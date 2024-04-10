#include <bits/stdc++.h>

using namespace std;


int main () {
    int n, k;
    cin >> n >> k;
    char a[n][n];
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int m1 = 1, m2 = 1;
    int best = 0;
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            if ( a[i][j] == '.') {
            int left = i;
            for ( int l = j; j - l + 1 <= k && l >= 0 && a[i][l] == '.'; l--) {
                left = l;
            }
            int up = i;
            for ( int u = i; i - u + 1 <= k && u >= 0 && a[u][j] == '.'; u--) {
                up = u;
            }
            int sum = 0;
            bool flag = true;
            for ( int l = left; l <= left + k - 1; l++) {
                if ( a[i][l] == '#') {
                    flag = false;
                    break;
                }
            }
            for ( int l = left; flag && l <= j && l + k - 1 < n && a[i][l + k - 1] == '.'; l++) {

                sum++;
            }
            flag = true;
            for ( int u = up; u <= up + k - 1; u++) {
                if ( a[u][j] == '#') {
                    flag = false;
                    break;
                }
            }
            for ( int u = up; u <= i && u + k - 1 < n && a[u + k - 1][j] == '.'; u++) {
                sum++;
            }

            if ( sum > best) {
                best = sum;
                m1 = i + 1;
                m2 = j + 1;
            }
        }
    }
    }

    cout << m1 << " " << m2;
    return 0;
}