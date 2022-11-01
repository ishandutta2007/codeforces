#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int Nmax = 100005;

pair<int, int> A[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i)
        scanf("%d%d", &A[i].first, &A[i].second);

    sort(A + 1, A + N + 1);

    int Ans = 0;

    priority_queue<int> H;
    for (int i = 1; i <= N; ++i) {
        if (!H.empty() && H.top() > A[i].second)
            ++Ans;

        H.push(A[i].second);
    }

    printf("%d\n", Ans);
}