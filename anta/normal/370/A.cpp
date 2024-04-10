#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <list>
#include <cassert>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

namespace glb {
int y1, x1, y2, x2;
int bfs(vpii moves) {
    static bool vis[8][8];
    mset(vis, 0);
    vpii q, next;
    next.pb(mp(y1, x1));
    int d = 0;
    while(!next.empty()) {
        q.swap(next);
        while(!q.empty()) {
            int y = q.back().first, x = q.back().second;
            q.pop_back();
            if(vis[y][x]) continue;
            vis[y][x] = true;
            if(y == y2 && x == x2) return d;
            each(m, moves) {
                int yy = y + m->first, xx = x + m->second;
                if(yy<0||yy>=8||xx<0||xx>=8) continue;
                next.pb(mp(yy,xx));
            }
        }
        d ++;
    }
    return 0;
}
}

int main() {
    cin >> glb::y1 >> glb::x1 >> glb::y2 >> glb::x2;
    glb::y1 --, glb::x1 --, glb::y2 --, glb::x2 --;
    vpii moves1, moves2, moves3;
    rer(x, -8, 8) moves1.pb(mp(0, x));
    rer(y, -8, 8) moves1.pb(mp(y, 0));
    rer(x, -8, 8) moves2.pb(mp(x, x));
    rer(x, -8, 8) moves2.pb(mp(x, -x));
    rer(dy, -1, 1) rer(dx, -1, 1) moves3.pb(mp(dy, dx));
    cout << glb::bfs(moves1) << " " << glb::bfs(moves2) << " " << glb::bfs(moves3) << endl;
    return 0;
}