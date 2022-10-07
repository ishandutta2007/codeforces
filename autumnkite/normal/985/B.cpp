#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cctype>
using namespace std;
const int N = 2005;
int n, m, cnt[N];
char a[N][N];
int main(){
    scanf("%d%d", &n, &m);
    for (register int i = 1; i <= n; ++i)
        for (register int j = 1; j <= m; ++j)
            while (!isdigit(a[i][j] = getchar()));
    for (register int i = 1; i <= n; ++i)
        for (register int j = 1; j <= m; ++j)
            cnt[j] += a[i][j] ^ '0';
    for (register int i = 1; i <= n; ++i){
        register bool bo = true;
        for (register int j = 1; j <= m; ++j)
            if (a[i][j] == '1' && cnt[j] == 1) bo = false;
        if (bo) return printf("YES"), 0;
    }
    return printf("NO"), 0;
}