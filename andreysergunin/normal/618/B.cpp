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

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<vector <int> > a;
    a.resize(n);
    for (int i = 0; i < n; i++)
        a[i].resize(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    vector<int> ans(n);
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < n; i++) {
            if (ans[i] != 0)
                continue;
            bool f = true;
            for (int j = 0; j < n; j++) {
                if (i != j && a[i][j] != k && ans[j] == 0)
                    f = false;
            }
            if (f) {
                ans[i] = k;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}