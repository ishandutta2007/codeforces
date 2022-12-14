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


    string a;
    cin >> a;

    ll n = a.size();

    ll nn = min(5ll, ll(a.size()));

    for(int i = 1; i <= nn; i++){
        ll stol = 0;
        for(int j = 1; j <= 20; j++)if(j * i >= a.size()){
            stol = j;
            break;
        }

        if(!stol)continue;

        vector <ll> c;

        ll x = stol * i - a.size();

        ll val = x / i;
        ll kol = x % i;
        if(kol > i)continue;

        cout << i << " " << stol << "\n";

        ll uk = -1;

        for(int j = 1; j <= i; j++){
            ll arr = val + (j <= x);
            for(int i1 = arr + 1; i1 <= stol; i1++){
                uk++;
                cout << a[uk];
            }
            while(arr--)cout << "*";
            cout << "\n";
        }
        return 0;

    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
/*
9
4 4 4 4 2 1 2 2 11
*/