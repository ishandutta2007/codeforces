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

int n;
bool g[2000][2000];
bool vis[2000];
int po[2000];

int dfsPostOrder(int cur, int pop) {
    vis[cur] = true;
    rep(i, n) if(!vis[i])
        if(g[cur][i])
            pop = dfsPostOrder(i, pop);
    po[pop++] = cur;
    return pop;
}

bool isSC() {
    rep(i, n) vis[i] = false;
    int pop = 0;
        
    rep(i, n) if(!vis[i])
        pop = dfsPostOrder(i, pop);
    rep(i, n) vis[i] = false;
    pop = 0;
        
    rep(i, n) if(!vis[i])
        pop = dfsPostOrder(i, pop);
        
    vector<int> ret(n);
    rep(i, n) vis[i] = false;
    int clus = 0;
    vector<int> q;
    for(int i = n - 1;i >= 0;i--) {
        if(!vis[po[i]]){
            q.push_back(po[i]);
            vis[po[i]] = true;
            while(!q.empty()){
                int cur = q.back(); q.pop_back();
                ret[cur] = clus;
                rep(k, n) if(!vis[k]) {
                    if(g[k][cur]){
                        q.push_back(k);
                        vis[k] = true;
                    }
                }
            }
            clus++;
        }
    }
    return clus <= 1;
}

int main() {
    scanf("%d", &n);
    rep(i, n) rep(j, n) {
        int a;
        scanf("%d", &a);
        g[i][j] = a > 0;
    }
    if(!isSC()) {
        puts("NO");
    }else {
        puts("YES");
    }

    return 0;
}