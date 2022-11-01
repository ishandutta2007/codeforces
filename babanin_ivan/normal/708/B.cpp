#pragma comment (linker, "/STACK:128000000")
#include <iostream>
#include <cstdio>
#include <fstream>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <ctime>
#include <sstream>
#include <stack>
#include <cassert>
#include <list>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long long i64;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

//int timer = 0;
#define FILENAME ""

int main() {
    string s = FILENAME;
#ifdef YA
    //assert(!s.empty());
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //cerr<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
    cin.tie(0);
#endif
    cout.sync_with_stdio(0);
    cout.precision(10);
    cout << fixed;
    int t = 1;

    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        //++timer;
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}

#define int li
#define y hui

void printerr() {
    cout << "Impossible\n";
    exit(0);
}

void solve() {
    vector <int> n(2);
    vector <int> y(2);
    cin >> n[0] >> y[0] >> y[1] >> n[1];

    vector <int> realn(2, -1);

    for (int j = 0; j < 2; ++j) {
        if (n[j] == 0) {
            if (y[0] || y[1]) {
                realn[j] = 1;
            }
            else {
                realn[j] = 0;
            }
        }
    }

    if (realn[0] == 0 && realn[1] == 0) {
        if (y[0] == 0 && y[1] == 0) {
            cout << "1";
            exit(0);
        }
        else {
            printerr();
        }
    }

    for (int u = 0; u <= 1000000; ++u) {
        for (int j = 0; j < 2; ++j) {
            if (realn[j] == -1 && u * (u - 1) / 2 == n[j]) {
                realn[j] = u;
            }
        }
    }

    if (realn[0] == -1 || realn[1] == -1) {
        printerr();
    }
    if (realn[0] * realn[1] != y[0] + y[1]) {
        printerr();
    }

    vector <int> result;

    vector <int> restn = realn;
    vector <int> resty = y;

    for (int i = 0; i < realn[0] + realn[1]; ++i) {
        if (resty[0] >= restn[1]) {
            result.push_back(0);
            resty[0] -= restn[1];
            --restn[0];
        }
        else {
            result.push_back(1);
            --restn[1];
        }
        if (restn[0] < 0 || restn[1] < 0) {
            printerr();
        }
    }

    if (resty[0]) {
        printerr();
    }

    for (int x:result) {
        cout << x;
    }
}