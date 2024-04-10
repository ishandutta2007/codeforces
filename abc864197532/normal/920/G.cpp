#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 1000001, logN = 17;

int lp[N], mu[N];
vector <int> f[N];

void build() {
    lp[1] = 1;
    for (int i = 2; i < N; ++i) if (!lp[i]) {
        for (int j = i; j < N; j += i) if (!lp[j]) {
            lp[j] = i;
        }
    }
    mu[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (lp[i] == lp[i / lp[i]]) mu[i] = 0;
        else mu[i] = mu[i / lp[i]] * -1;
    }
    for (int i = 1; i < N; ++i) if (mu[i]) {
        for (int j = i; j < N; j += i) {
            f[j].pb(i);
        }
    }
}

int get(int n, int p) {
    // count how many number x <= n and gcd(p, x) = 1
    int ans = 0;
    for (int i : f[p]) {
        ans += (n / i) * mu[i];
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    build();
    int t;
    cin >> t;
    while (t--) {
        int x, p, k;
        cin >> x >> p >> k;
        int re = get(x, p);
        int l = x, r = N * 7;
        while (r - l > 1) {
            int m = l + r >> 1;
            if (re + k <= get(m, p)) r = m;
            else l = m;
        }
        cout << r << endl;
    }
}