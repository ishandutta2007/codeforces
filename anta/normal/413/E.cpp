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
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int H = 2, W;
char board[2][200001];
vi dists[20][2][2];

void getdist_rec(int lv, int left, int right) {
    if(left > right) return;
    int mid = (left + right) / 2;
    rep(y0, H) {
        vi *dist = dists[lv][y0];
        rep(y, H) rer(x, left, right) dist[y][x] = INF;
        if(board[y0][mid] == 'X') continue;
        vi q, nq;
        dist[y0][mid] = 0;
        nq.push_back(y0 * W + mid);
        int dd = 0;
        while(!nq.empty()) {
            q.swap(nq);
            while(!q.empty()) {
                int y = q.back() / W, x = q.back() % W; q.pop_back();
                static const int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};
                rep(d, 4) {
                    int yy = y + dy[d], xx = x + dx[d];
                    if(yy<0||yy>=H||xx<left||xx>right) continue;
                    if(board[yy][xx] == 'X') continue;
                    if(dist[yy][xx] == INF) {
                        dist[yy][xx] = dd + 1;
                        nq.push_back(yy * W + xx);
                    }
                }
            }
            dd ++;
        }
    }
    getdist_rec(lv + 1, left, mid - 1);
    getdist_rec(lv + 1, mid + 1, right);
}

int getlevels(int left, int right) {
    if(left > right) return 0;
    int mid = (left + right) / 2;
    return max(getlevels(left, mid - 1), getlevels(mid + 1, right)) + 1;
}

int query_rec(int lv, int left, int right, int vy, int uy, int vx, int ux) {
    int mid = (left + right) / 2;
    if((vx <= mid && mid <= ux) || (ux <= mid && mid <= vx)) {
        int res = INF;
        rep(y0, H) {
//          cerr << vy << "," << vx << ", " << uy << "," << ux << ", " << y0 << ", " << mid << ": " << dists[lv][y0][vy][vx] << " + " << dists[lv][y0][uy][ux] << endl;
            amin(res, dists[lv][y0][vy][vx] + dists[lv][y0][uy][ux]);
        }
        return res;
    }else if(vx < mid && ux < mid) {
        return query_rec(lv + 1, left, mid - 1, vy, uy, vx, ux);
    }else if(mid < vx && mid < ux) {
        return query_rec(lv + 1, mid + 1, right, vy, uy, vx, ux);
    }else {
        cerr << "Error!" << endl;
        return INF;
    }
}

int main() {
    int Q;
    scanf("%d%d", &W, &Q);
    rep(i, H) scanf("%s", &board[i]);
    int levels = getlevels(0, W - 1);
    rep(lv, levels) rep(y0, H) rep(y, H)
        dists[lv][y0][y].assign(W, INF);
    getdist_rec(0, 0, W - 1);
    rep(ii, Q) {
        int v, u;
        scanf("%d%d", &v, &u), v --, u --;
        int vy = v / W, vx = v % W;
        int uy = u / W, ux = u % W;
        int ans = query_rec(0, 0, W - 1, vy, uy, vx, ux);
        if(ans == INF) puts("-1");
        else printf("%d\n", ans);
    }
    return 0;
}