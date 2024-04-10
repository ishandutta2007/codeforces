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
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> g[MAXN], g1[MAXN];

int Max;

bool f[MAXN], f1[MAXN];

vector <ll> order;

void dfs(ll x){
    if(f[x])return;
    f[x] = 1;
    for(auto to : g[x])dfs(to);
    Max = x;
}

void dfs1(ll x){
    if(f1[x])return;
    f1[x] = 1;
    for(auto to : g1[x])dfs1(to);
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            g[i].clear(), g1[i].clear();
            f[i] = f1[i] = 0;
        }
        int m;
        cin >> m;
        while(m--){
            int a, b;
            cin >> a >> b;
            g[a].p_b(b);
            g1[b].p_b(a);
        }
        for(int i = 1; i <= n; i++)dfs(i);
        dfs1(Max);
        if(*min_element(f1 + 1, f1 + n + 1) == 0){
            vector <int> res_cats, res_people;
            for(int i = 1; i <= n; i++)if(f1[i])res_cats.p_b(i);else res_people.p_b(i);
            cout << "Yes\n";
            cout << sz(res_people) << " " << sz(res_cats) << "\n";
            for(auto i : res_people)cout << i << " "; cout << "\n";
            for(auto i : res_cats)cout << i << " "; cout << "\n";
        }else cout << "No\n";
    }


    return 0;
}