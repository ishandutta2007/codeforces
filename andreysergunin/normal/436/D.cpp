#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>

using namespace std;



int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> prev(n), next(n);
    
    prev[0] = -1;
    for (int i = 1; i < n; i++)
        prev[i] = (a[i] == a[i - 1] + 1 ? prev[i - 1] : i - 1);
    next[n - 1] = n;
    for (int i = n - 2; i >= 0; i--)
        next[i] = (a[i] + 1 == a[i + 1] ? next[i + 1] : i + 1);
    
    vector<int> dp1(n + 1), dp2(n + 1);
    for (int i = 0; i < n; i++) {
        int k = 0;
        dp1[i + 1] = dp2[i];
        for (int j = m - 1; j >= 0; j--) {
            if (b[j] <= a[i]) {
                k++;
                if (i - a[i] + b[j] >= 0) {
                    int u = prev[i - a[i] + b[j]] + 1;
                    dp1[i + 1] = max(dp1[i + 1], dp2[u] + k);
                }
            }
        }
        dp2[i + 1] = max(dp2[i + 1], dp2[i]);
        dp2[i + 1] = max(dp2[i + 1], dp1[i + 1]);
        k = 0;
        for (int j = 0; j < m; j++) {
            if (b[j] > a[i]) {
                k++;
                if (i - a[i] + b[j] < n) {
                    int u = next[i - a[i] + b[j]];
                    dp2[u] = max(dp2[u], dp1[i + 1] + k);
                }
            }
        }
    }
    cout << dp2[n] << endl;
    return 0;
}