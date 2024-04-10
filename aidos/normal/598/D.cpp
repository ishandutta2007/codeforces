#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (1ll << 31) - 1;
const int mod = (int) 1e9 + 7;

int used[1010][1010];
int cc = 0;
char c[1010][1010];
int n, m, k;
int p[2001000];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int ans[2001000];
bool ok (int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m && !used[x][y];
}
void dfs(int x, int y, int cc){
    used[x][y] = cc;
    for(int i = 0; i<4; i++){
        int a=x + dx[i];
        int b = y + dy[i];
        if(ok(a, b)){
            if(c[a][b] == '.'){
                dfs(a, b, cc);
            }else {
                ans[cc]++;
            }
        }
    }
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++){
        scanf("%s", &c[i]);
    }
    for(int i = 0, x, y; i < k; i++){
        scanf("%d %d\n", &x, &y);
        x--;
        y--;
        if(used[x][y] > 0){
            printf("%d\n", ans[used[x][y]]);
        }
        else {
            cc++;
            dfs(x, y, cc);
            printf("%d\n", ans[used[x][y]]);
        }
    }       
    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}