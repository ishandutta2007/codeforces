#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n & 1)
        cout << n - 9 << ' ' << 9 << '\n';
    else
        cout << n - 4 << ' ' << 4 << '\n';
    return 0;
}