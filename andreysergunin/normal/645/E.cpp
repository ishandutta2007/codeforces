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

const int P = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    string t;
    cin >> t;
    int m = (int)t.size();
    vector<int> a(k);
    vector<int> p(k, -1);
    for (int i = 0; i < m; i++) {
        int c = t[i] - 'a';
        p[c] = i;
        a[c] += 1;
        if (a[c] >= P)
            a[c] -= P;
        for (int j = 0; j < k; j++)
            if (j != c) {
                a[c] += a[j];
                if (a[c] >= P)
                    a[c] -= P;
            }
    }
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 1; j < k; j++)
            if (p[c] > p[j])
                c = j;
        p[c] = i + m;
        a[c] += 1;
        if (a[c] >= P)
            a[c] -= P;
        for (int j = 0; j < k; j++)
            if (j != c) {
                a[c] += a[j];
                if (a[c] >= P)
                    a[c] -= P;
            }
    }
    int ans = 1;
    for (int i = 0; i < k; i++) {
        ans += a[i];
        if (ans >= P)
            ans -= P;
    }
    cout << ans << endl;
    return 0;
}