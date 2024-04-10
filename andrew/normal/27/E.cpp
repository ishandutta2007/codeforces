#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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

const ll N = 1e6;

ll dp[1001][1021];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector <bool> f(N + 1);

    vector <ll> a;



    a.p_b(0);

    for(int i = 2; i <= N; i++)if(!f[i]){
        a.p_b(i);
        if(a.size() > 22)break;
        if(ll(i) * ll(i) <= N)for(int j = i * i; j <= N; j += i)f[j] = 1;
    }

    ll m = 20;
    for(int i = 0; i <= m; i++)
        for(int j = 1; j <= n; j++)dp[i][j] = 5e18;

    dp[0][1] = 1;


    for(int i = 1; i <= m; i++){
        ll pr = 1;
        ll kol = 0;

        //for(int j = 1; j <= n; j++)dp[i][j] = dp[i - 1][j];

        while(1){
            for(int j = 1; j <= n; j++)if(j * (kol + 1) <= n && !((5e18) / pr < dp[i - 1][j]) && dp[i - 1][j] != 1e18){
                dp[i][j * (kol + 1)] = min(dp[i][j * (kol + 1)], dp[i - 1][j] * pr);
            }
            if(5e18 / pr < a[i])break;
            pr *= a[i];
            kol++;
        }
    }

    cout << dp[m][n] << "\n";

    return 0;
}