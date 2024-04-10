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

ll pref[MAXN];

string s;
bool fl[MAXN];
void kek(ll l, ll r){
    string ans = s.substr(l - 1, r - l + 1);
    vout(ans);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll r = k / 2;
    ll l = 1;
    if(k % 2 == 0)r--;
    r = min(r, n);
    ll ri = r;
    if(r < 1)vout(0);
    if(k - r > n)vout(0);
    while(l < r){
        ll c = (l + r) >> 1;
        if(k - c > n)l = c + 1; else r = c;
    }
    vout(ri - r + 1);
    return 0;
}