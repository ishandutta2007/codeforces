#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define mod 1000000007ll

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    
    int m = 6 * n - 1;
    cout << m * k << "\n";
    for (int i = 1; i < m; i += 6) {
        int third = i + 1;
        if (third % 3 == 0)
            third += 2;
        cout << i * k << " " << (i + 2) * k << " ";
        cout << (i + 4) * k << " " << third * k << "\n";
    }
    return 0;
}