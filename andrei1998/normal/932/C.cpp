#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1000000 + 5;

int v[NMAX];
int sz;

void append(int cnt) {
    for (int i = 1; i < cnt; ++ i)
        v[sz + i] = sz + i + 1;
    v[sz + cnt] = sz + 1;
    sz += cnt;
}

int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    for (int cntA = 0; cntA <= N; ++ cntA) {
        const long long int val = N - 1LL * A * cntA;
        if (val >= 0 && val % B == 0) {
            const int cntB = val / B;
            for (int i = 0; i < cntA; ++ i)
                append(A);
            for (int i = 0; i < cntB; ++ i)
                append(B);
            for (int i = 1; i <= N; ++ i)
                cout << v[i] << " \n"[i == N];
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}