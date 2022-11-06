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

int ca = 0;

int t = 62;

bool ask(int x) {
//    ca++;
    cout << x << "\n";
    cout.flush();
    string res;
    cin >> res;
    return res == "yes";
//    return t % x == 0;
}

bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    init_cin;
    vector<int> p;
    int cnt = 0;
    for (int i = 2; i <= 50; i++) {
        if (isPrime(i)) {
            if (ask(i)) {
                cnt++;
            }
            if (i * i <= 100 && ask(i * i)) {
                cout << "composite";
                return 0;
            }
        }
    }

    if (cnt <= 1) {
        cout << "prime";
    } else {
        cout << "composite";
    }


    return 0;
}