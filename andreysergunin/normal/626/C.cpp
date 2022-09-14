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
    int n, m;
    cin >> n >> m;
    int x = 2 * n, y = 3 * m;
    int k = 1;
    while (6 * k <= x && 6 * k <= y) {
        if (x + 2 <= y + 3)
            x += 2;
        else
            y += 3;
        k += 1;
    }
    cout << max(x, y);
    return 0;
}