#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int a[1111];
unordered_map<int, unordered_map<int, bool> > was;

int main() {
    scid(n);
    unordered_multiset<int> s;
    s.reserve(n);
    for (int i = 0; i < n; i++) {
        scid(x);
        a[i] = x;
        s.insert(x);
    }
    int ans = 2;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || was[a[i]][a[j]]) {
                continue;
            }
            while (!dq.empty()) {
                s.insert(dq.front());
                dq.pop_front();
            }
            dq.push_back(a[i]);
            dq.push_back(a[j]);
            s.erase(s.find(a[i]));
            s.erase(s.find(a[j]));
            int ls = a[j];
            int nx = a[i] + a[j];
            while (dq.size() >= 2 && !was[dq[0]][dq[1]]) {
                was[dq[0]][dq[1]] = true;
                while (s.find(nx) != s.end()) {
                    dq.push_back(nx);
                    s.erase(s.find(nx));
                    int t = ls + nx;
                    ls = nx;
                    nx = t;
                }
                ans = max(ans, (int) dq.size());
                s.insert(dq[0]);
                dq.pop_front();
            }
        }
    }

    cout << ans;

    return 0;
}