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

vector<int> g[555555];
char s[555555];

//vector<int> bh[555555][26];
vector<int> bh[555555];
//vector<int> cnt[555555][26];
int h[555555];
int tin[555555];
int tout[555555];
int tim = 0;

vector<pair<int, int> > htins[555555];
vector<pair<int, int> > htouts[555555];

void dfs(int v, int p, int ch) {
    tin[v] = tim++;
    h[v] = ch;
//    bh[ch].push_back(v);
//    for (char c = 'a'; c <= 'z'; c++) {
//        if (s[v] == c) {
//            cnt[ch][c - 'a'].push_back(1);
//        } else {
//            cnt[ch][c - 'a'].push_back(0);
//        }
//    }
//    bh[ch][s[v] - 'a'].push_back(v);
    bh[ch].push_back(v);
    for (int i : g[v]) {
        if (i != p) {
            dfs(i, v, ch + 1);
        }
    }
    tout[v] = tim++;
}

int ans[555555];

int main() {
    sciid(n, m);
    for (int i = 1; i < n; i++) {
        scid(x);
        --x;
        g[x].push_back(i);
        g[i].push_back(x);
    }
    scanf("%s", s);

    dfs(0, -1, 0);
//    for (int i = 0; i < 555555; i++) {
//        for (int j = 0; j < 26; j++) {
//            for (int k = 1; k < cnt[i][j].size(); k++) {
//                cnt[i][j][k] += cnt[i][j][k - 1];
//            }
//        }
//    }

    for (int i = 0; i < m; i++) {
        sciid(v, qh);
        --v; --qh;
        if (h[v] > qh) {
            continue;
        }
        int ntin = tin[v] + (qh - h[v]);
        int ntout = tout[v] - (qh - h[v]);
        htins[qh].push_back({ntin, i});
        htouts[qh].push_back({ntout, i});
    }

    for (int qh = 0; qh < 555555; qh++) {
        auto& tins = htins[qh];
        sort(tins.begin(), tins.end());
        auto& touts = htouts[qh];
        sort(touts.begin(), touts.end());
        int iIn = 0;
        int iOut = 0;
        int cXor = 0;
        for (int t : bh[qh]) {
            int cTin = tin[t];
            int cTout = tout[t];
            while (iIn < tins.size() && tins[iIn].first <= cTin) {
                ans[tins[iIn].second] = cXor;
                iIn++;
            }
            while (iOut < touts.size() && touts[iOut].first < cTout) {
                ans[touts[iOut].second] ^= cXor;
                iOut++;
            }
            cXor ^= 1 << (s[t] - 'a');
        }
        while (iIn < tins.size()) {
            ans[tins[iIn].second] = cXor;
            iIn++;
        }
        while (iOut < touts.size()) {
            ans[touts[iOut].second] ^= cXor;
            iOut++;
        }
    }

    for (int i = 0; i < m; i++) {
        if (__builtin_popcount(ans[i]) <= 1) {
            puts("Yes");
        } else {
            puts("No");
        }
    }

//    while (m-- > 0) {
//        sciid(v, qh);
//        --v; --qh;
//        if (h[v] > qh) {
//            puts("Yes");
//            continue;
//        }
//        int cOdd = 0;
//        for (int c = 0; cOdd <= 1 && c < 26; c++) {
//            vector<int> &a = bh[qh][c];
//            int l = -1, r = a.size();
//            int ntin = tin[v] + (qh - h[v]);
//            while (l + 1 < r) {
//                int md = (l + r) >> 1;
//                if (tin[a[md]] < ntin) {
//                    l = md;
//                } else {
//                    r = md;
//                }
//            }
//            int ql = r;
//
//            l = -1, r = a.size();
//            int ntout = tout[v] - (qh - h[v]);
//            while (l + 1 < r) {
//                int md = (l + r) >> 1;
//                if (tout[a[md]] <= ntout) {
//                    l = md;
//                } else {
//                    r = md;
//                }
//            }
//
//            int qr = l;
//
//            if ((qr - ql + 1) & 1) {
//                cOdd++;
//            }
//        }
//
//        if (cOdd <= 1) {
//            puts("Yes");
//        } else {
//            puts("No");
//        }
//    }



    return 0;
}