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



int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, k, sc = 0;
    cin >> n >> k;
    vector <ll> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sc += a[i];
    }

    if(sc % k)vout("No");
    vector <ll> vb;
    sc /= k;
    ll su = 0;
    ll kol = 0;
    for(int i = 1; i <= n; i++){
        su += a[i];
        kol++;
        if(su > sc)vout("No");
        if(su == sc){
            vb.p_b(kol);
            su = 0;
            kol = 0;
        }
    }

    if(vb.size() != k)vout("No");
    cout << "Yes\n";
    for(auto i : vb)cout << i << " ";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}