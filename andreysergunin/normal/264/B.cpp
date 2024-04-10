#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <deque>

using namespace std;

const int MAXN = 1e5 + 10;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int d[MAXN];
    for (int i = 0; i < MAXN; i++)
        d[i] = 0;
    for (int i = 0; i < n; i++) {
        int k = a[i];
        vector<int> p;
        for (int i = 2; i * i <= k; i++) {
            if (k % i == 0) {
                p.push_back(i);
                while (k % i == 0)
                    k /= i;
            }
        }
        if (k > 1)
            p.push_back(k);
        int ans = 1;
        for (int i = 0; i < (int)p.size(); i++)
            ans = max(ans, d[p[i]] + 1);
        for (int i = 0; i < (int)p.size(); i++)
            d[p[i]] = ans;
    }
    int ans = 1;
    for (int i = 0; i < MAXN; i++)
        ans = max(ans, d[i]);
    cout << ans;
    return 0;
}