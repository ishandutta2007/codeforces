#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int maxn = 100;
char c[maxn][maxn];

int main() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << -1 << '\n';
        exit(0);
    }
    
    int k = n;
    while (k * k > n || (n & 1) != (k & 1)) {
        k--;
    }
    
    n -= k * k;
    int m = (n / 2 + k - 1) / k + k;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            c[i][j] = '.';
        }
    }
    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            c[i][j] = 'o';
        }
    }
    
    n /= 2;
    for (int i = k; i < m; i++) {
        for (int j = 0; j < k; j++) {
            if (n == 0) {
                break;
            }
            n--;
            c[i][j] = 'o';
            c[j][i] = 'o';
        }
    }
    cout << m << '\n';
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            cout << c[i][j];
        }
        cout << '\n';
    }
}