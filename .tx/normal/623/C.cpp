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

int prmn[111111];
int sfmn[111111];
int prmx[111111];
int sfmx[111111];

pair<int, int> a[111111];

lint sqdist(lint x1, lint y1, lint x2, lint y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

lint dists[6];
int pt[4][2];

int main() {
    scid(n);
    int y1 = 1e9, y2 = -1e9;
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        a[i] = {x, y};
        y1 = min(y1, y);
        y2 = max(y2, y);
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        prmn[i] = prmx[i] = a[i].second;
        if (i) {
            prmn[i] = min(prmn[i], prmn[i - 1]);
            prmx[i] = max(prmx[i], prmx[i - 1]);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        sfmn[i] = sfmx[i] = a[i].second;
        if (i + 1 < n) {
            sfmn[i] = min(sfmn[i], sfmn[i + 1]);
            sfmx[i] = max(sfmx[i], sfmx[i + 1]);
        }
    }

    lint l = -1, r = sqdist(0, y1, 0, y2);
    while (l + 1 < r) {
        lint m = (l + r) >> 1;
        int cr = 0;
        bool ok = false;
        for (int cl = 0; cl < n; cl++) {
            if (a[cl].first > 0) {
                break;
            }
            while (cr < n && abs(a[cr].first) <= abs(a[cl].first) && sqdist(a[cl].first, 0, a[cr].first, 0) <= m) {
                cr++;
            }
            while (cr > 0 && abs(a[cr - 1].first) > abs(a[cl].first)) {
                cr--;
            }
            if (cl == 0 && cr == n) {
                ok = true;
                break;
            }
            int mnx = a[cl].first;
            int mxx = a[cr - 1].first;
            int mny = 1e9, mxy = -1e9;
            if (cl) {
                mny = min(mny, prmn[cl - 1]);
                mxy = max(mxy, prmx[cl - 1]);
            }
            if (cr < n) {
                mny = min(mny, sfmn[cr]);
                mxy = max(mxy, sfmx[cr]);
            }
            pt[0][0] = mnx;
            pt[1][0] = mxx;
            pt[2][1] = mny;
            pt[3][1] = mxy;
            int t = 0;
            for (int i = 0; i < 4; i++) {
                for (int j = i + 1; j < 4; j++) {
                    dists[t++] = sqdist(pt[i][0], pt[i][1], pt[j][0], pt[j][1]);
                }
            }
            lint d = *max_element(dists, dists + t);
            if (d <= m) {
                ok = true;
                break;
            }
        }
        cr = -1;
        for (int cl = 0; cl < n; cl++) {
            if (a[cl].first <= 0) {
                continue;
            }
            while (cr + 1 < n && (abs(a[cr + 1].first) > abs(a[cl].first) || sqdist(a[cl].first, 0, a[cr + 1].first, 0) > m)) {
                cr++;
            }
            while (cr >= 0 && abs(a[cr].first) <= abs(a[cl].first) && sqdist(a[cr].first, 0, a[cl].first, 0) <= m) {
                cr--;
            }
            if (cl == n - 1 && cr == -1) {
                ok = true;
                break;
            }
            int mnx = a[cl].first;
            int mxx = a[cr + 1].first;
            int mny = 1e9, mxy = -1e9;
            if (cl + 1 < n) {
                mny = min(mny, sfmn[cl + 1]);
                mxy = max(mxy, sfmx[cl + 1]);
            }
            if (cr >= 0) {
                mny = min(mny, prmn[cr]);
                mxy = max(mxy, prmx[cr]);
            }
            pt[0][0] = mnx;
            pt[1][0] = mxx;
            pt[2][1] = mny;
            pt[3][1] = mxy;
            int t = 0;
            for (int i = 0; i < 4; i++) {
                for (int j = i + 1; j < 4; j++) {
                    dists[t++] = sqdist(pt[i][0], pt[i][1], pt[j][0], pt[j][1]);
                }
            }
            lint d = *max_element(dists, dists + t);
            if (d <= m) {
                ok = true;
                break;
            }
        }
        if (ok) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r;

    return 0;
}