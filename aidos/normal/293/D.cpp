#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int xx[300100],yy[300100];
double a[2000100];
double b[2000100];

double aa[2000100];
double bb[2000100];
int get_up(double k){
    int x = (int) k;
    if( fabs(k - x) > 1e-12) return x+1;
    return x;
}
int get_down(double k){
    int x = (int) (k+1e-12);
    return x;
}
int n;
double get(int j, int sx, int sy, int nx, int ny){
    if(sx == nx) {
        return sy;
    }
    if(ny == sy) return sy;
    int diff = nx - sx;
    int diff2 = j - sx;
    int di = ny - sy;
//  (cur - sy)/ di = diff2/diff;
    double cur = (di * 1ll * diff2 + sy * 1ll * diff + 0.0)/diff;
    return cur;
}
ll get(int sx, int sy, int nx, int ny){
    return (nx - sx) * 1ll * (ny + sy);
}
double get(int x[], int y[]){
    double area = 0;
    ll cnt = 0;
    for(int i = 0; i < 2000011; i++){
        a[i] = inf;
        b[i] = -inf;
    }
    for(int i=0; i < n; i++){
        int nx = x[(i + 1) % n];
        int ny = y[(i+1) % n];
        a[nx] = min(ny + 0.0, a[nx]);
        b[nx] = max(ny+0.0, b[nx ]);

        int sx = x[i];
        int sy = y[i];

        a[sx] = min(sy + 0.0, a[sx]);
        b[sx] = max(sy+0.0, b[sx]);
        
        if(nx < sx) {
            swap(nx, sx);
            swap(ny, sy);
        }
        for(int j = sx; j <= nx; j++){
            double poi = get(j, sx, sy, nx, ny);
            a[j] = min(poi, a[j]);
            b[j] = max(poi, b[j]);
//          cout << j << " " << sx << " " << sy << " " << nx << " " << ny << " " << poi<< endl;
        }
    }
    double ans=0;
    ll prev = 0;
    for(int i = 0; i < 2000001; i++){
        int down = get_up(a[i]);
        int up = get_down(b[i]);
        ll go = up - down + 1;
        if(down > up) {
            go = 0;
        }
        cnt+=go;
        if(go > 0){
        }
    }
    ll sum1 = 0;
    ll sum2 = 0;
    double sum3 = 0;
    for(int i = 0; i < 2000001; i++){
        int down = get_up(a[i]);
        int up = get_down(b[i]);
        ll go = up - down + 1;
        if(down > up) {
            go = 0;
        }
        sum2 += sum1 - prev;
        sum1 += 2ll * go;
        sum3 += 1.0 * sum2/cnt/(cnt-1.0);
        prev = go;
        ans += sum3 * go;
    }         
//  cout << ans << endl;
//  cout << cnt << endl;

    return ans;
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> xx[i] >> yy[i];
        xx[i] += 1000000;
        yy[i] += 1000000;
    }
    
    double ans = (get(xx, yy) + get(yy, xx));
    printf("%.17lf\n", ans);
//  cout << ans << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}