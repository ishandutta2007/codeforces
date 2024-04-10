#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n & 1) {
        for(int i = 0; i < n; i++)
            cout << i << ' ';
        cout << '\n';
        for(int i = 0; i < n; i++)
            cout << i << ' ';
        cout << '\n';
        for(int i = 0; i < n; i++)
            cout << (i + i) % n << ' ';
        cout << '\n';
    }
    else
        cout << -1 << '\n';
    return 0;
}