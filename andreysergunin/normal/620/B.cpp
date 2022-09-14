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

int dig[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = a; i <= b; i++) {
        int p = i;
        while (p > 0) {
            ans += dig[p % 10];
            p /= 10;
        }
    }
    cout << ans;
}