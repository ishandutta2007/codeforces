#include <bits/stdc++.h>
 
using namespace std;

int main (int argc, char const *argv[]) {
    int n, d = 1e9 + 10, x, y; 
    cin >> n;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            int j = n/i;
            if (j - i < d) {
                d = j - i;
                x = i, y = j;
            }
        }
    }
    cout << x << " " << y << '\n';
    return 0;
}