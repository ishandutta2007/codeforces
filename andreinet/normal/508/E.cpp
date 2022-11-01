#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long i64;
const int Nmax = 605;

pair<int, int> A[Nmax];
int nextState[Nmax][Nmax];

char Ans[Nmax];

void build(int pos, int left, int right) {
    if (left > right) return;
    int k = nextState[left][right];
    Ans[pos] = '(';
    Ans[pos + 2 * k + 1] = ')';
    if (left == right) return;
    build(pos + 1, left + 1, left + k);
    build(pos + 2 * k + 1 + 1, left + k + 1, right);
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

    for (int i = 1; i <= N; ++i) {
        cin >> A[i].first >> A[i].second;
        if (A[i].first % 2 == 0) ++A[i].first;
        if (A[i].second % 2 == 0) --A[i].second;
        if (A[i].first > A[i].second) {
            puts("IMPOSSIBLE");
            return 0;
        }
    }

    memset(nextState, -1, sizeof nextState);
    nextState[N + 1][N] = 0;
    for (int i = N; i > 0; --i) {
        nextState[i][i - 1] = 0;
        for (int j = i; j <= N; ++j) {
            for (int k = A[i].first / 2; k <= A[i].second / 2 && i + k <= j; ++k) {
                if (nextState[i + 1][i + k] != -1 && nextState[i + k + 1][j] != -1) {
                    nextState[i][j] = k;
                    break;
                }
            }
        }
    }

    if (nextState[1][N] == -1) {
        puts("IMPOSSIBLE");
    } else {
        build(0, 1, N);
        cout << Ans << '\n';
    }
}