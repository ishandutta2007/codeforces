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
#include <memory>
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

vector<vi> g;
vector<vector<char> > gt;
bool problem[100000];
vi ans;

void dfs(int i, int parent) {
    rep(j, g[i].size()) {
        int e = g[i][j];
        if(e != parent) {
            dfs(e, i);
            problem[e] = gt[i][j];
        }
    }
}
int dfs2(int i, int parent) {
    int problems = 0;
    rep(j, g[i].size()) if(g[i][j] != parent)
        problems += dfs2(g[i][j], i);
//  cout << i << ": " << problem[i] << ", " << problems << endl;
    if(problem[i] && problems == 0)
        ans.pb(i);
    problems += problem[i];
    return problems;
}

int main() {
    int n;
    cin >> n;
    g.assign(n, vi());
    gt.assign(n, vector<char>());
    rep(i, n-1) {
        int x, y, t;
        cin >> x >> y >> t; x --, y --;
        g[x].pb(y);
        g[y].pb(x);
        gt[x].pb(t == 2);
        gt[y].pb(t == 2);
    }
    mset(problem, 0);
    dfs(0, -1);
    ans.clear();
    dfs2(0, -1);
    cout << ans.size() << endl;
    rep(i, ans.size()) {
        cout << ans[i]+1;
        if(i != ans.size()-1) cout << " ";
    }
    cout << endl;

    return 0;
}