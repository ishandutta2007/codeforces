#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 200200;

struct Rational {
  ll p, q;
  Rational(ll p, ll q):
    p(p), 
    q(q) { }

  Rational():
    p(0),
    q(1) { } 

  Rational operator - (const Rational &to) const {
    return Rational(p * to.q - to.p * q, q * to.q);
  }

  bool operator < (const Rational &to) const {
    return p * to.q < to.p * q;
  }
};

int n = 1e5;
ll a[M];
ll sum[M];

struct Ans {
  int c;
  int mid;
  int k;

  Ans(int c, int mid, int k) :
    c(c),
    mid(mid),
    k(k) {
      //debug();
      assert(mid + c <= n);
      assert(n - k >= mid + c);
      assert(mid >= k);
    }

  void debug() {
    cerr << "c = " << c << " mid = " << mid << " k = " << k << endl;
  }

  Rational val() {
    ll p = a[mid] + (c == 1 ? 0 : a[mid + 1]);
    Rational med(p, c);

    ll summ = p + sum[n] - sum[n - k] + sum[mid] - sum[mid - k];
    Rational mean(summ, c + 2 * k);
    return mean - med;
  }

  void print() {
    int sz = 2 * k + c;
    //debug();
    cout << sz << endl;
    vector<ll> ans;
    for (int i = mid - k; i < mid + c; ++i)
      ans.push_back(a[i]);
    for (int i = n - 1; i >= n - k; --i)
      ans.push_back(a[i]);
    sort(ans.begin(), ans.end());
    for (int x : ans)
      cout << x << " ";
    cout << endl;
  }

} best(1, 0, 0);


void relax(Ans a) {
  if (best.val() < a.val())
    best = a;
}


void read() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a, a + n);
}

void pre() {
  sum[0] = 0;
  for (int i = 1; i <= n; ++i)
    sum[i] = a[i - 1] + sum[i - 1];
}

void kill() {
  for (int mid = 0; mid < n; ++mid)
    for (int c = 1; c <= 2 && mid + c <= n; ++c) {
      int l = 0, r = min(n - mid - c, mid) + 1;
      while (l + 1 < r) {
        int m1 = (2 * l + r) / 3;
        int m2 = (l + 2 * r) / 3;
        auto v1 = Ans(c, mid, m1).val();
        auto v2 = Ans(c, mid, m2).val();
        if (v1 < v2)
          l = m1 + 1;
        else
          r = m2;
      }
      relax(Ans(c, mid, l));
    }

  best.print();
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  pre();
  kill();
}