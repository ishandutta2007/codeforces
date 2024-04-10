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
    cin >> n;
    vector<long long> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    string s;
    cin >> s;
    long long st = 0;
    for (int i = 0; i < n; ++i)
        if (s[i] == 'B')
            st += p[i];
    long long ans = st;
    long long cur = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A')
            cur += p[i];
        else
            cur -= p[i];
        if (ans < st + cur)
            ans = st + cur;
    }
    cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'A')
            cur += p[i];
        else
            cur -= p[i];
        if (ans < st + cur)
            ans = st + cur;
    }
    cout << ans << endl;
    return 0;
}