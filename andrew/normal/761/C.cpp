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

template <typename T> void vout(T s){
    cout << s << endl;
    exit(0);
}

ll what(char c){
    if('0' <= c && c <= '9')return 0;
    if('a' <= c && c <= 'z')return 1;
    return 2;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;

    vector <vector <ll> > rust(n + 1);

    for(int i = 1; i <= n; i++){
        rust[i].resize(3);

        for(int j = 0; j < 3; j++)rust[i][j] = 1e18;

        for(int j = 1; j <= m; j++){
            char a;
            cin >> a;

            ll type = what(a);
            ll val = min(j - 1ll, m - j + 1);
            rust[i][type] = min(rust[i][type], val);

        }

    }


    ll ans = 1e18;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)if(i != j)
            for(int k = 1; k <= n; k++)if(i != k && k != j){
                ans = min(ans, rust[i][0] + rust[j][1] + rust[k][2]);
            }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}