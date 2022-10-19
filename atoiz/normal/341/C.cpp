#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;
int add(int a, int b) { return ((a += b) >= mod ? a - mod : a); }
int sub(int a, int b) { return ((a -= b) < 0 ? a + mod : a); }
int mul(int a, int b) { return (long long) a * b % mod; }

const int MAXN = 2004;
int c[MAXN][MAXN], p[MAXN], n, f[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) c[i][0] = 1;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
    f[0] = 1;
    for (int i = 1; i <= n; ++i) f[i] = mul(f[i - 1], i);
    for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
    for (int i = 1; i <= n; ++i) if (p[i] == i) return 0 * puts("0");

    vector<bool> flag(n + 1, 1); flag[0] = 0;
    for (int i = 1; i <= n; ++i) if (p[i] >= 0) flag[p[i]] = 0, flag[i] = 0;
    int cnt_possible = count(flag.begin(), flag.end(), 1), cnt_neg = count(p + 1, p + 1 + n, -1);

    int ans = 0;
    for (int i = 0; i <= cnt_possible; ++i) {
        int tmp = mul(c[cnt_possible][i], f[cnt_neg - i]);
        if (i & 1) ans = sub(ans, tmp);
        else ans = add(ans, tmp);
    }
    cout << ans << endl;
}