#include <cstdio>
const int N = 100005;
int n, sl, sr, l[N], r[N], mx, id;
inline int abs(int a){
    return a > 0 ? a : -a;
}
int main(){
    scanf("%d", &n);
    for (register int i = 1; i <= n; ++i)
        scanf("%d%d", l + i, r + i), sl += l[i], sr += r[i];
    mx = abs(sl - sr), id = 0;
    for (register int i = 1, s; i <= n; ++i){
        s = abs((sl - l[i] + r[i]) - (sr - r[i] + l[i]));
        if (s > mx) mx = s, id = i;
    }
    return printf("%d", id), 0;
}