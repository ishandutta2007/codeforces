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
    int n, x;
    cin >> n >> x;
    int ans = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (i <= n && x / i <= n) {
                ans += 2;
                if (i * i == x)
                    ans -= 1;
            }
        }
    }
    cout << ans;
}