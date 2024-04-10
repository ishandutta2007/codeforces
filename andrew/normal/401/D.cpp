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

ll dp[263000][100];


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string a;
    ll m;
    cin >> a >> m;
    ll n = a.size();
    dp[0][0] = 1;
    ll k = 1;
    sort(all(a));
    for(int i = 1; i < n; i++)k *= 10;

    vector <ll> b(n);
    for(int i = 0; i < n; i++)b[i] = a[i] - '0';

    ll musk = 1ll << n;
    int i, j, i1;
    for(i = 0; i < musk; i++){
        k = 1;
        for(j = 0; j < n; j++)if(!((1ll << j) & i))k *= 10;
        k /= 10;
        for(j = 0; j < m; j++)if(dp[i][j]){
            ll first = 0;
            if(!i && !b[0])first = 1;

            for(i1 = first; i1 < n; i1++)if(((1ll << i1) & i) == 0){
                if(i1 && b[i1] == b[i1 - 1] && (i&(1ll << i1 - 1)) == 0)continue;
                ll sm = (j + k * b[i1]) % m;
                dp[i | (1ll << i1)][sm] += dp[i][j];
            }
        }
    }
    cout << dp[musk - 1][0] << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}