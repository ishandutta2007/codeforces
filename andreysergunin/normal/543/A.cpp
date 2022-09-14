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
#include <ctime>

using namespace std;

int MAXN = 51;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, b, mod;
    cin >> n >> m >> b >> mod;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector< vector<int> > dpPrev, dpNext;
    
    dpPrev.resize(m + 1);
    dpNext.resize(m + 1);
    for (int j = 0; j <= m; j++) {
        dpPrev[j].resize(b + 1);
        dpNext[j].resize(b + 1);
    }
    
    dpPrev[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= b; k++) {
                dpNext[j][k] = dpPrev[j][k];
                if (k - a[i - 1] >= 0 && j > 0)
                    dpNext[j][k] = (dpNext[j][k] + dpNext[j - 1][k - a[i - 1]]) % mod;
            }
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= b; k++)
                dpPrev[j][k] = dpNext[j][k];
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= b; k++)
                dpNext[j][k] = 0;
    }
    int ans = 0;
    for (int i = 0; i <= b; i++)
        ans = (ans + dpPrev[m][i]) % mod;
    cout << ans << endl;
    return 0;
}