#include <bits/stdc++.h>

using namespace std;

int bitcount(int x) {
    int f = 0;
    while(x > 0) {
        f += x & 1;
        x /= 2;
    }
    return f;
}

int main() {
    int n, m, k, x;
    cin >> n >> m >> k;
    vector <int> f(m);
    for (int i = 0; i < m; i++) {
        cin >> f[i];   
    }
    cin >> x;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans += (bitcount(x ^ f[i]) <= k); 
    }
    cout << ans << endl;
}