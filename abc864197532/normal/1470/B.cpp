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
const int mod = 1e9 + 7, abc = 864197532, N = 1000087, logN = 17, K = 3e6;

int lp[N];

void build() {
    vector <int> p;
    for (int i = 2; i < N; ++i) {
        if (!lp[i]) {
            p.push_back(i);
            lp[i] = i;
        }
        for (int j = 0; 1ll * p[j] * i < N; ++j) {
            lp[p[j] * i] = p[j];
            if (i % p[j] == 0) break;
        }
    }
}

void solve() {
    int n, q;
    lli x;
    cin >> n;
    vector <int> a(n);
    vector <vector <int>> cur(n);
    map <vector <int>, int> m1;
    vector <vector <int>> cc;
    int _t = 0;
    vector <int> adj[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int tmp = a[i];
        while (tmp != 1) {
            int j = lp[tmp], cnt = 0;
            while (tmp % j == 0) tmp /= j, cnt++;
            if (cnt & 1) cur[i].pb(j);
        }
        if (!m1.count(cur[i])) {
            m1[cur[i]] = _t++;
            cc.pb({});
        }
        cc[m1[cur[i]]].pb(i);
    }
    int cnt0 = 0, cnt1odd = 0, cnt1even = 0;
    for (int i = 0; i < _t; ++i) {
        int N = cc[i].size();
        if (cur[cc[i][0]].empty()) {
            cnt1even += N;
        } else {
            if (N & 1) cnt1odd = max(cnt1odd, N);
            else cnt1even += N;
        }
        cnt0 = max(cnt0, N);
    }
    cin >> q;
    while (q--) {
        cin >> x;
        if (x == 0) cout << cnt0 << '\n';
        else cout << max(cnt1odd, cnt1even) << '\n';
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    build();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}