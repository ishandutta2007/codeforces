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
#include <cstdlib>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 2e5 + 10;

using namespace std;
int n, m;
int dx, dy;
int curx[1000100];
int cury[1000100];
int posx[1000100];
int posy[1000100];
int cnt[1000100];

void calc(int *cur, int *pos, int x){
    int d = 0;
    for(int i = 0; i<n; i++){
        cur[i] = d;
        pos[d] = i;
        d += x;
        if( d >= n) d-=n;
    }
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> m >> dx >> dy;
    
    calc(curx, posx, dx);
    calc(cury, posy, dy);
    
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        cnt[cury[(posy[y] - posx[x] + n) % n]]++;
    }
    int mx = 0;
    for(int i = 0; i<n; i++) if( cnt[mx] < cnt[i]) mx = i;
    cout << 0 << " " << mx << endl;
    
    
    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}