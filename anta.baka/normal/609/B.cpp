#include <bits/stdc++.h>

using namespace std;

int c[11];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        c[t]++;
    }
    int res = 0;
    for(int i = 1; i < 10; i++)
        for(int j = i + 1; j <= 10; j++)
            res += c[i]*c[j];
    cout << res;
}