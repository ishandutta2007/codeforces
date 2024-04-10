#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define M 400010

using namespace std;

typedef long long ll;

ll n, m, Ans[100010];

map <int, int> hsh[100010];

int main() {
    scanf("%lld%lld", &n, &m);
    if(n * (n - 1) / 2 == m) {
        puts("NO");
        return 0;
    }
    for(int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        hsh[a][b] = 1;
        hsh[b][a] = 1;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(!hsh[i][j] && i != j) {
                puts("YES");
                int cnt = 3;
                for(int k = 1; k <= n; k++) if(k != i && k != j) Ans[k] = cnt++;
                Ans[i] = 1;
                Ans[j] = 2;
                for(int k = 1; k <= n; k++) printf("%lld%c", Ans[k], " \n"[k == n]);
                Ans[j] = 1;
                for(int k = 1; k <= n; k++) printf("%lld%c", Ans[k], " \n"[k == n]);
                return 0;
            }
}