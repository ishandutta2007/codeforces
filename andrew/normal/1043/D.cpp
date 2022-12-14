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

ll a[14][200101];

ll p[14][200101], n, m;
ll pref[14][200101];
ll pos[20][MAXN];
ll last[MAXN];

ll get(ll xe, ll l, ll r){
    return pref[xe][r] - pref[xe][l - 1];
}

bool check(ll l, ll r){
    for(int i = 1; i <= m; i++){
        ll le = pos[i][a[1][l]], ri = min(n, le + (r - l + 1) - 1);
        ll x = get(i, le + 1, ri);
        if(x != r - l)return 0;
    }
    return 1;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)cin >> a[i][j];

    for(int i = 1; i <= n; i++){
        last[a[1][i]] = a[1][i - 1];
    }

    for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++){
        pos[i][a[i][j]] = j;
        pref[i][j] = pref[i][j - 1];
        if(last[a[i][j]] == a[i][j - 1])pref[i][j]++;
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll l = i, r = n;
        while(l < r){
            ll c = (l + r) >> 1;
            if(c == l)c++;
            if(check(i, c))l = c; else r = c - 1;
        }
        ans += l - i + 1;
    }
    cout << ans << "\n";
    return 0;
}