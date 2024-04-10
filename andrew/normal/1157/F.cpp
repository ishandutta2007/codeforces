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

ll b[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;

    vector <ll> a(n);

    ll ans = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[a[i]]++;
    }

    ll r = 1, sc = 0, uk = 0;

    for(int i = 1; i <= 2e5; i++){
        while(i >= r)sc += b[r], r++;
        if(b[i]){
            while(b[r] > 1)sc += b[r], r++;
            ll kol = sc;
            if(b[r] == 1){
                kol++;
            }
            if(ans < kol){
                ans = kol;
                uk = i;
            }
        }
        sc -= b[i];
    }

    vector <ll> d, c;
    while(b[uk]--)d.p_b(uk);
    uk++;
    while(b[uk] > 1){
        c.p_b(uk);
        b[uk]--;
        while(b[uk]--)d.p_b(uk);
        uk++;
    }

    if(b[uk])d.p_b(uk);

    reverse(all(c));

    for(auto i : c)d.p_b(i);

    cout << d.size() << "\n";

    for(auto i : d)cout << i << " ";
    cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}


/*
4 -1 3
*/