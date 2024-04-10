#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100000 + 5;

int N;
int p[NMAX];
/*bool ok() {
    for (int i = 1; i <= N; ++ i)
        if (p[p[i]] != N - i + 1)
            return false;
    return true;
}*/

int main()
{
    /*for (N = 1; N <= 10; ++ N) {
        cout << "N = " << N << " -> ";
        for (int i = 1; i <= N; ++ i)
            p[i] = i;

        bool done = false;
        do {
            if (ok()) {
                done = true;
                for (int i = 1; i <= N; ++ i)
                    cout << p[i] << " \n"[i == N];
                break;
            }
        } while (next_permutation(p + 1, p + N + 1));

        if (!done)
            cout << "-1\n";
    }*/

    cin >> N;
    int st = 1, dr = N;
    while (st + 1 < dr - 1) {
        p[st] = st + 1;
        p[st + 1] = dr;
        p[dr] = dr - 1;
        p[dr - 1] = st;

        st += 2;
        dr -= 2;
    }

    if (st == dr)
        p[st] = st;
    else if (dr + 1 != st) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 1; i <= N; ++ i)
        cout << p[i] << " \n"[i == N];
    return 0;
}