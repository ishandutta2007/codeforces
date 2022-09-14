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
    int n, x;
    cin >> n >> x;
    vector< pair<int, int> > a[2];
    for (int i = 0; i < n; i++) {
        int t, h, m;
        cin >> t >> h >> m;
        a[t].push_back(make_pair(h, m));
    }
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    int ans[2] = {0, 0};
    for (int q = 0; q < 2; q++) {
        int k = q;
        int h = x;
        int m[2] = {0, 0};
        set< pair<int, int> > s[2];
        for ( ; ; ) {
            for (int i = 0; i < 2; i++) {
                while (m[i] < a[i].size() && a[i][m[i]].first <= h) {
                    s[i].insert(make_pair(-a[i][m[i]].second, m[i]));
                    m[i]++;
                }
            }
            if (s[k].empty())
                break;
            pair<int, int> y = *(s[k].lower_bound(make_pair(-10000, 0)));
            s[k].erase(y);
            h -= y.first;
            ans[q]++;
            k = 1 - k;
        }
    }
    cout << max(ans[0], ans[1]);
    
    return 0;
}