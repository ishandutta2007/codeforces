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
    int n;
    cin >> n;
    map<int, long long> mx, my;
    map<pair<int, int>, long long> mp;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        ++mx[x[i]];
        ++my[y[i]];
        ++mp[make_pair(x[i], y[i])];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += mx[x[i]] * (mx[x[i]] - 1) / 2;
        ans += my[y[i]] * (my[y[i]] - 1) / 2;
        ans -= mp[make_pair(x[i], y[i])] * (mp[make_pair(x[i], y[i])] - 1) / 2;
        mx[x[i]] = 0;
        my[y[i]] = 0;
        mp[make_pair(x[i], y[i])] = 0;
    }
    cout << ans << endl;
    return 0;
}