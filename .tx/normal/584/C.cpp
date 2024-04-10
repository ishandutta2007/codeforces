#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).end()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

char ne(char a, char b) {
    for (char i = 'a'; i <= 'c'; i++) {
        if (i != a && i != b) {
            return i;
        }
    }
    return -1;
}

int main() {
    init_cin();
    int n, d;
    cin >> n >> d;
    string s, t;
    cin >> s >> t;
    int cd = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            cd++;
        }
    }
    int cs = n - cd;
    if ((cd + 1) / 2 > d) {
        cout << -1;
        return 0;
    }
    int inSame = max(0, d - cd);
    d -= inSame;
    int inDiff = 2 * d - cd;
    if (inSame > cs) {
        inDiff += inSame - cs;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) {
            if (inSame > 0) {
                cout << (s[i] == 'a' ? 'b' : 'a');
                inSame--;
            } else {
                cout << s[i];
            }
        } else {
            if (inDiff > 0) {
                cout << ne(s[i], t[i]);
                inDiff--;
            } else {
                if (cd % 2 == 0) {
                    cout << s[i];
                } else {
                    cout << t[i];
                }
                cd --;
            }
        }
    }

    return 0;
}