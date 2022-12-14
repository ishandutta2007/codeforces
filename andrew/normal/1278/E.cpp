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
const ll N = 1e5;
const ll inf = 3e18;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> arr;

vector <ll> v[MAXN];

void dfs(ll x, ll pr){
    for(auto to : v[x])if(to != pr)arr.p_b(to);
    arr.p_b(x);
    reverse(all(v[x]));
    for(auto to : v[x])if(to != pr)dfs(to, x);
}

ll ft[MAXN], sd[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n;
    cin >> n;

    for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    arr.p_b(1);

    dfs(1, 0);

    for(int i = 0; i < 2 * n; i++){
        if(!ft[arr[i]]){
            ft[arr[i]] = i + 1;
        }else sd[arr[i]] = i + 1;
    }

    for(int i = 1; i <= n; i++)cout << ft[i] << " " << sd[i] << "\n";

    return 0;
}