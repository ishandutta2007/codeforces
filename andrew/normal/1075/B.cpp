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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
T sqr(T x){
    return x * x;
}

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


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;
    ll k = n + m;
    vector <ll> a(k + 1);
    vector <bool> f(k + 1);
    for(int i = 1; i <= k; i++)cin >> a[i];
    for(int i = 1; i <= k; i++){
        bool x;
        cin >> x;
        f[i] = x;
    }
    ll pos = 0;
    vector <ll> b(k + 1);
    vector <ll> c(k + 1);
    vector <ll> res(k + 1);
    for(int i = 1; i <= k; i++)b[i] = 1e18;
    for(int i = 1; i <= k; i++){
        if(f[i]){
            pos = i;
        }else{
            if(pos){
                c[i] = pos;
                b[i] = a[i] - a[pos];
            }
        }
    }

    pos = 0;

    for(int i = k; i > 0; i--){
        if(f[i]){
            pos = i;
        }else{
            if(pos){
                if(a[pos] - a[i] < b[i]){
                    c[i] = pos;
                }
            }
        }
    }

    for(int i = 1; i <= k; i++)res[c[i]]++;
    vector <ll> ans;
    for(int i = 1; i <= k; i++)if(f[i])ans.p_b(res[i]);
    for(auto i : ans)cout << i << " ";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}