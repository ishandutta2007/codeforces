#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pdd pair<ld,ld>
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, _t = 0;
    cin >> n >> a;
    map <string, int> m1;
    vector <int> value[N];
    int v[n];
    vector <int> d1, d2;
    string s[n];
    fop (i,0,n) {
        cin >> s[i] >> v[i];
        if (!m1.count(s[i])) m1[s[i]] = _t++;
        value[m1[s[i]]].pb(v[i]);
    }
    fop (i,0,_t) sort(all(value[i]));
    int ans = 0;
    for (auto A : m1) {
        string ss = A.X;
        string t = ss;
        reverse(all(t));
        if (m1.count(t)) {
            if (ss != t) {
                int a = m1[ss], b = m1[t];
                while (value[a].size() && value[b].size()) {
                    int al = value[a].back() + value[b].back();
                    if (al > 0) {
                        ans += al;
                        value[a].pop_back();
                        value[b].pop_back();
                    } else {
                        break;
                    }
                }
            } else {
                int a = m1[ss];
                while (value[a].size() > 1) {
                    int tmp = value[a].back();
                    value[a].pop_back();
                    int tmp2 = value[a].back();
                    if (tmp2 > 0) {
                        value[a].pop_back();
                        ans += tmp + tmp2;
                    } else {
                        value[a].pb(tmp);
                        break;
                    }
                }
                if (value[a].size() > 1) {
                    d2.pb(value[a].back() + value[a][value[a].size() - 2]);
                    if (d2.back() < 0) d2.back() = 0;
                    d1.pb(value[a].back());
                } else if (value[a].size()) {
                    d2.pb(0);
                    d1.pb(value[a].back());
                }
            }
        }
    }
    int tmp = 0, nn = d1.size(), al = accumulate(all(d2), 0);
    fop (i,0,nn) {
        tmp = max(tmp, al - d2[i] + d1[i]);
    }
    cout << ans + tmp << endl;
}