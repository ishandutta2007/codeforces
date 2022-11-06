#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int main() {
    scid(n);
    rveid(a, n);
    int ans = 1;
    deque<int> mx;
    deque<int> mn;
    int i = 0;
    mx.push_back(a[0]);
    mn.push_back(a[0]);
    for (int j = 1; j < n; j++) {
        int x = a[j];
        while (!mx.empty() && mx.back() < x) {
            mx.pop_back();
        }
        mx.push_back(x);
        while (!mn.empty() && mn.back() > x) {
            mn.pop_back();
        }
        mn.push_back(x);
        while (mx.front() - mn.front() > 1) {
            x = a[i++];
            if (mx.front() == x) {
                mx.pop_front();
            }
            if (mn.front() == x) {
                mn.pop_front();
            }
        }
        ans = max(ans, j - i + 1);
    }
    cout << ans;

    return 0;
}