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

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, k, ans = 0;
    cin >> n >> k;
    vector <ll> f(n + 1), b(k + 1);

    for(int i = 1; i <= k; i++){
        cin >> b[i];
        if(!f[b[i]])f[b[i]] = i;
        v[b[i]].p_b(i);
    }

    for(int i = 1; i <= n; i++)v[i].p_b(1e18);

    for(int i = 1; i <= n; i++){
        for(int j = -1; j <= 1; j++)if(1 <= i + j && i + j <= n){
            if(i == i + j){
                if(!f[i])ans++;
            }else
            if(!f[i])ans++; else{
                ll val = *upper_bound(all(v[i + j]), f[i]);
                if(val == 1e18)ans++;

            }
        }
    }

    cout << ans << "\n";



    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}