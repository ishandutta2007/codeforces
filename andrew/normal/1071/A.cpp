#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
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

ll a, b;
bool check(ll x){
    ll l = a, r = b;
    vector <bool> fl(x + 1);
    for(int i = x; i > 0; i--)if(i <= l){
        l -= i;
        fl[i] = 1;
    }
    for(int i = 1; i <= x; i++)if(!fl[i] && i <= r){
        r -= i;
        fl[i] = 1;
    }
    for(int i = 1; i <= x; i++)if(!fl[i])return 0;
    return 1;
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> a >> b;
    ll l = 0, r = 5 * 1e5;
    while(l < r){
        ll c = (l + r) >> 1;
        if(c == l)c++;
        if(check(c))l = c; else r = c - 1;
    }

    set <ll> sa, sb;
    for(int i = l; i > 0; i--)if(i <= a){
        a -= i;
        sa.insert(i);
    }

    for(int i = 1; i <= l; i++)if(i <= b && sa.find(i) == sa.end()){
        b -= i;
        sb.insert(i);
    }

    cout << sa.size() << "\n";
    for(auto i : sa)cout << i << " "; cout << "\n";
    cout << sb.size() << "\n";
    for(auto i : sb)cout << i << " "; cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}