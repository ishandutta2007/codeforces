#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long i64;
const int Nmax = 105, Inf = 0x3f3f3f3f;

int A[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    int minval = Inf, maxval = -Inf;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        minval = min(minval, A[i]);
        maxval = max(maxval, A[i]);
    }

    if (maxval - minval > K) {
        puts("NO");
        return 0;
    }

    puts("YES");
    for (int i = 1; i <= N; ++i) {
        int p = 0;
        while (A[i]-- > 0) {
            printf("%d ", p + 1);
            p = (p + 1) % K;
        }
        puts("");
    }
}