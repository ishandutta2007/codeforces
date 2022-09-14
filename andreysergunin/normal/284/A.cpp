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

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int p;
    cin >> p;
    int ans = 0;
    for (int i = 1; i < p; i++)
        if (gcd(i, p - 1) == 1)
            ans++;
    cout << ans << endl;
    return 0;
}