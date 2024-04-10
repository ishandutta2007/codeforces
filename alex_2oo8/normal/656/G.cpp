#include<bits/stdc++.h>

using namespace std;

int f[42], n, m, k, ans = 0, i, j;//kitten

int main() {
    cin >> n >> m >> k;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            char c;
            cin >> c;

            if (c == 'Y') {
                if (++f[j] == k) ans++;
            }
        }
    
    cout << ans;
    
    return 0;
}