#include <cstdio>
char a[2005], b[2005];
int n, p, bo;
int main(){
    scanf("%d%d%s", &n, &p, a + 1);
    for (register int i = 1; i <= n; ++i){
        if (a[i] != '.') b[i] = a[i];
        if (i + p > n) continue;
        if (a[i] == '.' || a[i + p] == '.'){
            if (a[i] == '.' && a[i + p] == '.') b[i] = '0', b[i + p] = '1';
            else if (a[i] == '.') b[i] = a[i + p] == '0' ? '1' : '0';
            else b[i + p] = a[i] == '0' ? '1' : '0';
            bo = 1;
            break;
        }
        else if (a[i] != a[i + p]){
            bo = 1; break;
        }
    }
    if (!bo) return printf("No"), 0;
    for (register int i = 1; i <= n; ++i)
        if (!b[i]) b[i] = a[i] != '.' ? a[i] : '0';
    return printf("%s", b + 1), 0;
}