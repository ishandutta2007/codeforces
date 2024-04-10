#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set
#define sqr(x) (x)*(x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

vector <ll> v[MAXN];

ll val[MAXN], pr[MAXN], tin[MAXN], tout[MAXN], stn;

bool fl[MAXN];

set <ll> s;

ll n, k;

ll T[MAXN];

const ll N = 1e6 + 2;

void u(ll pos, ll val){
    for(int i = pos; i <= N; i += i & -i)T[i] += val;
}

void up(ll l, ll r, ll val){
    u(l, val);
    u(r + 1, -val);
}

ll f(ll x){
    ll res = 0;
    for(int i = x; i > 0; i -= i & -i)res += T[i];
    return res;
}

void dfs(ll x, ll deep, ll p){
    tin[x] = ++stn;
    up(tin[x], tin[x], deep);
    pr[x] = p;
    for(auto to : v[x])if(to != p)dfs(to, deep + 1, x);
    tout[x] = stn;
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> k;
    k = n - k;
    for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    set <ll> ans;

    for(int i = 1; i <= n; i++)ans.insert(i);

    dfs(n, 1ll, 0ll);

    for(int i = n; i >= 1; i--){

        if(f(tin[i]) <= k){
            ll x = i;
            ans.erase(i);
            while(x){
                if(fl[x])break;
                k--;
                fl[x] = 1;
                up(tin[x], tout[x], -1);
                x = pr[x];
            }
        }

    }

    for(auto i : ans)cout << i << " ";
    cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}