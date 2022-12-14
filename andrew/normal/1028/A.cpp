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

char a[1001][1001];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)cin >> a[i][j];
    }
    ll kol = 0;
    for(int j = 1; j <= m; j++){
        ll sc = 1;
        for(int i = 2; i <= n; i++)if(a[i][j] == 'B' && a[i - 1][j] == 'B')sc++;
        kol = max(kol, sc);
    }
    kol /= 2;
    ll kol1 = 0;
    for(int i = 1; i <= n; i++){
        ll sc = 1;
        for(int j = 2; j <= m; j++)if(a[i][j] == 'B' && a[i][j - 1] == 'B')sc++;
        kol1 = max(kol1, sc);
    }
    kol1 /= 2;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)if(a[i][j] == 'B'){
        cout << i + kol << " " << j + kol1 << "\n";
        return 0;
    }
    return 0;
}