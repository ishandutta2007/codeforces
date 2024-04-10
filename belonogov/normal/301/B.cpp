#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 1000;
const int inf = 1e9;

struct pnt{
    int x, y;
    pnt(){}
    pnt(int x, int y): x(x), y(y){};
    int len(pnt p){
    return abs(x - p.x) + abs(y - p.y);
    }
};

int a[maxn];
pnt p[maxn];
int dist[maxn];
int n, d;
queue < int > q;

bool solve(int k){
    int v;
    q.push(0);
    for(int i = 0; i < n; i++)
    dist[i] = -1;
    dist[0] = k;
    
    while(!q.empty()){
    v = q.front();
    q.pop();
    for(int i = 0; i < n; i++){
        if (i != v && dist[v] - p[v].len(p[i]) * d + a[v] > dist[i]){
        q.push(i);
        dist[i] = dist[v] - p[v].len(p[i]) * d + a[v];
        }  
    }
    }
    return dist[n - 1] >= 0;    
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    
    scanf("%d%d", &n, &d);
    for(int i = 1; i < n - 1; i++)
    scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
    scanf("%d%d", &p[i].x, &p[i].y);
    
    int l = 0, r = 100000 * 401;
    while(r - l > 1){
    if (solve((l + r) / 2))
        r = (l + r) / 2;
    else
        l = (l + r) / 2;
    }

    printf("%d\n", r);
    return 0;
}