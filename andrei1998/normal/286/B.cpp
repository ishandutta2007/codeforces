#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1000000 + 5;

int N;
int p[2 * NMAX];

int main() {
    cin >> N;
    iota(p + 1, p + N + 1, 1);
    int st = 1, dr = N;
    for (int phase = 2; phase <= N; ++ phase, ++ st) {
        int old = 0;
        for (int i = st; i <= dr; i += phase) {
            int aux = p[i];
            p[i] = old;
            old = aux;
        }
        p[++ dr] = old;
    }

    for (int i = st; i <= dr; ++ i)
        cout << p[i] << " \n"[i == dr];
    return 0;
}