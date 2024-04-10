#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long i64;
const int Nmax = 1005;

bool A[Nmax][Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);

    vector<int> sign = {1, -1};
    for (int i = 1; i <= K; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);

        A[x][y] = true;
        bool ok = false;
        for (int s1: sign) {
            for (int s2: sign) {
                if (A[x + s1][y] && A[x][y + s2] && A[x + s1][y + s2])
                    ok = true;
            }
        }
        if (ok) {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("0");
}