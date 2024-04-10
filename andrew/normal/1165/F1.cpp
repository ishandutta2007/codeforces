#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll kol[MAXN], last[MAXN];
vector <ll> v[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;

    vector <ll> k(n + 1);
    for(int i = 1; i <= n; i++)cin >> k[i];

    ll l = 1, r = 3000;

    while(m--){
        ll d, t;
        cin >> d >> t;
        v[t].p_b(d);
    }

    while(l < r){
        ll c = (l + r) >> 1;
        for(int i = 1; i <= c; i++)kol[i] = 0;
        ll ost = 0, sc = 0;
        for(int i = 1; i <= n; i++){
            last[i] = 0;
            for(auto j : v[i])if(j <= c)last[i] = max(last[i], j);
            if(!last[i]){
                ost += k[i];
            }else kol[last[i]] += k[i];
        }

        for(int i = 1; i <= c; i++){
            sc++;
            ll c = min(kol[i], sc);
            kol[i] -= c;
            sc -= c;
            ost += kol[i];
        }
        if(sc < ost * 2)l = c + 1; else r = c;

    }

    cout << l << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}