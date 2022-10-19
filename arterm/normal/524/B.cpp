#include <iostream>

using namespace std;

const int M = 1010;
const int INF = 2000000000;

int n, a[M], b[M], ans = INF;

int get(int mh) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int x = INF;
        if (a[i] <= mh) {
            x = min(b[i], x);
        }
        if (b[i] <= mh) {
            x = min(a[i], x);
        }
        if (x == INF)
            return INF;
        sum += x;
    }
    return sum * mh;
}

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
}

void kill() {
    for (int i = 0; i < n; ++i)
        ans = min(ans, min(get(a[i]), get(b[i])));
    cout << ans << "\n";
}

int main() {
    read();
    kill();
    return 0;
}