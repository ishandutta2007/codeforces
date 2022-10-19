#include <bits/stdc++.h>

using namespace std;

const int M = 1000100;

int d[M], n;
bool a[M];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x] = true;
    }
}

void kill() {
    for (int i = M - 1; i >= 1; --i)
        if (a[i]) {
            d[i] = 1;
            for (int j = i + i; j < M; j += i)
                d[i] = max(d[i], d[j] + 1);
        }
    cout << (*max_element(d, d + M)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    read();
    kill();
    return 0;
}