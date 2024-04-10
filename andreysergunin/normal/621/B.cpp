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
    vector<int> a(1999), b(1999);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[x + y - 2]++;
        b[x - y + 999]++;
    }
    long long ans = 0;
    for (int i = 0; i < 1999; i++) {
        ans += (long long)a[i] * ((long long)a[i] - 1) / 2;
        ans += (long long)b[i] * ((long long)b[i] - 1) / 2;
    }
    cout << ans;
    return 0;
}