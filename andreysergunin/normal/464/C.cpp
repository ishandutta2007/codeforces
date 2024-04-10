#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

const int P = 1e9 + 7;

long long p(long long a, long long b) {
    if (b == 0)
        return 1;
    long long x = p(a, b / 2);
    if (b % 2 == 0)
        return (x * x) % P;
    else
        return ((x * x) % P) * a % P;
}

int main() {
    int n;
    string s;
    cin >> s;
    cin >> n;
    vector<int> d(n);
    vector<string> t(n);
    for (int i = 0; i < n; i++) {
        string u;
        cin >> u;
        d[i] = u[0] - '0';
        t[i] = "";
        for (int j = 3; j < (int)u.size(); j++)
            t[i] += u[j];
    }
    long long ansd[10];
    long long l[10];
    for (int i = 0; i < 10; i++) {
        ansd[i] = i;
        l[i] = 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        long long x = 0, y = 0;
        for (int j = 0; j < (int)t[i].size(); j++) {
            x = ((p(10, l[t[i][j] - '0']) * x) % P + ansd[t[i][j] - '0']) % P;
            y = (y + l[t[i][j] - '0']) % (P - 1);
        }
        ansd[d[i]] = x;
        l[d[i]] = y;
    }
    long long ans = 0;
    for (int i = 0; i < (int)s.size(); i++)
        ans = ((p(10, l[s[i] - '0']) * ans) % P + ansd[s[i] - '0']) % P;
    cout << ans << endl;
    return 0;
}