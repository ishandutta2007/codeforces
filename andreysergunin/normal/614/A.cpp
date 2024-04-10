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
    long long l, r, k;
    cin >> l >> r >> k;
    long long p = 1;
    int ans = 0;
    if (l == 1) {
        cout << 1 << " ";
        ans++;
    }
    while (p <= (l - 1) / k)
        p *= k;
    while (p <= r / k) {
        p *= k;
        ans++;
        cout << p << " ";
    }
    if (ans == 0)
        cout << -1;
    return 0;
}