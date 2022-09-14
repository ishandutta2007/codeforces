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
    int n;
    cin >> n;
    long long m = 1e9 + 1;
    long long s = 0;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        s += a;
        if (a % 2 == 1 && a < m)
            m = a;
    }
    if (s % 2 == 1)
        s -= m;
    cout << s << endl;
    return 0;
}