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
#define ple pair<pll, ll>

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;


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
    //freopen("mooyomooyo.in","r",stdin);
    //freopen("mooyomooyo.out","w",stdout);
    ll n;
    cin >> n;

    map <pair <string, ll>, vector <ll> > mp;

    for(int i = 1; i <= n; i++){
        string a, b;
        cin >> a >> b;
        ll musk = 0;

        for(auto j : b)musk |= 1ll << (j - 'a' + 1);

        while(!a.empty() && ((1ll << a[a.size() - 1] - 'a' + 1) & musk))a.erase(a.size() - 1);

        mp[{a, musk}].p_b(i);
    }

    cout << mp.size() << "\n";

    for(auto i : mp){
        cout << i.se.size();
        for(auto &j : i.se)cout << " " << j;
        cout << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}