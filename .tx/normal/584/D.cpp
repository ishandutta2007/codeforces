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

bool isPrime(int x) {
    if (x == 2) {
        return true;
    }
    if (x == 1 || (x & 1) == 0) {
        return false;
    }
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

vector<int> ans;

void findSimple(int x) {
    if (isPrime(x)) {
        ans.push_back(x);
        return;
    }
    for (int i = 2; i + 1 < x; i++) {
        if (isPrime(i) && isPrime(x - i)) {
            ans.push_back(i);
            ans.push_back(x - i);
            return;
        }
    }
}

void genAns(int n) {
    if (n == 3) {
        ans.push_back(n);
        return;
    }

    if (n == 4) {
        ans.push_back(2);
        ans.push_back(2);
        return;
    }

    if (n < 1000) {
        ans.push_back(3);
        findSimple(n - 3);
        return;
    }
    int x = n - 3;
    while (!isPrime(x)) {
        x--;
    }
    ans.push_back(x);
    findSimple(n - x);
}

int main() {
    scid(n);
    genAns(n);
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }


    return 0;
}