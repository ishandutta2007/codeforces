///////////////////////////////     _LeMur_
#define _CRT_SECURE_NO_WARNINGS
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <chrono>
#include <random>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <ctime>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

const int N = 1005;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());

int n, s, d;

bitset <N> a[(1 << 20) + 2];
bitset <N> b[(1 << 10) + 2];
bitset <N> mas[33];
bitset <N> A;
int cnt[(1 << 20) + 2];

unordered_map < bitset<N>, int > mp;

int main() {
    cin >> n >> s >> d;

    for (int i = 1; i <= s; i++) {
        int c;
        scanf("%d", &c);
        mas[i] = 0;

        while (c--) {
            int a;
            scanf("%d", &a);
            mas[i][a] = 1;
        }
    }

    int x = min(s, 20);
    int y = s - x;

    cnt[0] = 0;
    for (int i = 1; i < (1 << 20); i++) {
        for (int j = 0; j < 20; j++) {
            if ((i >> j) & 1) {
                cnt[i]++;
            }
        }
    }

    ///
    b[0] = 0;
    mp[ b[0] ] = 0;
    ///

    for (int i = 1; i < (1 << x); i++) {
        int pos;
        for (int j = 0; j < x; j++) {
            if ((i >> j) & 1) {
                pos = j;
                break;
            }
        }

        b[i] = b[i ^ (1 << pos)] ^ mas[pos + 1];
        if (mp.find(b[i]) == mp.end()) {
            mp[ b[i] ] = cnt[i];
        } else {
            mp[ b[i] ] = min(mp[ b[i] ], cnt[i]);
        }
    }

    ///
    a[0] = 0;
    for (int i = 1; i < (1 << y); i++) {
        int pos;
        for (int j = 0; j < y; j++) {
            if ((i >> j) & 1) {
                pos = j;
                break;
            }
        }

        a[i] = a[i ^ (1 << pos)] ^ mas[pos + 1 + x];
    }
    ///

    while (d--) {
        int c;
        scanf("%d", &c);
        A = 0;

        while (c--) {
            int a;
            scanf("%d", &a);
            A[a] = 1;
        }

        int answ = inf;
        for (int i = 0; i < (1 << y); i++) {
            if (mp.find(A ^ a[i]) != mp.end()) {
                answ = min(answ, cnt[i] + mp[ A ^ a[i] ]);
            }
        }

        if (answ == inf) answ = -1;
        printf("%d\n", answ);
    }
    return 0;
}