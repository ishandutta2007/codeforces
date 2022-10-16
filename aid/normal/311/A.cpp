#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    if(n * (n - 1) / 2 <= k)
        cout << "no solution\n";
    else {
        for(int i = 0; i < n; i++)
            cout << 0 << ' ' << i << '\n';
    }
    return 0;
}