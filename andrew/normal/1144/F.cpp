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

vector <ll> ve[MAXN];

vector <pll> v;

bool fl[MAXN];
ll ans[MAXN];

vector <ll> d[MAXN];

queue <ll> q;

ll deep[MAXN];

bool fe[MAXN];
ll t[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;

    v.resize(m);

    for(int i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        d[a].p_b(i);
        d[b].p_b(i);
        v[i] = {a, b};
    }

    q.push(1);

    while(!q.empty()){
        ll x = q.front();
        q.pop();
        for(auto to : d[x]){
            ll kek = 0;
            ll f = 0;
            if(v[to].fi == x){
                kek = v[to].se;
            }else{
                kek = v[to].fi;
                f = 1;
            }

            ll nz = deep[x] ^ 1;
            nz ^= f;
            if(fl[to]){
                if(ans[to] != nz)vout("NO");
                continue;
            }

            if(!fl[to]){
                fl[to] = 1;
                ans[to] = nz;
                if(fe[kek]){
                    if(t[kek] != deep[x] ^ 1)vout("NO");
                    continue;
                }
                fe[kek] = 1;
                t[kek] = deep[x] ^ 1;
                deep[kek] = deep[x] ^ 1;
                q.push(kek);
            }

        }

    }

    cout << "YES\n";

    for(int i = 0; i < m; i++)cout << ans[i];
    cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}