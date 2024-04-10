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
    string s, t;
    cin >> s;
    cin >> t;
    long long n = (int)s.size();
    long long m = (int)t.size();
    vector<long long> pref(m + 1);
    pref[0] = 0;
    for (int i = 1; i <= m; i++)
        pref[i] = pref[i - 1] + t[i - 1] - '0';
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            ans += pref[m - n + i + 1] - pref[i];
        else
            ans += m - n + 1 - (pref[m - n + i + 1] - pref[i]);
    }
    cout << ans << endl;
    return 0;
}