#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 55;

int A[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int N;
    i64 M;
    cin >> N >> M;
    M--;

    for (int i = 1, l = 1, r = N, p = N - 2; i <= N; ++i, --p) {
        if (p == -1 || ((1LL << p) & M) == 0) A[l++] = i;
        else A[r--] = i;
    }

    for (int i = 1; i <= N; ++i)
        cout << A[i] << ' ';
    cout << '\n';
}