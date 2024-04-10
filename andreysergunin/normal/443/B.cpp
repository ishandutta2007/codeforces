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
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = (int)s.size();
    int ans = 0;
    for (int d = 2; d <= n + k; d += 2) {
        for (int i = 0; i <= n + k - d; i++) {
            bool f = true;
            for (int j = i; j < i + d / 2; j++)
                if (!(j + d / 2 >= n) && s[j] != s[j + d / 2])
                    f = false;
            if (f)
                ans = d;
        }
    }
    cout << ans;
    return 0;
}