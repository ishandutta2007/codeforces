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

bool took[1111111];

const int s = 1e6;

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        scid(x);
        took[x] = true;
    }
    vector<int> ans;
    int cp = 0;
    for (int i = 1; i <= s; i++) {
        if (took[i]) {
            if (!took[s + 1 - i]) {
                ans.push_back(s + 1 - i);
            } else {
                cp++;
            }
        }
    }
    for (int i = 1; cp > 0 && i <= s; i++) {
        if (!took[i] && !took[s + 1 - i]) {
            ans.push_back(i);
            ans.push_back(s + 1 - i);
            cp -= 2;
        }
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        printf("%d ", i);
    }

    return 0;
}