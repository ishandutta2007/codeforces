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

map <pll, ll> mp;

vector <ll> v[MAXN];

bool f[MAXN];
ll k[MAXN], kol[MAXN];

void dfs(ll x, ll pr = 0){
    ll col = 1;
    ll xe = mp[{x, pr}];
    if(f[x]){
        for(auto to : v[x])if(to != pr){
            mp[{x, to}] = col;
            mp[{to, x}] = col;
            dfs(to, x);
        }
    }else{
        col = 0;
        for(auto to : v[x])if(to != pr){
            col++;
            if(col == xe)col++;
            mp[{x, to}] = col;
            mp[{to, x}] = col;
            dfs(to, x);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    ll n, Q;
    cin >> n >> Q;

    multiset <pll> s;

    vector <pll> arr(n);

    for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        arr[i] = {a, b};
        v[a].p_b(b);
        v[b].p_b(a);
    }

    for(int i = 1; i <= n; i++)s.insert({v[i].size(), i});
    for(int i = 1; i <= n; i++)kol[i] = v[i].size();

    while(!s.empty() && Q){
        Q--;
        pll xe = *--s.end();
        s.erase(--s.end());
        k[xe.se] = 1;
        f[xe.se] = 1;
        for(auto i : v[xe.se]){
            if(!f[i]){
                s.erase({kol[i], i});
                //kol[i]--;
                k[i]++;
                s.insert({kol[i], i});
            }
        }
    }

    ll ans = 0, x = 0;
    for(int i = 1; i <= n; i++){
        if(f[i]){
            ans = max(ans, 1ll);
            if(ans == 1)x = i;
        }
        else{
            ll sc = k[i];
            for(auto j : v[i])if(!f[j])sc++;
            ans = max(ans, sc);
            if(ans == sc)x = i;
        }
    }

    cout << ans << "\n";
    dfs(x);
    for(int i = 1; i < n; i++)cout << mp[arr[i]] << " ";
    cout << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}