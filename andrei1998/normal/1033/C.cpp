#include <bits/stdc++.h>

// 10:29
using namespace std;

const int NMAX = 100000 + 5;
int N;
int v[NMAX];
int where[NMAX];
bool win[NMAX];

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
        where[v[i]] = i;
    }

    for (int i = N; i; --i) {
        int pos = where[i];
        win[pos] = false;
        for (int j = pos + v[pos]; j <= N; j += v[pos])
            if (!win[j] && v[j] > v[pos])
                win[pos] = true;
        for (int j = pos - v[pos]; j > 0; j -= v[pos])
            if (!win[j] && v[j] > v[pos])
                win[pos] = true;
    }

    for (int i = 1; i <= N; ++i) {
        if (win[i])
            cout << 'A';
        else
            cout << 'B';
    }
    cout << endl;
    return 0;
}