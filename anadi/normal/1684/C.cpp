#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
#define st first
#define nd second
#define PII pair <int, int>
 
const int N = 1'000'007;
const int MOD = 1'000'000'007;
const ll INF = 1LL * MOD * MOD;
 
int n, m;
vector <int> in[N];
 
void solve()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        in[i].resize(m);
        for (auto &v: in[i]) {
            scanf("%d", &v);
        }
    }
 
    int scol = -1, ecol = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (in[i][j] < in[i][j - 1]) {
                scol = j - 1, ecol = j;
                for (int k = j - 1; k >= 0; --k) {
                    if (in[i][k] >= in[i][scol]) {
                        scol = k;
                    }
                }

                for (int k = j + 1; k < m; ++k) {
                    if (in[i][k] <= in[i][ecol]) {
                        ecol = k;
                    }
                }
 
                break;
            }
        }
 
        if (scol != -1) {
            break;
        }
    }
 
    if (scol == -1) {
        puts("1 1");
        return;
    }
 
    for (int i = 1; i <= n; ++i) {
        swap(in[i][scol], in[i][ecol]);
        for (int j = 1; j < m; ++j) {
            if (in[i][j] < in[i][j - 1]) {
                puts("-1");
                return;
            }
        }
    }
 
    printf("%d %d\n", scol + 1, ecol + 1);
}
 
int main()
{
    int cases = 1;
    scanf("%d", &cases);
 
    while (cases--) {
        solve();
    }
 
    return 0;
}