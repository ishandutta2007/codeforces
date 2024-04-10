#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1000 + 5;

int N;
int x[NMAX], y[NMAX];

bool attempt() {
    int odds = 0, evens = 0;
    for (int i = 1; i <= N; ++i) {
        if ((x[i] + y[i]) % 2 == 0) {
            ++evens;
        } else {
            ++odds;
        }
    }
    if (odds > 0 && evens > 0) {
        cout << evens << endl;
        for (int i = 1; i <= N; ++i) {
            if ((x[i] + y[i]) % 2 == 0) {
                cout << i << '\n';
            }
        }
        return true;
    } else {
        return false;
    }
}

void trns() {
    for (int i = 1; i <= N; ++i) {
        int a = x[i], b = y[i];
        if ((a + b) % 2 != 0) {
            --a;
        }
        x[i] = (a + b) / 2;
        y[i] = (a - b) / 2;
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> x[i] >> y[i];
    }
    while (!attempt()) {
        trns();
    }
    return 0;
}