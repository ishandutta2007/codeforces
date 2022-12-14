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
const ll MAXN = 1123456;
const ll N = 2e5 + 2;
const ll inf = 1e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s) {cout << s << endl; exit(0);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int cnt[MAXN];
vector <int> v[MAXN];

void solve(){
    int n;
    cin >> n;
    vector <int> a(2 * n);

    for(auto &i : a)cin >> i;

    for(int g = 2; g <= 1000; g++){
        vector <pii> res;
        for(int i = 0; i <= 1000; i++)v[i].clear();
        for(int i = 0; i < 2 * n; i++)v[a[i] % g].p_b(i);
        for(int i = 0; i < g; i++){
            while(sz(v[i])){
                int x = v[i].back(), s, t;
                v[i].pop_back();
                s = g - i;
                if(s == g)s = 0;
                if(v[s].empty())continue;
                t = v[s].back();
                v[s].pop_back();
                res.p_b({t + 1, x + 1});
            }
        }
        if(sz(res) >= n - 1){
            if(sz(res) == n)res.pop_back();
            for(auto i : res)cout << i.fi << " " << i.se << "\n";
            return;
        }
        res.clear();
    }
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    cin >> t;

    while(t--)solve();

    return 0;
}