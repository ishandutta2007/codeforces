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

int a[111111];
int pr[111111];
int cnt[1 << 21];
lint ans[111111];

int main() {
    sciiid(n, m, k);
    for (int i = 1; i <= n; i++) {
        sci(a[i]);
        pr[i] = pr[i - 1] ^ a[i];
    }

    int blen = floor(sqrt(n));
    int bc = (n + blen - 1) / blen;
    vector<vector<pair<int, pair<int, int> > > > rq(bc + 1);
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        rq[x / blen].push_back({y, {x, i}});
    }
//    lint ans = 0;
    for (auto& vq : rq) {
        sort(vq.begin(), vq.end());
        memset(cnt, 0, sizeof(cnt));
        int cl = 0, cr = 0;
        lint cans = 0;
        for (auto& q : vq) {
            int ql = q.second.first - 1;
            int qr = q.first;
            for (; cr <= qr; cr++) {
                cans += cnt[pr[cr] ^ k];
                cnt[pr[cr]]++;
            }
            for (; cl < ql; cl++) {
                cnt[pr[cl]]--;
                cans -= cnt[pr[cl] ^ k];
            }
            for (; cl > ql; cl--) {
                cans += cnt[pr[cl - 1] ^ k];
                cnt[pr[cl - 1]]++;
            }
            ans[q.second.second] = cans;
//            if (k == 0) {
//                ans[q.second.second]
//            }
        }
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }



    return 0;
}