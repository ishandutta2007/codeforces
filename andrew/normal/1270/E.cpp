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
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

pll ask(vector <ll> q){
    cout << "?";
    for(auto i : q)cout << " " << i;
    cout << endl;
    pll xe;
    cin >> xe.fi >> xe.se;
    return xe;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n;
    cin >> n;
    vector <pll> a(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i].fi >> a[i].se;
    ll cnt[2][2];

    while(1){
        for(int i = 0; i < 2; i++)cnt[i][0] = cnt[i][1] = 0;
        for(int i = 1; i <= n; i++)cnt[a[i].fi & 1][a[i].se & 1]++;
        int kol = 0;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)kol += (cnt[i][j] > 0);
        if(kol == 1){
            for(int i = 1; i <= n; i++){
                (a[i].fi += 1) >>= 1;
                (a[i].se += 1) >>= 1;
            }
        }else{
            if(cnt[0][0] + cnt[1][1] && cnt[1][0] + cnt[0][1]){
                cout << cnt[0][0] + cnt[1][1] << "\n";
                for(int step = 1; step <= n; step++)if(!((a[step].fi ^ a[step].se) & 1)){
                    cout << step << " ";
                }
                cout << "\n";
                return 0;
            }else{
                for(int i = 0; i < 2; i++)
                for(int j = 0; j < 2; j++)if(cnt[i][j]){
                    cout << cnt[i][j] << "\n";
                    for(int step = 1; step <= n; step++)if(((a[step].fi & 1) == i) && ((a[step].se & 1) == j)){
                        cout << step << " ";
                    }
                    cout << "\n";
                    return 0;
                }
            }
        }
    }

    return 0;
}