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
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<int> ans(m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'U')
                if (i % 2 == 0)
                    ans[j]++;
            if (s[i][j] == 'L')
                if (j - i >= 0)
                    ans[j - i]++;
            if (s[i][j] == 'R')
                if (j + i < m)
                    ans[i + j]++;
        }
    for (int i = 0; i < m; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}