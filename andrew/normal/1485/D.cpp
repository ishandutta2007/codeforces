#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }
#define sqr(x) (x) * (x)

using namespace std;
typedef long long ll;
typedef long double ld;
const ll M = 2e5;
const int inf = 1e8;
const ll mod = 1e9 + 7;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll a[1000][1000], b[1000][1000];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    ll c = 1;
    for(ll i = 2; i <= 16; i++)c = (c * i) / __gcd(c, i);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if((i + j) % 2 == 0)b[i][j] = c;
        }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)if((i + j) % 2 == 1){
            for(int i1 = 1; i1 <= 35; i1++){
                ll val = sqr(sqr(i1));
                if(c > val && (c - val) % a[i][j] == 0){
                    b[i][j] = c - val;
                }
            }
        }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)cout << b[i][j] << " ";
        cout << "\n";
    }

    return 0;
}