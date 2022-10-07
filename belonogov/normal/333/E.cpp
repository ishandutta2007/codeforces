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

const int maxn = 3003;
const int inf = 1e9;

struct pnt{
    int x, y;
    pnt(){}
    pnt(int x, int y): x(x), y(y){};
    pnt operator - (const pnt & a){
    return pnt(x - a.x, y - a.y);
    }
    inline int operator * (const pnt & a)const{
    return x * a.y - y * a.x;
    }
    inline int len2() const{
    return x * x + y * y;
    }
    void Epr(){
    epr("x y: %d %d\n", x, y);
    }
};

pnt a[maxn];
pnt b[maxn];
pnt c1[maxn];
pnt c[maxn];
int dist[maxn];
int n;
int bsz = 0, sz;


inline int Dist(const pnt & a, const pnt & b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

inline bool cmp(const pnt & p1, const pnt & p2){
    return p1 * p2 > 0 || (p1 * p2 == 0 && p1.len2() < p2.len2());
    //     return (p1 - b[0]) * (p2 - b[0]) > 0 || ((p1 - b[0]) * (p2 - b[0]) == 0 && (p1 - b[0]).len2() < (p2 - b[0]).len2());
}
bool cmpX(pnt p1, pnt p2){
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

void convex_full(){
    sz = 0;
    for(int i = 0; i < bsz; i++){
    if ((b[i] - b[0]) * (b[bsz - 1] - b[0]) < 0)
        continue;
    for(; sz > 1 && (c[sz - 1] - c[sz - 2]) * (b[i] - c[sz - 1]) <= 0; sz--);
    c[sz++] = b[i];
    }
//     epr("first part\n");
//     for(int i = 0; i < sz; i++)
//  c[i].Epr();
//     epr("\n");
    int cur = 0;
    for(int i = bsz - 1; i >= 0; i--){
    if ((b[i] - b[0]) * (b[bsz - 1] - b[0]) > 0)
        continue;
    for(; cur > 1 && (c1[cur - 1] - c1[cur - 2]) * (b[i] - c1[cur - 1]) <= 0; cur--);
    c1[cur++] = b[i];
    }
    for(int i = 1; i < cur - 1; i++)
    c[sz++] = c1[i];
    
}

inline int two_far_point(){
    convex_full();
    int cur1 = 0, cur2 = 0;
    int ans2 = 0;
    pnt v1, v2;
    for(int i = 0; i < sz + 5; i++){
    ans2 = max(ans2, (c[cur1] - c[cur2]).len2());

    v1 = c[(cur1 + 1) % sz] - c[cur1];
    v2 = c[(cur2 + 1) % sz] - c[cur2];
    if (v1 * v2 >= 0)
        cur2 = (cur2 + 1) % sz;
    else
        cur1 = (cur1 + 1) % sz;
    }
    return ans2;
}



inline bool solve(int v, int r){
    bsz = 0;
    
    for(int i = 0; i < n; i++)
    if ((a[v] - a[i]).len2() >= r)
        b[bsz++] = a[i];
    
   return (bsz == 0) ? 0 : two_far_point() >= r;
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int ans2 = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    scanf("%d%d", &a[i].x, &a[i].y);
    
    sort(a, a + n, cmpX);
    
/*    
    for(int i = 0; i < n; i++)
    b[bsz++] = a[i];
    convex_full();
    for(int i = 0; i < sz; i++)
    c[i].Epr();
    return 0; 
    */
    
    for(int i = 0; i < n; i++){
    for(int j = i; j < n; j++)
        dist[j - i] = Dist(a[i], a[j]);
    sort(dist, dist + n - i);
    int l = 0;
    int r = n - i;
    while(r - l > 1){
        if (solve(i, dist[(l + r) / 2]))
        l = (l + r) / 2;
        else
        r = (l + r) / 2;
    }
    ans2 = max(ans2, dist[l]);  
    }
    cout.precision(15);
    cout << fixed << sqrt(ans2 * 1.0) / 2 << endl;
    return 0;
}

//  for(int i = 0; i < bsz; i++)
//  if (b[i].y < b[0].y || (b[i].y == b[0].y && b[i].x < b[0].x))
//      swap(b[0], b[i]);
//     for(int i = bsz - 1; i != -1; i--)
//  b[i] = b[i] - b[0];
//     
//     sort(b + 1, b + bsz, cmp);
//     int sz = 0;
//     for(int i = 0; i < bsz; i++){
//  for(;sz >= 2 && (c[sz - 1] - c[sz - 2]) * (b[i] - c[sz - 1]) <= 0; sz--);
//      c[sz++] = b[i];
//     }
//