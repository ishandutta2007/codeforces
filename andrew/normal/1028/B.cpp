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

ll s[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    string s, s1;
    for(int i = 1; i <= 1000; i++)s += "5";
    for(int i = 1; i < 1000; i++)s1 += "4";
    s1 += "5";
    cout << s << endl << s1 << endl;
    return 0;
}