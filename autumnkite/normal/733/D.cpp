#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
struct cub{
    int x, y, z;
}a[N];
struct squ{
    int x, y;
    inline bool operator < (const squ &t) const{
        return x < t.x || x == t.x && y < t.y;
    }
    inline bool operator == (const squ &t) const{
        return x == t.x && y == t.y;
    }
}b[N << 2];
struct node{
    int id, l;
}c[N << 2];
int n, m, mx, si, sj;
inline int minn(int a, int b, int c){
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}
inline void updans(int i, int x, int y, int z){
    register int p = lower_bound(b + 1, b + 1 + m, (squ){x, y}) - b;
    register int s = minn(x, y, c[p].l + z);
    if (s > mx) mx = s, si = c[p].id, sj = i;
}
inline void updc(int i, int x, int y, int z){
    register int p = lower_bound(b + 1, b + 1 + m, (squ){x, y}) - b;
    if (z > c[p].l) c[p].id = i, c[p].l = z;
}
int main(){
    scanf("%d", &n);
    for (register int i = 1; i <= n; ++i){
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
        if (a[i].x > a[i].y) swap(a[i].x, a[i].y);
        if (a[i].x > a[i].z) swap(a[i].x, a[i].z);
        if (a[i].y > a[i].z) swap(a[i].y, a[i].z);
        b[++m] = (squ){a[i].x, a[i].y};
        b[++m] = (squ){a[i].x, a[i].z};
        b[++m] = (squ){a[i].y, a[i].z};
    }
    for (register int i = 1; i <= n; ++i)
        if (minn(a[i].x, a[i].y, a[i].z) > mx)
            mx = minn(a[i].x, a[i].y, a[i].z), si = i, sj = 0;
    sort(b + 1, b + 1 + m);
    m = unique(b + 1, b + 1 + m) - b - 1;
    for (register int i = 1; i <= n; ++i){
        updans(i, a[i].x, a[i].y, a[i].z);
        updans(i, a[i].x, a[i].z, a[i].y);
        updans(i, a[i].y, a[i].z, a[i].x);
        updc(i, a[i].x, a[i].y, a[i].z);
        updc(i, a[i].x, a[i].z, a[i].y);
        updc(i, a[i].y, a[i].z, a[i].x);
    }
    if (sj == 0) printf("1\n%d", si);
    else printf("2\n%d %d", si, sj);
}