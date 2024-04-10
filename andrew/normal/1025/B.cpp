#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

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

set <ll> old, _new;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    ll a, b;
    cin >> a >> b;

    while(a != 1){
        ll j;
        bool fl = 0;
        for(j = 2; j * j <= a; j++)if(a % j == 0){
            fl = 1;
            break;
        }
        if(!fl){
            old.insert(a);
            break;
        }
        old.insert(j);
        while(a % j == 0)a /= j;
    }

    while(b != 1){
        ll j;
        bool fl = 0;
        for(j = 2; j * j <= b; j++)if(b % j == 0){
            fl = 1;
            break;
        }
        if(!fl){
            old.insert(b);
            break;
        }
        old.insert(j);
        while(b % j == 0)b /= j;
    }

    old.erase(1ll);
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        for(auto j : old)if(__gcd(a, j) > 1)_new.insert(j);
        for(auto j : old)if(__gcd(b, j) > 1)_new.insert(j);

        old = _new;
        _new.clear();
    }

    if(old.empty())vout(-1);
    cout << *(old.begin()) << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}