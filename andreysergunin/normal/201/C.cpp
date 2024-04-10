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
    vector<long long> a(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> a[i];
    vector<long long> dp1(n), dp2(n), dp3(n), dp4(n);
    dp1[0] = 0; dp2[0] = 0; dp3[0] = 0; dp4[0] = 0;
    for (int i = 1; i < n; i++) {
        dp4[i] = (a[i - 1] > 1 ? dp4[i - 1] + a[i - 1] - a[i - 1] % 2 : 0);
        dp3[i] = (a[i - 1] > 0 ? dp3[i - 1] + a[i - 1] - 1 + a[i - 1] % 2 : 0);
        dp3[i] = max(dp3[i], dp4[i]);
        dp2[i] = (a[i - 1] > 1 ? dp2[i - 1] + a[i - 1] - a[i - 1] % 2 : 0);
        dp2[i] = max(dp2[i], dp3[i]);
        dp1[i] = max(dp1[i - 1], dp2[i]);
    }
    cout << dp1[n - 1] << endl;
}