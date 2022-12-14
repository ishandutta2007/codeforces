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


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, p;
    cin >> n >> p;
    ll mx = 0, mxj = n;
    ll kek = 10;
    for(int i = 1; i < 18; i++, kek *= 10){
        ll nine = kek - 1;
        if(nine > n)break;
        ll xe = n / kek, ost = n % kek;
        if(ost != nine)xe--;
        xe *= kek;
        xe += nine;
        ll r = n - xe;
        if(r <= p){
            mx = i;
            mxj = xe;
        }
    }
    cout << mxj << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}