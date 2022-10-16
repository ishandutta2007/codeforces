#include <iostream>

using namespace std;

const int N = 1000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << 2 * N - 1 << '\n';
    for(int i = 0; i < N; i++)
        cout << i + 1 << ' ' << 1 << ' ' << i + 1 << ' ' << 2 << '\n';
    for(int i = 1; i < N; i++)
        cout << i + 1 << ' ' << 1 << ' ' << i + 1 << ' ' << 2 << '\n';
    return 0;
}