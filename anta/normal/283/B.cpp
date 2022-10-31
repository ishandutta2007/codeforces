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
int a[200001];
pair<char,ll> dist[2][200001];
bool vis[2][200001];
bool memo[2][200001];

pair<char,ll> dfs(bool pm, int i) {
    if(memo[pm][i]) return dist[pm][i];
    if(vis[pm][i]) {
        memo[pm][i] = true;
        return dist[pm][i] = mp(-1, INFL);
    }
    memo[pm][i] = true;
    if(i == 0) {
        return dist[pm][i] = mp(pm, 0);
    }
    int next = !pm ? i + a[i] : i - a[i];
    if(next < 0 || next >= n) {
        return dist[pm][i] = mp(-1, a[i]);
    }else {
        vis[pm][i] = true;
        pair<char,ll> d = dfs(!pm, next);
        vis[pm][i] = false;
        return dist[pm][i] = mp(d.first, d.second == INFL ? INFL : a[i] + d.second);
    }
}

int main() {
    scanf("%d", &n);
    rep(i, n-1)
        scanf("%d", &a[1+i]);
    mset(vis, 0); mset(memo, 0);
    rep(pm, 2) reu(i, 1, n)
        if(!memo[pm][i]) dfs(pm, i);
    reu(i, 1, n) {
        ll d;
        pair<char,ll> p = dist[1][i];
        if(p.first == -1) {
            d = p.second == INFL ? -1 : i + p.second;
        }else if(p.first == 0) {
            d = -1;
        }else if(dist[0][i].first == 1) {   //0
            d = i + p.second;
        }
        printf("%I64d\n", d);
    }
    return 0;
}