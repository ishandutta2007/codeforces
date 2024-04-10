#include <bits/stdc++.h>

using namespace std;
int a[555][555];
int mx[555][555];
int n, m;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            mx[i][j] = a[i][j];
        }
    }
    for(int i = n; i >= 1; i--) {
        for(int j = m; j >= 1; j--) {
            if(a[i][j] == 0) {
                mx[i][j] = min(mx[i+1][j] - 1, mx[i][j+1] - 1);
            }
        }
    }
    long long cur = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            a[i][j] = mx[i][j];
            cur += a[i][j];
            if(a[i][j] <= 0) {
                cout << -1 << "\n";
                return 0;
            }
            if(i > 1 && a[i][j] <= a[i-1][j]) {
                cout << -1 << "\n";
                return 0;
            }
            if(j > 1 && a[i][j] <= a[i][j-1]) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    cout << cur << "\n";
}