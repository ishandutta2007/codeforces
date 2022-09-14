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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a;
    cin >> a;
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + (s[i - 1] - '0');
    vector<long long> v(9 * n + 1);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            v[pref[j] - pref[i]]++;
    long long ans = 0;
    if (a != 0) {
        for (int i = 1; i < 9 * n + 1; i++)
            if (a % i == 0 && a / i < 9 * n + 1)
                ans += v[i] * v[a / i];
        }
    else {
        ans += v[0] * v[0];
        for (int i = 1; i < 9 * n + 1; i++)
            ans += 2 * v[0] * v[i];
    }
    cout << ans;
    return 0;
}