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

const ll MOD = 1e9 + 7;
ll a[1001][1001], b[1001][1001], c[1001][1001];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)cin >> a[i][j];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ll kol = 0;
            for(int i1 = 1; i1 <= m; i1++)kol += a[i][i1];
            for(int i1 = 1; i1 <= n; i1++)kol += a[i1][j];
            if(kol == n + m)b[i][j] = 1;
        }
    }

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
            ll val = 0;
            for(int i1 = 1; i1 <= m; i1++)val |= b[i][i1];
            for(int i1 = 1; i1 <= n; i1++)val |= b[i1][j];
            if(val != a[i][j])vout("NO");
    }

    cout << "YES\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)cout << b[i][j] << " ";
        cout << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}