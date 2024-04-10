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

ll pref[MAXN][3];

ll get(ll v, ll l , ll r){
    return pref[r][v] - pref[l - 1][v];
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;
    vector <ll> a(n + 1), b(n + 1);
    ll a1 = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pref[i][1] = pref[i - 1][1];
        pref[i][2] = pref[i - 1][2];
        pref[i][a[i]]++;
        if(a[i] == 2)a1++;
    }
    ll sc = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 1)sc++; else a1--;
        ans = max(ans, sc + a1);
    }
    for(int r = n; r > 0; r--){
        ll a1 = get(2, r, n), a2 = 0, kol = get(1, 1, r);
        ll sc = kol;
        for(int l = r; l > 0; l--){
            if(a[l] == 2)sc++;else a2++, kol--, sc--;
            sc = max(sc, a2 + a1 + kol);
            ans = max(ans, sc);
        }
    }
    return cout << ans << "\n", 0;
}