#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    if(k > n) {
        cout << -1 << '\n';
        return 0;
    }
    if(n == 1) {
        cout << "a\n";
        return 0;
    }
    if(k == 1) {
        cout << -1 << '\n';
        return 0;
    }
    for(int i = 0; i < n - k + 2; i++)
        cout << ((i & 1)? 'b' : 'a');
    for(int i = 2; i < k; i++)
        cout << char('a' + i);
    cout << '\n';
    return 0;
}