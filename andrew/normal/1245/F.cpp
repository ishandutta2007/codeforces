#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 32;
const ll inf = 3e18;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll dp[40][2][2][2][2];

ll f(ll l, ll r){
    for(int st = 0; st < 40; st++)
        for(int j = 0; j < 2; j++)
        for(int j1 = 0; j1 < 2; j1++)
        for(int i = 0; i < 2; i++)
        for(int i1 = 0; i1 < 2; i1++)dp[st][j][j1][i][i1] = 0;

    vector <ll> L, R;


    for(int i = N; i >= 0; i--){
        L.p_b((pw(i) & l) > 0);
        R.p_b((pw(i) & r) > 0);
    }

    for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)if(i + j == (i ^ j)){
        if((L[0] <= i && i <= R[0]) && (L[0] <= j && j <= R[0]))dp[0][L[0] < i][i < R[0]][L[0] < j][j < R[0]]++;
    }

    for(int step = 1; step <= N; step++){
        for(int oi = 0; oi < 2; oi++)
            for(int oi1 = 0; oi1 < 2; oi1++)
            for(int oj = 0; oj < 2; oj++)
        for(int oj1 = 0; oj1 < 2; oj1++){
            for(int wi = 0; wi < 2; wi++)
            for(int wj = 0; wj < 2; wj++)if(wi + wj == (wi ^ wj)){
                bool fi, fi1, fj, fj1;
                ll Le, Ri, L1, R1;
                Le = L[step], Ri = R[step];
                L1 = L[step], R1 = R[step];
                if(oi)Le = -1;if(oi1)Ri = 10;
                if(oj)L1 = -1;if(oj1)R1 = 10;
                if(!(Le <= wi && wi <= Ri && L1 <= wj && wj <= R1))continue;
                fi = (Le < wi);
                fi1 = (wi < Ri);
                fj = (L1 < wj);
                fj1 = (wj < R1);
                dp[step][fi][fi1][fj][fj1] += dp[step - 1][oi][oi1][oj][oj1];
            }
        }
    }

    ll ans = 0;

    for(int i = 0; i < 2; i++)
        for(int i1 = 0; i1 < 2; i1++)
        for(int j = 0; j < 2; j++)
        for(int j1 = 0; j1 < 2; j1++)ans += dp[N][i][i1][j][j1];

    return ans;

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll t;
    cin >> t;


    while(t--){
        ll l, r;
        cin >> l >> r;
        cout << f(l, r) << "\n";
    }

    return 0;
}