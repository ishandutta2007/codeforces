#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

#define ll long long
#define rep(i, a, b) for (register int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (register int i = a, end = b; i >= end; i--)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define fst first
#define snd second
#define pii pair<int, int>

inline int read() {
    int w = 0, f = 1; char c;
    while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
    while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
    return w * f;
}

const int maxn = 3000 + 5;

int N, M[maxn][maxn];

int main() {
    N = read();
    rep(i, 1, N)
        rep(j, 1, N)
            M[i][j] = read();

    printf("%d ", M[1][1] = (int)sqrt(1ll*M[2][1]*M[3][1]/M[2][3]));
    rep(i, 2, N)
        printf("%d ", M[i][i] = M[i][i-1] / M[i-1][i-1]);
    
    return 0;
}