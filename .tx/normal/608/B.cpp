#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
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

int p1[222222];
int p0[222222];
int s1[222222];
int s0[222222];


int main() {
    init_cin
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '1') {
            p1[i]++;
        } else {
            p0[i]++;
        }
        if (i > 0) {
            p1[i] += p1[i - 1];
            p0[i] += p0[i - 1];
        }
    }
    for (int i = a.length() - 1; i >= 0; i--) {
        if (a[i] == '1') {
            s1[i]++;
        } else {
            s0[i]++;
        }
        if (i + 1 < a.length()) {
            s1[i] += s1[i + 1];
            s0[i] += s0[i + 1];
        }
    }
    lint ans = 0;
    for (int i = 0; i < b.length(); i++) {
        lint x = 0;
        if (b[i] == '1') {
            x = s0[0];
            if (i + 1 < a.length()) {
                x -= s0[i + 1];
            }
            if (i + a.length() > b.length()) {
                x -= p0[a.length() - (b.length() - i) - 1];
            }
        } else {
            x = s1[0];
            if (i + 1 < a.length()) {
                x -= s1[i + 1];
            }
            if (i + a.length() > b.length()) {
                x -= p1[a.length() - (b.length() - i) - 1];
            }
        }
        ans += x;
    }
    cout << ans;
    return 0;
}