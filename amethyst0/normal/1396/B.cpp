#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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
#define mp make_pair

const int maxn = 110;
int v[maxn];

int main() {
    int t;

    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int s = 0;

        for (int i = 0; i < n; i++) {
            cin >> v[i];
            s += v[i];
        }

        sort(v, v + n);
        if (v[n - 1] > s - v[n - 1]) {
            cout << "T\n";
        }
        else {
            if (s % 2 == 0) {
                cout << "HL\n";
            }
            else {
                cout << "T\n";
            }
        }
    }
}