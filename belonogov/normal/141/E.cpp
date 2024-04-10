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

const int maxn = 1e5 + 2;
const int inf = 1e9;

struct Edge{
    int v, u, t, id;
    bool flag;
    Edge(){}
    Edge(int v, int u, int t, int id): v(v), u(u), t(t), id(id), flag(0){}
};

Edge a[maxn];
int p[maxn];


int getId(int v){
    if (p[v] == v) return v;
    return p[v] = getId(p[v]);      
}

void merge(int v, int u){
    p[v] = u;   
}

// void ret(){
//  printf("-1\n");
//  exit (0);
// }


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, m, cur = 0, cntM = 0, cntS = 0, p1, p2, com, v, u;
    char c;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++){
        scanf("%d %d %c", &v, &u, &c); v--; u--;
        assert(c == 'M' || c == 'S');
        if (v != u)
            a[cur++] = Edge(v, u, (c == 'M'), i);       
        
        cntM += c == 'M';
        cntS += c == 'S';       
    }
    if (cntM * 2 < n - 1 || cntS * 2 < n - 1 || n % 2 == 0){
        printf("-1\n");
        return 0;
    }
    
    
    
    
    m = cur;
    com = n;
    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i = 0; i < m; i++)
        if (a[i].t){
            p1 = getId(a[i].v);
            p2 = getId(a[i].u);
            if (p1 != p2){
                merge(p1, p2);
                com--;
                
            }
        }
    
    for (int i = 0; i < m; i++)
        if (!a[i].t){
            p1 = getId(a[i].v);
            p2 = getId(a[i].u);
            if (p1 != p2){
                a[i].flag = 1;
                merge(p1, p2);
                com--;              
            }
        }
    assert(com >= 1);
    if (com != 1){
        printf("-1\n");
        return 0;       
    }
    
    for (int i = 0; i < n; i++)
        p[i] = i;
    
    cntS = (n - 1) / 2;
    for (int i = 0; i < m; i++)
        if (a[i].flag){
            p1 = getId(a[i].v);
            p2 = getId(a[i].u);
            if (p1 != p2){
                merge(p1, p2);
                cntS--;             
            }
        }
    
    for (int i = 0; i < m; i++)
        if (cntS && a[i].t == 0){
            p1 = getId(a[i].v);
            p2 = getId(a[i].u);
            if (p1 != p2){
                merge(p1, p2);
                a[i].flag = 1;
                cntS--;             
            }
        }
    if (cntS != 0){
        printf("-1\n");
        return 0;       
    }
    for (int i = 0; i < m; i++)
        if (a[i].t){
            p1 = getId(a[i].v);
            p2 = getId(a[i].u);
            if (p1 != p2){
                merge(p1, p2);
                a[i].flag = 1;
            }
        }
    printf("%d\n", n - 1);
    for (int i = 0; i < m; i++)
        if (a[i].flag)
            printf("%d ", a[i].id + 1);
    printf("\n");
    return 0;
}