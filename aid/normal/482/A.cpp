#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n - k - 1; i++)
        cout << i + 1 << ' ';
    int a = n - k - 1, dif = k;
    for(int i = 0; i <= k; i++, dif--) {
        cout << a + 1 << ' ';
        if(i & 1)
            a -= dif;
        else
            a += dif;
    }
    cout << '\n';
    return 0;
}