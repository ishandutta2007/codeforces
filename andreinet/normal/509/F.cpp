#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long i64;
const int Nmax = 505, Mod = 1e9 + 7;

int A[Nmax];
int Dp[Nmax][Nmax];

int makeTree(int, int);

int divide(int left, int right) {
    if (left >= right) return 1;
    int& ans = Dp[left][right];
    if (ans != -1) return ans;
    ans = 0;
    for (int j = left; j <= right; ++j) {
        if (j < right && A[j + 1] < A[left]) continue;
        ans = (ans + 1LL * makeTree(left, j) * divide(j + 1, right)) % Mod;
    }
    return ans;
}

int makeTree(int left, int right) {
    return divide(left + 1, right);
}

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
        cin >> A[i];

    memset(Dp, -1, sizeof Dp);

    int ans = makeTree(1, N);
    cout << ans << '\n';
}