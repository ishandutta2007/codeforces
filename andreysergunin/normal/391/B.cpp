#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> dp(n);
    int prev[26][2];
    for (int i = 0; i < 26; i++)
        prev[i][0] = -1, prev[i][1] = -1;
    for (int i = 0; i < n; i++) {
        if (prev[s[i] - 'A'][(i + 1) % 2] != -1)
            dp[i] = dp[prev[s[i] - 'A'][(i + 1) % 2]] + 1;
        else
            dp[i] = 1;
        prev[s[i] - 'A'][i % 2] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}