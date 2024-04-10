#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <ctime>

using namespace std;

int main() {
    int n;
    long long p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s == "half")
            a[i] = 0;
        else
            a[i] = 1;
    }
    long long cur = 0;
    long long ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        cur *= 2;
        if (a[i] == 1) {
            cur += 1;
            ans -= p / 2;
        }
    }
    ans += p * cur;
    cout << ans << endl;
    return 0;
}