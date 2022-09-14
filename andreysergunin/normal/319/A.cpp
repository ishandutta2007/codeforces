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

const int P = 1e9 + 7;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    int n = (int)s.size();
    long long ans = 0;
    vector<long long> p(n + 1);
    p[0] = 1;
    for (int i = 1; i <= n; i++)
        p[i] = (p[i - 1] * 2) % P;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            long long k = (p[n - i - 1] * p[n - i - 1]) % P;
            k = (k * p[i]) % P;
            ans = (ans + k) % P;
        }
    }
    cout << ans << endl;
}