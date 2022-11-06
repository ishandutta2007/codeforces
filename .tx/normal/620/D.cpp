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

int a[2222];
int b[2222];

int main() {
    scid(n);
    lint sa = 0;
    for (int i = 0; i < n; ++i) {
        sci(a[i]);
        sa += a[i];
    }
    scid(m);
    lint sb = 0;
    for (int i = 0; i < m; i++) {
        sci(b[i]);
        sb += b[i];
    }
    lint mv = abs(sa - sb);
    int aa[2];
    int ab[2];
    int ax = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            lint nsa = sa - a[i] + b[j];
            lint nsb = sb - b[j] + a[i];
            if (abs(nsa - nsb) < mv) {
                mv = abs(nsa - nsb);
                ax = 1;
                aa[0] = i;
                ab[0] = j;
            }
        }
    }

    unordered_map<lint, pair<int, int> > ssp;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            ssp[b[i] + b[j]] = {i, j};
        }
    }

    vector<lint> sv;
    sv.reserve(ssp.size());
    for (auto& i : ssp) {
        sv.push_back(i.first);
    }
    sort(sv.begin(), sv.end());

    int svlen = sv.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cs = a[i] + a[j];
            lint tsb = (sb - sa) / 2 + cs;
            int it = lower_bound(sv.begin(), sv.end(), tsb) - sv.begin();
            if (it != 0) {
                --it;
            }
            for (int k = 0; k < 2 && it < svlen; ++k, ++it) {
                lint cb = sv[it];
                lint nsa = sa - cs + cb;
                lint nsb = sb - cb + cs;
                if (abs(nsa - nsb) < mv) {
                    mv = abs(nsa - nsb);
                    ax = 2;
                    auto &tp = ssp[cb];
                    aa[0] = i;
                    ab[0] = tp.first;
                    aa[1] = j;
                    ab[1] = tp.second;
                }
            }
        }
    }

    cout << mv << "\n";
    cout << ax << "\n";
    for (int i = 0; i < ax; i++) {
        cout << aa[i] + 1 << " " << ab[i] + 1 << "\n";
    }

    return 0;
}