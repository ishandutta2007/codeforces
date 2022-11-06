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

vector<int> ans;

void aAns(int a, int b, int c) {
    int x[3] = {a, b, c};
    sort(x, x + 3);
    for (int i = 2; i >= 0; i--) {
        ans.push_back(x[i]);
    }
}

int main() {
    scid(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        scid(x);
        cnt[x]++;
    }
    priority_queue<pair<int, int> > q;
    for (auto& i : cnt) {
        q.push({i.second, i.first});
    }
    while (q.size() >= 3) {
        pair<int, int> x[3];
        for (int i = 0; i < 3; i++) {
            x[i] = q.top();
            q.pop();
        }
        aAns(x[0].second, x[1].second, x[2].second);
        for (int i = 0; i < 3; i++) {
            x[i].first--;
            if (x[i].first > 0) {
                q.push(x[i]);
            }
        }
    }
    cout << ans.size() / 3 << "\n";
    for (int i = 0; i < ans.size(); i += 3) {
        cout << ans[i] << " " << ans[i + 1] << " " << ans[i + 2] << "\n";
    }

    return 0;
}