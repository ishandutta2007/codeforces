#include <iostream>

using namespace std;

int main() {
    int w;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> w;
    cout << ((w%2||w<=2) ? "NO" : "YES");
    return 0;
}