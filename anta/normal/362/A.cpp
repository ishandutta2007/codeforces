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
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

char board[8][9];
char vis[8][8];
const int dy[4] = {-2,-2,2,2}, dx[4] = {-2,2,-2,2};
int main() {
    int t;
    cin >> t;
    rep(ii, t) {
        rep(i, 8) cin >> board[i];
        mset(vis, 0);
        int knights = 0;
        rep(i, 8) rep(j, 8) {
            if(board[i][j] == 'K') {
                vpii q, next;
                next.pb(mp(i, j));
                int parity = 0;
                while(!next.empty()) {
                    q.swap(next);
                    while(!q.empty()) {
                        int y = q.back().first, x = q.back().second;
                        q.pop_back();
                        if(vis[y][x] >> knights * 2 & 3) continue;
                        vis[y][x] |= 1 << knights * 2 + parity;
                        rep(d,4) {
                            int yy = y + dy[d], xx = x + dx[d];
                            if(yy < 0 || yy >= 8 || xx < 0 || xx >= 8) continue;
                            next.push_back(mp(yy, xx));
                        }
                    }
                    parity ^= 1;
                }
                knights ++;
            }
        }
        bool ok = false;
        rep(i, 8) rep(j, 8)
            ok |= (vis[i][j] == 5 || vis[i][j] == 10) && board[i][j] != '#';
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}