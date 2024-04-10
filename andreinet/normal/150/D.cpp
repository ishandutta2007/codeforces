#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 155, Inf = 0x3f3f3f3f;

char A[Nmax];
int points[Nmax];
int dp1[Nmax][Nmax], dp2[Nmax][Nmax], dp3[Nmax][Nmax][Nmax];

int solveAll(int, int);

int solvePal(int left, int right, int len) {
    if (left > right && len == 0) return 0;
    if (len == 0) return solveAll(left, right);
    if (len > right - left + 1) return -Inf;

    int& ans = dp3[left][right][len];
    if (ans != -Inf - 1) return ans;
    ans = -Inf;

    if (len == 1) {
        for (int i = left; i <= right; ++i)
            ans = max(ans, solveAll(left, i - 1) + solveAll(i + 1, right));
    } else {
        for (int i = left; i < right; ++i)
            ans = max(ans, solveAll(left, i) + solvePal(i + 1, right, len));
        for (int i = right; i > left; --i)
            ans = max(ans, solvePal(left, i - 1, len) + solveAll(i, right));
        
        if (A[left] == A[right])
            ans = max(ans, solvePal(left + 1, right - 1, len - 2));
    }

    return ans;
}

int solveAll(int left, int right) {
    if (left > right) return 0;
    int& ans = dp2[left][right];
    if (ans != -Inf - 1) return ans;
    ans = -Inf;

    for (int i = 1; i <= right - left + 1; ++i)
        if (points[i] != -1) {
            //cerr << i << ' ' << points[i] << '\n';
            ans = max(ans, solvePal(left, right, i) + points[i]);
        }

    return ans;
}

int solve(int left, int right) {
    if (left > right) return 0;
    int& ans = dp1[left][right];
    if (ans != -Inf - 1) return ans;
    ans = max(0, solveAll(left, right));

    for (int i = left; i < right; ++i)
        ans = max(ans, solve(left, i) + solve(i + 1, right));
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i)
        cin >> points[i];

    cin >> (A + 1);

    memset(dp1, -Inf - 1, sizeof dp1);
    memset(dp2, -Inf - 1, sizeof dp2);
    memset(dp3, -Inf - 1, sizeof dp3);
    cout << solve(1, N) << '\n';
}