#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()


#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef double ld;
typedef long long ll;

const int LG = 19;
typedef complex<ld> base;

vector<base> ang[LG + 5];

void init_fft() {
    int n = 1 << LG;
    ld e = acosl(-1) * 2 / n;
    ang[LG].resize(n);
    forn(i, n)
        ang[LG][i] = polar(ld(1), e * i);

    for (int k = LG - 1; k >= 0; --k) {
        ang[k].resize(1 << k);
        forn(i, 1 << k)
            ang[k][i] = ang[k + 1][i * 2];
    }
}

void fft_rec(base *a, int lg, bool inv) {
    if (lg == 0)
        return;
    int hlen = 1 << (lg - 1);
    fft_rec(a, lg-1, inv);
    fft_rec(a + hlen, lg-1, inv);

    forn (i, hlen) {
        base w = ang[lg][i];
        if (inv)
            w = conj(w);
        base u = a[i];
        base v = a[i + hlen] * w;
        a[i] = u + v;
        a[i + hlen] = u - v;
    }
}

void fft(base *a, int lg, bool inv) {
    int n = 1 << lg;
    int j = 0, bit;
    for (int i = 1; i < n; ++i) {
        for (bit = n >> 1; bit & j; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    fft_rec(a, lg, inv);
    if (inv) {
        forn(i, n)
            a[i] /= n;
    }
}

const int N = 1 << LG;
const int T = 200200;
const int R = 60;
const int M = 2 * T + 10;

int n, x;
int a[M];
int b[M];
base A[3][N], B[N];
ll cnt[M];
ll ans[M];

void read() {
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
}

void kill() {
  a[0] = 0;
  for (int i = 0; i < n; ++i)
    a[i + 1] = a[i] + (b[i] < x ? 1 : 0);

  for (int i = 0; i <= n; ++i) {
    cnt[a[i]]++;
  }

  for (int i = 0; i < T; ++i) {
    ans[0] += cnt[i] * (cnt[i] - 1) / 2;
    //if (cnt[i])
      //cerr << cnt[i] << "!\n";
  }

  for (int i = 0; i < T; ++i) {
    B[T - i] = cnt[i];
    for (int j = 0; j < 3; ++j) {
      A[j][i] = cnt[i] % R;
      cnt[i] /= R;
    }
    assert(cnt[i] == 0);
  }

  for (int j = 0; j < 3; ++j)
    fft(A[j], LG, 0);
  fft(B, LG, 0);
  for (int j = 0; j < 3; ++j)
    for (int i = 0; i < N; ++i) {
      A[j][i] *= B[i];
    }

  for (int j = 0; j < 3; ++j)
    fft(A[j], LG, 1);

  for (int i = 1; i < T; ++i) {
    for (int j = 2; j >= 0; --j) {
      ans[i] *= R;
      ans[i] += round(A[j][i + T].real());
    }
  }

  {
    ll sum = 0;
    for (int i = 0; i <= n; ++i)
      sum += ans[i];
    assert(sum == 1ll * n * (n + 1) / 2);
  }

  for (int i = 0; i <= n; ++i)
    cout << ans[i] << " ";
  cout << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  init_fft();

  assert(M < N);

  read();
  kill();
}