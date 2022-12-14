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
    ll n, m, l;
    cin >> n >> m >> l;
    vector <ll> a(n + 1);
    vector <ll> b(n + 1);

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] > l)b[i] = 1;
    }

    for(int i = 1; i <= n; i++)if(b[i] && !b[i - 1])ans++;

    while(m--){
        ll type, p, d;
        cin >> type;
        if(!type)cout << ans << "\n"; else{
            cin >> p >> d;
            a[p] += d;
            if(a[p] > l && !b[p]){
                b[p] = 1;
                ans++;
                if(p != n && b[p + 1])ans--;
                if(b[p - 1])ans--;
            }
        }
    }
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}