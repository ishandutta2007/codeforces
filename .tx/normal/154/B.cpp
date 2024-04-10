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

bool on[111111];
vector<int> pr[100001];

set<int> bp[100001];

int main() {
    for (int i = 2; i <= 100000; i++) {
        if (pr[i].empty()) {
            for (int j = i; j <= 100000; j += i) {
                pr[j].push_back(i);
            }
        }
    }

    int n, m;
    scanf("%d %d", &n, &m);
    while (m-- > 0) {
        char c;
        int x;
        scanf("\n%c %d", &c, &x);
        if (c == '+') {
            if (on[x]) {
                cout << "Already on";
            } else {
                bool ok = true;
                for (int p : pr[x]) {
                    if (!bp[p].empty()) {
                        cout << "Conflict with " << *bp[p].begin();
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    cout << "Success";
                    on[x] = true;
                    for (int p : pr[x]) {
                        bp[p].insert(x);
                    }
                }
            }
        } else {
            if (!on[x]) {
                cout << "Already off";
            } else {
                for (int p : pr[x]) {
                    bp[p].erase(x);
                }
                on[x] = false;
                cout << "Success";
            }
        }
        cout << "\n";
    }


    return 0;
}