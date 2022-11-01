//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using vi = vector<int>;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second
#define int ll

const int maxn = 5e5;
const int mod = 1e9 + 7;
const int inf = 1e9;
const ll inf64 = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-6;

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int t; cin >> t;
    while(t--) {
        int n; string s;
        cin >> n >> s;
        bool ok = true;
        for(int i = 0; i < n / 2; i++) {
            int d = abs(s[i] - s[n - 1 - i]);
            ok &= (d % 2 == 0 && d <= 2);
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}