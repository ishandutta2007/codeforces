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
#include <queue>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int u = 1, v = 2;
    vector< vector<int> > ans(a);
    for (int i = 0; i < a; i++) {
        ans[i].resize(b);
        for (int j = 0; j < b; j++) {
            if ((i + j) % 2 == 0 && u <= n) {
                ans[i][j] = u;
                u += 2;
            }
            if ((i + j) % 2 == 1 && v <= n) {
                ans[i][j] = v;
                v += 2;
            }
        }
    }
    if (u <= n || v <= n) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}