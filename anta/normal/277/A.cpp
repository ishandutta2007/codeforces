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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER)
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

int n;
bool g[111][111];
bool vis[111];
void dfs(int i) {
    vis[i] = true;
    rep(j, n) if(g[i][j] && !vis[j]) dfs(j);
}
int main() {
    int m;
    scanf("%d%d", &n, &m);
    vector<set<int> > s(n);
    bool empty = true;
    rep(i, n) {
        int k;
        scanf("%d", &k);
        empty &= k == 0;
        rep(j, k) {
            int a;
            scanf("%d", &a);
            s[i].insert(a);
        }
    }
    if(empty) {
        printf("%d\n", n);
        return 0;
    }
    mset(g, 0);
    rep(i, n) reu(j, i+1, n) {
        bool b = false;
        each(k, s[i]) b |= s[j].count(*k) != 0;
        g[i][j] = g[j][i] = b;
    }
    mset(vis, 0);
    int count = 0;
    rep(i, n) if(!vis[i]) {
        count ++;
        dfs(i);
    }
    printf("%d\n", count-1);
    return 0;
}