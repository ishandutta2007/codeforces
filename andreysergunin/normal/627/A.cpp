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
    long long s, x;
    cin >> s >> x;
    if (s < x) {
        cout << 0;
        return 0;
    }
    long long q = s - x;
    if (q % 2 == 1) {
        cout << 0;
        return 0;
    }
    q /= 2;
    if ((q & x) != 0) {
        cout << 0;
        return 0;
    }
    long long k = 0;
    long long y = x;
    while (y > 0) {
        if (y % 2 == 1)
            k++;
        y /= 2;
    }
    long long ans = (long long)1 << k;
    if ((s ^ 0) == x)
        ans -= 2;
    cout << ans;
    return 0;
}