#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>
#include <queue>

using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr 
#endif 

const int maxn = 2000;
const int inf = (int)1e9;

struct pnt{
    long double x, y;
    pnt(){}
    pnt(long double x, long double y): x(x), y(y){};
    pnt operator - (pnt A){
        return pnt(x - A.x, y - A.y);
    }
    long double len(){
        return sqrt(x * x + y * y);
    }
};

pnt a[maxn];
vector < int > e[maxn];
vector < long double > c[maxn];
vector < int > w[maxn];
vector < int > par[maxn];
queue < int > q;
bool use[maxn];
long double dist[maxn];
int p[maxn];
int id[maxn];
int f, s, n, cur;
long double ans = 0;

bool levit(){
    int v;
    for(int i = 0; i < n * 2 + 2; i++)
        dist[i] = inf;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        v = q.front();
        q.pop();
//         epr("v %d\n", v);
        
        use[v] = 0;
        for(int i = 0; i < (int)e[v].size(); i++)
            if (w[v][i] > 0 && dist[e[v][i]] > dist[v] + c[v][i]){
    dist[e[v][i]] = dist[v] + c[v][i];
    p[e[v][i]] = v;
    id[e[v][i]] = i;
    if (!use[e[v][i]]){
        q.push(e[v][i]);
        use[e[v][i]] = 1;
    }
            }
    }/*
    for(int i = 0; i < n * 2 + 2; i++)
        epr("%lf  ", (double)dist[i]);
    epr("\n");*/
    if (dist[f] >= inf - 1) return 0;
    
    int d = f;
    for(;d != s;){
        w[p[d]][id[d]]--;
        ans += c[p[d]][id[d]];
        w[d][par[p[d]][id[d]]]++;
        d = p[d];
    }
    return 1;
}

void add(int v, int u, long double cc, int ww){
    e[v].pb(u);
    c[v].pb(cc);
    w[v].pb(ww);
    par[v].pb(e[u].size());
    
    e[u].pb(v);
    c[u].pb(-cc);
    w[u].pb(0);
    par[u].pb(e[v].size() - 1);
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int x, y;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &x, &y);
        a[i] = pnt(x, y);
    }
    s = n * 2;
    f = n * 2 + 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if (a[i].y > a[j].y)
    add(i, j + n, (a[i] - a[j]).len(), 1);
    
    for(int i = 0; i < n; i++)
        add(s, i, 0, 2);
    
    for(int i = 0; i < n; i++)
        add(i + n, f, 0, 1);
    
    
    for(int i = 0; i < n - 1; i++)
        if (!levit()){
            cout << -1 << endl;
            return 0;
        }
    
    cout.precision(15);
    cout << fixed << ans << endl;
    

    return 0;
}