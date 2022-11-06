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

bool isPrime(int x) {
    if (x == 1) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    init_cin
    string s;
    cin >> s;
    int n = s.length();
    int cntOne = 1;
    for (int i = 3; i <= n; i++) {
        if (isPrime(i) && i * 2 > n) {
            cntOne++;
        }
    }
    vector<int> cnt(26);
    int mx = 0;
    for (char c : s) {
        cnt[c - 'a']++;
        if (cnt[c - 'a'] > cnt[mx]) {
            mx = c - 'a';
        }
    }
    int cntSame = n - cntOne;
    if (cntSame > cnt[mx]) {
        cout << "NO";
        return 0;
    }
    vector<char> a;
    for (int i = 0; i < cnt[mx]; i++) {
        a.push_back((char) (mx + 'a'));
    }
    for (int i = 0; i < n; i++) {
        if (s[i] - 'a' != mx) {
            a.push_back(s[i]);
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        if (i == 1 || isPrime(i) && i * 2 > n) {
            cout << a.back();
            a.pop_back();
        } else {
            cout << (char) (mx + 'a');
        }
    }


    return 0;
}