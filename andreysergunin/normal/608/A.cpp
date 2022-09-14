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
    int n, s;
    cin >> n >> s;
    int ans = s;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ans = max(ans, a + b);
    }
    cout << ans;
    return 0;
}