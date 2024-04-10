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

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;
    vector <ll> pref(n + 1);

    ll mn = 1e18, mx = -1e18;

    for(int i = 2; i <= n; i++){
        cin >> pref[i];
        pref[i] += pref[i - 1];
        mn = min(mn, pref[i]);
        mx = max(mx, pref[i]);
    }


    for(int i = 1; i <= n; i++){
        if(i + mn < 1 || i + mx > n)continue;
        vector <ll> a(n + 1);
        a[1] = i;
        for(int i = 2; i <= n; i++)a[i] = a[1] + pref[i];
        set <ll> s;
        for(int i = 1; i <= n; i++)s.insert(a[i]);
        if(s.size() != n)vout(-1);
        for(int i = 1; i <= n; i++)cout << a[i] << " ";
        cout << "\n";
        return 0;
    }
    vout(-1);
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}