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

long long ans = 0;

void gcd(long long a, long long b) {
    if (b == 0)
        return;
    ans += a / b;
    gcd(b, a % b);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long a, b;
    cin >> a >> b;
    gcd(a, b);
    cout << ans;
}