#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a = 1e9 + 1;
        for (int j = 0; j < m; j++) {
            int c;
            cin >> c;
            a = min(a, c);
        }
        ans = max(a, ans);
    }
    cout << ans;
    
    return 0;
}