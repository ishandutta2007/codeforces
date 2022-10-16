#include <iostream>

using namespace std;

const int NMAX = 1000 + 5;

int sPart[NMAX * NMAX];

int main()
{
    int N, T, K, D;
    cin >> N >> T >> K >> D;

    for (int i = T; i < NMAX * NMAX; i += T)
        sPart[i] += K;

    int ansN = -1;
    for (int i = 1; i < NMAX * NMAX; ++ i) {
        sPart[i] += sPart[i - 1];
        if (ansN == -1 && sPart[i] >= N)
            ansN = i;
    }

    int ansS = -1;
    for (int i = D; i < NMAX * NMAX; ++ i) {
        int cnt = sPart[i] + sPart[i - D];
        if (ansS == -1 && cnt >= N)
            ansS = i;
    }

    if (ansN > ansS)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}