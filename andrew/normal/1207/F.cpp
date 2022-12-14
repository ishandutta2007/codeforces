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
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 5e5;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll SQ = 708;

ll arr[N + 1];

ll Sum[709][709];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll M;

    cin >> M;

    ll ans = 0;

    for(int step = 1; step <= M; step++){
        ll type;
        cin >> type;
        if(type == 1){
            ll x, y;
            cin >> x >> y;
            arr[x] += y;
            for(int i = 1; i <= SQ; i++)Sum[i][x % i] += y;
        }else{
            ll x, y;
            cin >> x >> y;
            if(x <= SQ){
                cout << Sum[x][y] << "\n";
            }else{
                ans = 0;
                for(int i = y; i <= N; i += x)ans += arr[i];
                cout << ans << "\n";
            }
        }
    }

    return 0;
}