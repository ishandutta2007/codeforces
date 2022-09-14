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
    long long n, k;
    cin >> n >> k;
    if (2 * k - 1 <= n)
        cout << 2 * k - 1 << endl;
    else
        cout << (k - (n + 1) / 2) * 2;
    return 0;
}