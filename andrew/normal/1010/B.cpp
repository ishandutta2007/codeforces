#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()

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

ll p[MAXN], n, m;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        cout << m << endl;
        ll x;
        cin >> x;
        if(x == -1)p[i] = 1;
    }
    ll l = 1, r = m;
    int i = 0;
    while(l < r){
        ll c = (l + r) >> 1;
        cout << c << endl;
        ll x;
        cin >> x;
        if(p[i] == 0)x *= -1;
        if(!x)vout(x);
        if(x == -1)r = c - 1;
        else l = c + 1;
        i = (i + 1) % n;
    }
    vout(l);
    return 0;
}