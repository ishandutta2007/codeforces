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

int x =0, y = 0;
vector < int > vx, vy;
vector < pii > li;
int n;
string cur;
int d;
int a[5020][5020];
ll ans=  0;

int nn, mm;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y){
    a[x][y] = 2;
    for(int i = 0; i < 4; i++){
        int X = dx[i] + x;
        int Y = dy[i] + y;
        if( X >= 0 && Y >= 0 && X < nn && Y< mm && !a[X][Y]) dfs(X, Y);
    }
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    li.pb( mp(0, 0) );
    for(int i = 0;  i< n; i++){
        cin >> cur >> d;
        if( cur == "L"){
            x -= d;
        }else if( cur == "R") {
            x += d;
        }else if( cur == "D"){
            y -= d;
        }
        else {
            y += d;
        }
        li.pb( mp(x,y) );
    }
    for(int i = 0; i < li.size(); i++){
        for(int j = -1; j < 2; j++){
            vx.pb( li[i].f + j);
            vy.pb( li[i].s + j);
        }
    }
    sort(all(vx));
    vx.resize(unique(all(vx)) - vx.begin());
    sort(all(vy));
    vy.resize(unique(all(vy)) - vy.begin());
    for(int i = 0; i +1< li.size(); i++){
        if( li[i].f == li[i + 1].f){
            int st = lower_bound(all(vx), li[i].f) - vx.begin();
            int j = lower_bound(all(vy), li[i].s) - vy.begin();
            int k = lower_bound(all(vy), li[i+1].s) - vy.begin();
            if(j < k) swap(j, k);
            while(j >= k){
                a[st][j] = 1;
                j--; 
            }
        }else {
            int st = lower_bound(all(vy), li[i].s) - vy.begin();
            int j = lower_bound(all(vx), li[i].f) - vx.begin();
            int k = lower_bound(all(vx), li[i+1].f) - vx.begin();
            if(j < k) swap(j, k);
            while(j >= k){
                a[j][st] = 1;
                j--; 
            }
        }
    }
    
    nn = vx.size();
    mm = vy.size();
    
    for(int i = 0; i < nn; i++){
        if(!a[i][0]) dfs(i, 0);
    }
    for(int i = 0; i < nn; i++){
        if(!a[i][mm-1]) dfs(i, mm-1);
    }
    for(int i = 0; i < mm; i++){
        if(!a[0][i]) dfs(0, i);
    }
    for(int i = 0; i < mm; i++){
        if(!a[nn-1][i]) dfs(nn - 1, i);
    }

    for(int i = 1; i < nn; i++){
        for(int j = 1;  j < mm; j++){
            if(a[i][j] == 2) continue;
            if(a[i-1][j] != 2 && a[i][j - 1] != 2 && a[i-1][j-1] != 2){
                ans += (vx[i] - vx[i-1] )  * 1ll * (vy[j] - vy[j - 1]);
            }else if(a[i][j] == 0 || (a[i-1][j] != 2 && a[i][j-1] != 2)) {
                ans += vx[i] - vx[i-1];
                ans += vy[j] - vy[j-1];
                ans--;
            }
            else if(a[i-1][j] != 2){
                ans += vx[i] - vx[i-1];
            }
            else if(a[i][j-1] != 2){
                ans += vy[j] - vy[j-1];
            }
            else ans++;
        }
    }
    cout << ans << endl;
    
    
    



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}