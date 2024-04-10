#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long i64;

i64 A[20][20];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i)
        A[i][1] = A[1][i] = 1;

    i64 maxval = 1;
    for (int i = 2; i <= N; ++i) {
        for (int j = 2; j <= N; ++j) {
            A[i][j] = A[i - 1][j] + A[i][j - 1];
            maxval = max(maxval, A[i][j]);
        }
    }

    cout << maxval << '\n';
}