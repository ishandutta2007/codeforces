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

    string s;
    cin >> s;

    ll k = n - 11;
    ll kol = 0, kolc = 0;

    vector <bool> f(n);

    ll uk = 0, uk1 = 0;
    set <ll> mult, t;

    for(int i = 0; i < n; i++)if(s[i] == '8'){
        mult.insert(i);
        kol++;
    }else{
        t.insert(i);
        kolc++;
    }

    for(int i = 1; i <= k; i++){
        if(i % 2){
            if(kolc){
                ll x = *t.begin();
                t.erase(x);
                f[x] = 1;
                kolc--;
            }else{
                ll x = *mult.begin();
                mult.erase(x);
                f[x] = 1;
                kol--;
            }
        }else{
            if(kol){
                ll x = *mult.begin();
                mult.erase(x);
                f[x] = 1;
                kol--;
            }else{
                ll x = *t.begin();
                t.erase(x);
                f[x] = 1;
                kolc--;
            }

        }
    }
    uk = 0;
    while(f[uk])uk++;
    if(s[uk] != '8')vout("NO");
    cout << "YES\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}