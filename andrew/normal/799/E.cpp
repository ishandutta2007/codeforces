#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


#define fi first
#define se second
#define p_b push_back
#define pll pair <ll, ll>
#define pii pair <int, int>
#define m_p make_pair
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define ifn(x) if(!(x))
#define fout(x) {cout << x << "\n"; return;}


using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 3123456;
const ll N = 2e5;
const ll inf = 3e18;
const ll buben = 338;
const ll mod = 1e9 + 7;
const ll step = 200003;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s) {cout << s << endl; exit(0);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, m, k;

    cin >> n >> m >> k;

    vector <ll> a(n + 1);

    vector <ll> musk(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int s = 0; s < 2; s++){
        ll x;
        cin >> x;
        for(int i = 0; i < x; i++){
            ll v;
            cin >> v;
            musk[v] |= pw(s);
        }
    }

    vector < vector <ll> > w(4);

    for(int i = 1; i <= n; i++){
        w[musk[i]].p_b(i);
    }

    if(sz(w[3]) + min(sz(w[1]), sz(w[2])) < k || k > m || 2 * k - sz(w[3]) > m){
        vout(-1);
    }

    ll ans = inf;

    

    set <pll> st[4], del[4];

    vector <ll> sum(4);

    for(int i = 0; i < 4; i++){
        for(auto j : w[i]){
            st[i].insert({a[j], j});
            sum[i] += a[j];
        }
    }

    while(sz(st[3]) > m){
        pll xe = *--st[3].end();
        st[3].erase(--st[3].end());
        del[0].insert(xe);
        sum[3] -= xe.fi;
    }

    for(int cnt_common = sz(st[3]); cnt_common > -1; --cnt_common){
        int len = cnt_common, need = max(k - cnt_common, 0LL);
        bool good = 1;

        while(sz(st[1]) > need){
            pll xe = *--st[1].end();
            st[1].erase(xe);
            sum[1] -= xe.fi;
            sum[0] += xe.fi;
            del[1].insert(xe);
            st[0].insert(xe);
        }

        while(sz(st[2]) > need){
            pll xe = *--st[2].end();
            st[2].erase(xe);
            sum[2] -= xe.fi;
            sum[0] += xe.fi;
            del[2].insert(xe);
            st[0].insert(xe);
        }

        len += 2 * need;
        while(sz(st[1]) < need){
            if(sz(del[1])){
                pll xe = *del[1].begin();
                del[1].erase(xe);
                if(st[0].find(xe) != st[0].end()){
                    sum[0] -= xe.fi;
                }
                st[0].erase(xe);
                del[0].erase(xe);
                st[1].insert(xe);
                sum[1] += xe.fi;
            }else{
                good = 0;
                break;
            }
        }

        while(sz(st[2]) < need){
            if(sz(del[2])){
                pll xe = *del[2].begin();
                del[2].erase(xe);
                if(st[0].find(xe) != st[0].end()){
                    sum[0] -= xe.fi;
                }
                st[0].erase(xe);
                del[0].erase(xe);
                st[2].insert(xe);
                sum[2] += xe.fi;
            }else{
                good = 0;
                break;
            }
        }

        if(len <= m){
            need = m - len;

            while(sz(st[0]) > need){
                pll xe = *--st[0].end();
                st[0].erase(xe);
                sum[0] -= xe.fi;
                del[0].insert(xe);
            }

            while(sz(st[0]) < need){
                if(sz(del[0])){
                    pll xe = *del[0].begin();
                    del[0].erase(xe);
                    st[0].insert(xe);
                    sum[0] += xe.fi;
                }else{
                    good = 0;
                    break;
                }
            }

            if(good)ans = min(ans, sum[0] + sum[1] + sum[2] + sum[3]);

        }

        if(!cnt_common)break;

        pll xe = *--st[3].end();

        sum[3] -= xe.fi;
        st[3].erase(xe);
        del[0].insert(xe);
    }

    cout << ans << "\n";

    return 0;
}