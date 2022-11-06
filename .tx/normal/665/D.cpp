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

int a[1111];
bool prime[2222222];

int main() {
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (int i = 2; i < 2222222; i++) {
        if (prime[i]) {
            for (int j = i + i; j < 2222222; j += i) {
                prime[j] = false;
            }
        }
    }

    scid(n);
    int c1 = 0;
    for (int i = 0; i < n; i++) {
        scid(x);
        a[i] = x;
        if (x == 1) {
            c1++;
        }
    }

    vector<int> ans;

    if (c1 >= 2) {
        for (int i = 0; i < n; i++) {
            if (a[i] != 1 && prime[a[i] + 1]) {
                ans.push_back(a[i]);
                break;
            }
        }
        for (int i = 0; i < c1; i++) {
            ans.push_back(1);
        }
    } else {
        for (int i = 0; ans.empty() && i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prime[a[i] + a[j]]) {
                    ans.push_back(a[i]);
                    ans.push_back(a[j]);
                    break;
                }
            }
        }
        if (ans.empty()) {
            ans.push_back(a[0]);
        }
    }

    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }


    return 0;
}