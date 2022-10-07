#include <cstdio>
#include <cstring>
using namespace std;
char a[105];
int n, ans = 0, k = 0;
inline int max(int a, int b){
    return a > b ? a : b;
}
int main(){
    scanf("%s", a + 1), n = strlen(a + 1);
    for (register int i = 1; i <= n; ++i)
        if (a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U' || a[i] == 'Y')
            ans = max(ans, i - k), k = i;
    ans = max(ans, n + 1 - k);
    return printf("%d", ans), 0;
}