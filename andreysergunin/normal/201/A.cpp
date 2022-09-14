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
    int x;
    cin >> x;
    if (x == 3) {
        cout << 5 << endl;
        return 0;
    }
    int n = 1;
    while ((n * n + 1) / 2 < x)
        n += 2;
    cout << n << endl;
    
    return 0;
}