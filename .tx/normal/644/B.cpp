#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

lint ans[222222];

struct req {
    lint t, d;
    int id;
};

int main() {
    sciid(n, b);
    queue<req> q;
    lint ct = 0;
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < n; i++) {
        sciid(t, d);
        while (!q.empty() && max(ct, q.front().t) <= t) {
            req rq = q.front();
            q.pop();
            ct = max(ct, rq.t) + rq.d;
            ans[rq.id] = ct;
        }
        if (q.size() < b) {
            q.push(req{t, d, i});
        }
    }
    while (!q.empty()) {
        req rq = q.front();
        q.pop();
        ct = max(ct, rq.t) + rq.d;
        ans[rq.id] = ct;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}