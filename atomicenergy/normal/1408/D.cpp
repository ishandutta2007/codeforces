
using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;
int mxwithfirst[1000005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  
    for (int i = 0; i < 1000005; i++) {
        mxwithfirst[i] = -1;
    }
    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    vector<pair<int, int> > u;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        u.push_back({ x, y });
    }

    for (auto p : v) {
        for (auto q : u) {
            if (q.first >= p.first && q.second >= p.second)
                mxwithfirst[q.first - p.first] = max(mxwithfirst[q.first - p.first], q.second - p.second);
        }
    }

    int ans = 10000000;
    int cur = -1;

    for (int i = 1000004; i >=0; i--) {
        cur = max(cur, mxwithfirst[i]);
        ans = min(ans, i + cur + 1);
    }

    cout << ans << endl;

}