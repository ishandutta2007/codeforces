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
        int n; cin >> n;
        map<int, int> cnt;
        vi a(n);
        for(int i = 0; i < n; i++) {
            int x; cin >> x; cnt[x]++; a[i] = x;
        }
        for(int i = 0; i < n; i++) if(cnt[a[i]] == 1) cnt.erase(a[i]);
        bool done = false;
        int p = 1, q = 0;
        for(auto it = cnt.begin(); it != cnt.end(); it++) {
            if(it->y >= 4) {
                for(int i = 0; i < 4; i++) cout << it->x << ' ';
                cout << '\n';
                done = true;
                break;
            }
            auto nxt = it;
            nxt++;
            if(nxt != cnt.end() && 1LL * nxt->x * q < 1LL * it->x * p) {
                p = nxt->x;
                q = it->x;
            }
        }
        if(!done) {
            cout << p << ' ' << p << ' ' << q << ' ' << q << '\n';
        }
    }
}