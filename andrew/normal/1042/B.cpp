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

ll a[3], b[3][3];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("joseph.in", "r", stdin);
    //freopen("joseph.out", "w", stdout);
    ll n;
    cin >> n;
    ll ans = 1e18;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            a[i] = b[i][j] = 1e18;
        }
    }
    for(int i = 0; i < n; i++){
        ll val;
        string s;
        cin >> val >> s;
        if(s.size() == 3){
            ans = min(ans, val);
            continue;
        }
        sort(all(s));
        for(int j = 0; j < s.size(); j++)a[s[j] - 'A'] = min(a[s[j] - 'A'], val);
        if(s.size() == 2)b[s[0] - 'A'][s[1] - 'A'] = min(val, b[s[0] - 'A'][s[1] - 'A']);
    }
    ans = min(ans, a[0] + a[1] + a[2]);
    ans = min(ans, a[0] + b[1][2]);
    ans = min(ans, a[1] + b[0][2]);
    ans = min(ans, a[2] + b[0][1]);
    if(ans == 1e18)vout(-1);
    vout(ans);
    return 0;
}