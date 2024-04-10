#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    vector<int> A[3];
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i) {
        int x;
        scanf("%d", &x);
        A[x - 1].push_back(i);
    }

    int ans = min({A[0].size(), A[1].size(), A[2].size()});
    printf("%d\n", ans);
    for (int i = 0; i < ans; ++i) {
        printf("%d %d %d\n", A[0][i], A[1][i], A[2][i]);
    }
}