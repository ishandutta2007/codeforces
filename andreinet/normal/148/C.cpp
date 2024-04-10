#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const int Vmax = 50005, Nmax = 105;

int A[Nmax];

void noSol() {
    cout << "-1\n";
    exit(0);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N, a, b;
    cin >> N >> a >> b;

    if (b == 0 && a > 0) {
        if (a >= N - 1) noSol();
        A[1] = 1;
        A[2] = 1;
        for (int i = 3; i <= a + 2; ++i)
            A[i] = A[i - 1] + 1;
        for (int i = a + 3; i <= N; ++i)
            A[i] = A[i - 1];

    } else {
        A[1] = 1;
        int s = A[1];
        for (int i = 2; i <= b + 1; ++i) {
            A[i] = s + 1;
            s += A[i];
            if (A[i] > Vmax) noSol();
        }
        for (int i = b + 2; i <= a + b + 1; ++i) {
            A[i] = A[i - 1] + 1;
            if (A[i] > Vmax) noSol();
        }
        for (int i = a + b + 2; i <= N; ++i)
            A[i] = A[i - 1];
    }

    for (int i = 1; i <= N; ++i)
        cout << A[i] << ' ';
    cout << endl;
}