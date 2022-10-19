#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 200200;

int gcd(int x, int y) {
    while (y) {
        x %= y;
        swap(x, y);
    }
    return x;
}

int n, m;
bool u[M];
int b[M], to[M];
vector<int> ds;
vector<int> a[M];
int phi[M];

void pre() {
    for (int i = 1; i < M; ++i)
        phi[i] = i;
    for (int i = 1; i < M; ++i)
        for (int j = 2 * i; j < M; j += i)
            phi[j] -= phi[i];
}

int bin(int x, int to, int mod) {
    int y = 1;
    while (to) {
        if (to & 1)
            y = 1ll * x * y % mod;
        x = 1ll * x * x % mod;
        to >>= 1;
    }
    return y;
}

void read() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        u[x] = true;
    }
}

vector<int> rep(int i) {
    vector<int> ans;
    while (i != -1) {
        ans.insert(ans.end(), all(a[ds[i]]));
        i = to[i];
    }
    return ans;
}

int fun(int x, int y) {
    int g = gcd(x, m);
    assert(y % g == 0);
    int p = phi[m / g];
    int a = bin(x / g, p - 1, m / g);
    int b = 1ll * a * (y / g) % m;
    return b;
}

void kill() {
    for (int i = 0; i < m; ++i)
        if (!u[i])
            a[gcd(i, m)].push_back(i);

    for (int d = 1; d <= m; ++d)
        if (m % d == 0)
            ds.push_back(d);

    int k = ds.size();
    for (int i = k - 1; i >= 0; --i) {
        int d = ds[i];
        b[i] = 0;
        to[i] = -1;
        for (int j = i + 1; j < k; ++j)
            if (ds[j] % d == 0) {
                if (b[j] > b[i]) {
                    b[i] = b[j];
                    to[i] = j;
                }
            }
        b[i] += a[d].size();
    }

    int best = 0;
    for (int i = 0; i < k; ++i)
        if (b[i] > b[best])
            best = i;

    vector<int> a = rep(best);
    cout << a.size() << endl;
    cout << a[0] << " ";
    for (int i = 0; i + 1 < (int) a.size(); ++i)
        cout << fun(a[i], a[i + 1]) << " ";
    cout << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  pre();
  read();
  kill();

}