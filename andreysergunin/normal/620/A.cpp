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

int main() {
    long long x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long ans = max(abs(x2 - x1), abs(y2 - y1));
    cout << ans;
    return 0;
}