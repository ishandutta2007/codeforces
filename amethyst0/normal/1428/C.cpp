#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int

const int maxn = (int)2e5 + 10;
char s[maxn];

int main() {
    int t;

    cin >> t;

    while (t--) {
        scanf("%s", s);
        int n = 0;
        while (s[n]) {
            n++;
        }

        vector <char> c;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                c.push_back(s[i]);
            }
            else {
                if (c.empty()) {
                    c.push_back(s[i]);
                }
                else {
                    c.pop_back();
                }
            }
        }

        printf("%d\n", (int)c.size());
    }
}