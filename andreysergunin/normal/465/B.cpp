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
    int ans = 0;
    int prev = 0;
    for (int i = 0; i < n; i++) {
        int next;
        cin >> next;
        ans += next;
        if (next == 1 && prev == 0)
            ans += 1;
        prev = next;
    }
    if (ans > 0)
        ans--;
    cout << ans;
    return 0;
}