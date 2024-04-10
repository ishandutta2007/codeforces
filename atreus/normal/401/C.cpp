#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    if (2 * n + 2 < m){
        cout << -1;
        return 0;
    }
    if (m + 1 < n){
        cout << -1 << endl;
        return 0;
    }
    if (n > m){
        while (m > 0){
            cout << "01";
            m--;
        }
        cout << 0 << endl;
        return 0;
    }
    while (m > n && n > 0){
        cout << 110;
        m -= 2;
        n -= 1;
    }
    while (n > 0){
        cout << 10;
        m --;
        n --;
    }
    while (m > 0){
        cout << 1;
        m --;
    }
    return 0;
}