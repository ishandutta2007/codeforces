#include <bits/stdc++.h>

//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

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

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1123456;
const int N = 1e5 + 3;
const int M = pw(10);
const int inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

bool f[2][MAXN];
ll n;
char c[2][MAXN];

void dfs(ll x, ll y, ll dx, ll dy){
    f[x][y] = 1;
    if(y == n + 1)return;
    if(dx == x){
        if(c[x][y] > '2')dfs(1 - x, y, x, y);
        else dfs(x, y + 1, x, y);
    }else{
        if(c[x][y] > '2')dfs(x, y + 1, x, y);
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll q;
    cin >> q;

    while(q--){
        cin >> n;

        for(int i = 0; i < 2; i++)
        for(int j = 1; j <= n; j++)cin >> c[i][j];

        for(int i = 0; i < 2; i++)
            for(int j = 0; j < n + 2; j++)f[i][j] = 0;

        dfs(0, 1, 0, 0);

        if(f[1][n + 1])cout << "YES\n"; else cout << "NO\n";

    }

    return 0;
}