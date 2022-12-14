#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
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

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    ll la, lb;
    la = lb = 0;
    if(s[0] == '0')la++; else lb++;
    for(int i = 1; i < n; i++){
        if(s[i] != s[i - 1]){
            if(s[i] == '0')la++; else lb++;
        }
    }
    ll ans = 1e18;
    ll sc = 0;
    if(!la)vout(0);
    if(!lb)vout(k);
    while(la > 0 && lb > 0){
        ans = min(ans, sc + min(la * k, lb * k + k));
        la--;
        lb--;
        if(!la && !lb)break;
        if(!la)la = 1;
        if(!lb)lb = 1;
        sc += m;
    }
    cout << ans << endl;
    return 0;
}