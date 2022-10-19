#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M 100100
#define long long long

long a[M], n, d[M];

void kill() {
    cin >> n;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        a[x + 10]++;
    }

    for (int i = 5; i < M; ++i) {
        d[i] = max(d[i - 1], a[i] * (i - 10) + d[i - 2]);
        //cout << d[i] << "\n";
    }

    cout << d[M - 1] << "\n";
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    kill();


    return 0;
}