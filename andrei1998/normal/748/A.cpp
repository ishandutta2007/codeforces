#include <iostream>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    --K;

    const int l = 1 + K / (2 * M);
    K %= (2 * M);
    const int d = 1 + K / 2;

    cout << l << ' ' << d;
    if (K % 2 == 0) {
        cout << " L\n";
    } else {
        cout << " R\n";
    }
    return 0;
}