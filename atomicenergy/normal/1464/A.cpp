
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

map<int, int> v;
set<int> seen;

int cur;

int dfs(int x, bool chk) {
    
    int y = v[x];
    seen.insert(x);
    if (y == cur) {
        return 2;
    }
    if (seen.count(y)) return 1;
    if (!v.count(y)) return 1;
    return 1 + dfs(y, true);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    int tests;
    cin >> tests;
    for (int casenum = 1; casenum <= tests; casenum++) {
        int n, m;
        cin >> n >> m;
        v.clear();
        seen.clear();
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            v[x] = y;
        }
        
        int tot = 0;
        for (auto p : v) {
            if (p.first == p.second) continue;
            cur = p.first;
            if (!seen.count(p.first)) {
                tot += dfs(p.first, false);
            }
        }
        cout << tot << endl;
    }


}