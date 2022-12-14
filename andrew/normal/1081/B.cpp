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

vector <ll> v[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;
    vector <ll> a(n), ans(n);

    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        a[i] = n - x;
        v[a[i]].p_b(i);
    }

    ll stn = 0;

    for(int i = 1; i <= n; i++)if(!v[i].empty()){
        ll kol = v[i].size();
        if(kol % i)vout("Impossible");

        for(int j = 0; j < kol; j++){
            if(j % i == 0)stn++;
            ans[v[i][j]] = stn;
        }

    }

    cout << "Possible\n";

    for(auto i : ans)cout << i << " ";
    cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}