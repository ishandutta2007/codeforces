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

ll kol[MAXN], b[MAXN];

vector <ll> v[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, q;
    cin >> q >> n;

    vector <pll> a(n);

    for(int i = 0; i < n; i++)cin >> a[i].fi >> a[i].se;

    ll sc = 0;

    ll ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = a[i].fi; j <= a[i].se; j++){
            if(v[j].size() < 2)v[j].p_b(i);
            kol[j]++;
        }
    }

    for(int i = 1; i <= q; i++)if(kol[i])sc++;

    for(int i = 0; i < n; i++){
        ll res = sc;

        for(int j = a[i].fi; j <= a[i].se; j++){
            if(kol[j] == 1)res--;
            if(kol[j] == 2){
                for(auto i1 : v[j])if(i1 != i)b[i1]++;
            }
        }

        for(int j = 1; j <= q; j++)if(!(a[i].fi <= j && j <= a[i].se)){
            if(kol[j] == 1)b[v[j][0]]++;
        }

        for(int j = 0; j < n; j++)if(i != j){
            ll k = res - b[j];
            ans = max(ans, k);
            b[j] = 0;
        }else b[j] = 0;

    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}