#include <cstdio>
#include <cstring>
using namespace std;
const int N = 300005;
int n, cnt, l[N], r[N], b[N];
char a[N];
long long ans;
int main(){
    scanf("%d", &n);
    for (register int i = 1; i <= n; ++i){
        scanf("%s", a + 1);
        for (register int j = 1, m = strlen(a + 1), k = 0; j <= m; ++j){
            if (a[j] == '(') ++l[i], ++k;
            if (a[j] == ')') ++r[i];
            if (a[j] == ')' && k) --l[i], --r[i], --k;
        }
    }
    for (register int i = 1; i <= n; ++i){
        if (!l[i]) ans += b[r[i]];
        if (!r[i]) ++b[l[i]];
    }
    memset(b, 0, sizeof b);
    for (register int i = 1; i <= n; ++i){
        if (!r[i]) ans += b[l[i]];
        if (!l[i]) ++b[r[i]];
    }
    for (register int i = 1; i <= n; ++i)
        if (!l[i] && !r[i]) ++ans;
    return printf("%I64d", ans), 0;
}