#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

typedef long long ll;
typedef double db;

const int maxn = 2e5;
const int inf = 1e9;

struct pnt{
    int x, y;
    pnt(){}
    pnt(int _x, int _y){
        x = _x;
        y = _y;
    }
};

pnt que[maxn];
int dist[maxn][2];
string s[2];

int main(){
     int i, n, k, uk1, uk2;
    pnt p, p1;
    cin >> n >> k;
    cin >> s[0];
    cin >> s[1];
    forn(i, n)
        dist[i][0] = dist[i][1] = inf;
    dist[0][0] = 0;
    que[0] = pnt(0, 0);
    uk1 = 0;
    uk2 = 1;

    for(;uk1 < uk2; uk1++){
        p = que[uk1];
        if (p.x == n - 1){
            cout << "YES";
            return 0;
        }

        if (s[p.y][p.x + 1] == '-' && dist[p.x + 1][p.y] > dist[p.x][p.y] + 1){
            que[uk2++] = pnt(p.x + 1, p.y);
            dist[p.x + 1][p.y] = dist[p.x][p.y] + 1;
        }
        if (p.x - 1 >= 0 && s[p.y][p.x - 1] == '-' && dist[p.x - 1][p.y] > dist[p.x][p.y] + 1 && dist[p.x][p.y] + 1 <= p.x - 1){
            que[uk2++] = pnt(p.x - 1, p.y);
            dist[p.x - 1][p.y] = dist[p.x][p.y] + 1;
        }
        p1 = pnt(p.x + k, (p.y + 1) % 2);
        if (p1.x >= n){
            cout << "YES";
            return 0;
        }
        if (s[p1.y][p1.x] == '-' && dist[p1.x][p1.y] > dist[p.x][p.y] + 1){
            que[uk2++] = pnt(p1.x, p1.y);
            dist[p1.x][p1.y] = dist[p.x][p.y] + 1;
        }
    }
    cout << "NO";



    return 0;

}