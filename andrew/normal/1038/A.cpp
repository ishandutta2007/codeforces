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

ll a[26];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n, m, ans = 0;;
    char cc;
    cin >> n >> m;
    ll mn = 1e18;
    while(n--){
        cin >> cc;
        a[cc - 'A']++;
    }
    for(int i = 0; i < m; i++)mn = min(mn, a[i]);
    ans += mn * m;
    for(int i = m + 1; i < 26; i++)ans += a[i];
    vout(ans);
    return 0;
}