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
    int n, k;
    cin >> n >> k;
    if ((k == 1 && n > 1) || (n < k)) {
        cout << -1 << endl;
        return 0;
    }
    if (k == 1 && n == 1) {
        cout << 'a' << endl;
        return 0;
    }
    for (int i = 0; i < n - k + 2; i++)
        cout << (char)('a' + (i % 2));
    for (int i = 2; i < k; i++)
        cout << (char)('a' + i);
    cout << endl;
    return 0;
}