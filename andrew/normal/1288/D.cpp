#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 2e9;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

pii Mx[MAXN];
int mn;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    int n, m;
    cin >> n >> m;

    vector <vector <int>> a(n);

    pair <int, pii> ans = {-inf, {0, 0}};

    for(int i = 0; i < n; i++){
        a[i].resize(m);
        for(auto &j : a[i])cin >> j;
        for(int musk = 0; musk < pw(m); musk++){
            mn = inf;
            for(int j = 0; j < m; j++)if((musk & pw(j))){
                mn = min(mn, a[i][j]);
            }
            Mx[musk] = max(Mx[musk], {mn, i});
        }
        for(int musk = 0; musk < pw(m); musk++){
            mn = inf;
            for(int j = 0; j < m; j++)if((musk & pw(j))){
                mn = min(mn, a[i][j]);
            }
            ans = max(ans, {min(mn, Mx[(pw(m) - 1) ^ musk].fi), {i, Mx[(pw(m) - 1) ^ musk].se}});
        }
    }

    cout << ans.se.fi + 1 << "\n" << ans.se.se + 1 << "\n";

    return 0;
}