/*
    I will never forget it.
*/
 
// 392699
 
#include <cstdio>
#include <cstring>
#include <vector>
 
using std::vector;
 
void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}
 
const int N = 1e5;
 
int a[N + 10], b[N + 10], c[N + 10], ans[N + 10], cnt[N + 10];
vector<int> q[N + 10];
int vis[N + 10];
 
struct OI {
    int RP, score;
} NOIWC2021, FJOI2021;
 
int main() {
    NOIWC2021.RP++, NOIWC2021.score++, FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        int n = fr(), m = fr(), pos = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) q[i].clear(), cnt[i] = 0;
        for (int i = 1; i <= n; i++) fr(a[i]);
        for (int i = 1; i <= n; i++) fr(b[i]);
        for (int i = 1; i <= m; i++) fr(c[i]);
        for (int i = 1; i <= n; i++) {
            vis[b[i]] = i;
            if (a[i] != b[i]) q[b[i]].push_back(i), cnt[b[i]]++;
        }
        for (int i = m; i; i--) {
            int col = c[i];
            if (cnt[col] == 0 && vis[col]) {
                ans[i] = vis[col];
                pos = vis[col];
                continue;
            }
            if (cnt[col] == 0 && pos == 0) {
                puts("NO");
                goto cat;
            }
            if (cnt[col] == 0) {
                ans[i] = pos;
                continue;
            }
            a[q[col][cnt[col] - 1]] = c[i];
            pos = q[col][cnt[col] - 1], ans[i] = q[col][cnt[col] - 1], cnt[col]--;
            
        }
        for (int i = 1; i <= n; i++)
            if (a[i] != b[i]) {
                puts("NO");
                goto cat;
            }
        puts("YES");
        for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
        puts("");
    cat:;
    }
    return 0;
}
/*
1
3 1
1 1 1
1 2 3
2
*/