#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


#define fi first
#define se second
#define p_b push_back
#define pll pair <ll, ll>
#define pii pair <int, int>
#define m_p make_pair
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define ifn(x) if(!(x))
#define fout(x) {cout << x << "\n"; return;}


using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5 + 2;
const ll inf = 1e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s) {cout << s << endl; exit(0);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

char c[51][51];

bool f[51][51];

queue <pii> q;

int n, m;

void add(int x, int y){
    if(x < 1 || y < 1 || x > n || y > m)return;
    if(c[x][y] == '#')return;
    if(f[x][y])return;
    f[x][y] = 1;
    q.push({x, y});
}

void solve(){
    cin >> n >> m;
    int cnt_g = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c[i][j];
            if(c[i][j] == 'G')cnt_g++;
            f[i][j] = 0;
        }
    }

    if(!cnt_g)fout("Yes");

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(c[i][j] == 'B'){
                if(i + 1 <= n){
                    if(c[i + 1][j] == 'G')fout("No");
                    if(c[i + 1][j] != 'B')c[i + 1][j] = '#';
                }
                if(j + 1 <= m){
                    if(c[i][j + 1] == 'G')fout("No");
                    if(c[i][j + 1] != 'B')c[i][j + 1] = '#';
                }
                if(i > 1){
                    if(c[i - 1][j] == 'G')fout("No");
                    if(c[i - 1][j] != 'B')c[i - 1][j] = '#';
                }
                if(j > 1){
                    if(c[i][j - 1] == 'G')fout("No");
                    if(c[i][j - 1] != 'B')c[i][j - 1] = '#';
                }
            }
        }
    }

    add(n, m);

    while(!q.empty()){
        pii xe = q.front();
        q.pop();
        add(xe.fi + 1, xe.se);
        add(xe.fi - 1, xe.se);
        add(xe.fi, xe.se + 1);
        add(xe.fi, xe.se - 1);
    }

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        if(c[i][j] == 'G' && !f[i][j])fout("No");
        if(c[i][j] == 'B' && f[i][j])fout("No");
    }

    fout("Yes");

}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    int t;
    cin >> t;

    while(t--)solve();

    return 0;
}