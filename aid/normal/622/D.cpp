#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int lastev = ((n & 1)? n - 1 : n - 2), lastodd = ((n & 1)? n - 2 : n - 1);
    for(int i = lastev; i >= 0; i -= 2)
        cout << n - i << ' ';
    for(int i = 2; i <= lastev; i += 2)
        cout << n - i << ' ';
    cout << n << ' ';
    for(int i = lastodd; i > 0; i -= 2)
        cout << n - i << ' ';
    for(int i = 1; i <= lastodd; i += 2)
        cout << n - i << ' ';
    cout << '\n';
    return 0;
}