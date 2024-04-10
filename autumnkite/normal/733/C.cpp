#include <cstdio>
const int N = 505;
int n, a[N], m, b[N], cnt;
struct node{
    int x;
    char y;
}c[N];
inline int max(int a, int b){
    return a > b ? a : b;
}
int main(){
    scanf("%d", &n);
    for (register int i = 1; i <= n; ++i) scanf("%d", a + i);
    scanf("%d", &m);
    for (register int i = 1; i <= m; ++i) scanf("%d", b + i);
    register int r = 1, l = 1, i = 1, s = a[1], mx = a[1];
    for (cnt = 0; r <= n; ++r, s += a[r], mx = max(mx, a[r]))
        if (s == b[i]){
            if (r - l == 0){
                ++i, l = r + 1, s = 0, mx = 0;
                continue;
            }
            register int Lmx = l, Rmx = r, id = 0;
            for (register int j = l; j <= r; ++j)
                if (a[j] == mx){
                    Lmx = j;
                    break;
                }
            for (register int j = Lmx; j <= r; ++j)
                if (a[j] != mx){
                    Rmx = j - 1;
                    break;
                }
            if (Lmx != l){
                id = Lmx - l + i;
                for (register int j = 1; j <= Lmx - l; ++j, --id)
                    c[++cnt] = (node){id, 'L'};
                for (register int j = 1; j <= r - Lmx; ++j)
                    c[++cnt] = (node){id, 'R'};
            }
            else if (Rmx != r){
                id = Rmx - l + i;
                for (register int j = 1; j <= r - Rmx; ++j)
                    c[++cnt] = (node){id, 'R'};
                for (register int j = 1; j <= Rmx - l; ++j, --id)
                    c[++cnt] = (node){id, 'L'};
            }
            else return printf("NO"), 0;
            ++i, l = r + 1, s = 0, mx = 0;
        }
        else if (s > b[i]) return printf("NO"), 0;
    if (i != m + 1) return printf("NO"), 0;
    printf("YES\n");
    for (register int i = 1; i <= cnt; ++i)
        printf("%d %c\n", c[i].x, c[i].y);
}