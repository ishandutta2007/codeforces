#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cmath>
#include <queue>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

const int maxn = 1100;
const int inf = 1e9;
const int step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dist[maxn][maxn];
char a[maxn][maxn];
queue < pair < int, int > > q;
int n, m;

bool check(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main(){
   // freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int x, y;
    pair < int, int > s, e, v;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", a[i]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if (a[i][j] == 'S')
                s = mp(i, j);
            if (a[i][j] == 'E')
                e = mp(i, j);
        }
    memset(dist, 63, sizeof(dist));
    dist[e.fr][e.sc] = 0;
    q.push(e);
    while(!q.empty()){
        v = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            x = v.fr + step[i][0];
            y = v.sc + step[i][1];
            if (check(x, y) && a[x][y] != 'T' && dist[x][y] > dist[v.fr][v.sc] + 1){
                dist[x][y] = dist[v.fr][v.sc] + 1;
                q.push(mp(x, y));
            }
        }
    }
    int Mdist = dist[s.fr][s.sc], ans = 0;
   // cerr << Mdist << endl;
   /* for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cerr << dist[i][j] << " ";
        cerr << "\n";
    }
    */for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if (dist[i][j] <= Mdist && '0' <= a[i][j] && a[i][j] <= '9')
                ans += a[i][j] - '0';

    cout << ans << endl;
    return 0;
}