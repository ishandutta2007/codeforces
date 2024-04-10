#include <iostream>
#include <cstdio>

using namespace std;

const int Nmax = 500005;

typedef long long i64;

int A[Nmax];
int Ways[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N;
    scanf("%d", &N);

    i64 S = 0;
    for (int i = 1; i <= N; ++i) {
        scanf("%d\n", &A[i]);

        S += A[i];
    }

    if (S % 3 != 0) {
        cout << "0\n";
        return 0;
    }

    S /= 3;

    i64 S1 = 0;
    for (int i = 1; i <= N; ++i) {
        S1 += A[i];

        Ways[i] += Ways[i - 1];
        if (S1 == S) {
            ++Ways[i];
        }
    }

    S1 = 0;
    i64 ans = 0;
    for (int i = N; i > 1; --i) {
        S1 += A[i];

        if (S1 == S)
         ans += Ways[i - 2];
    }

    cout << ans << '\n';
}