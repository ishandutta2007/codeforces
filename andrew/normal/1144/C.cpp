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
    vector <ll> cd(n + 1);
    for(int i = 1; i <= n; i++)cin >> cd[i];

    vector <ll> a, b;

    map <ll, ll> mp;

    for(int i = 1; i <= n; i++)mp[cd[i]]++;

    for(auto i : mp){
        if(i.se > 2)vout("NO");
        if(i.se == 1)a.p_b(i.fi); else{
            a.p_b(i.fi);
            b.p_b(i.fi);
        }
    }

    sort(all(a));
    sort(all(b));
    reverse(all(b));
    cout << "YES\n";
    cout << a.size() << "\n";
    for(auto i : a)cout << i << " ";cout << "\n";
    cout << b.size() << "\n";
    for(auto i : b)cout << i << " ";cout << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}