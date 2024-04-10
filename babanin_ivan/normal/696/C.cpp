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

const int mod = 1000000000 + 7;

int bpow(int x, int p) {
    if (p == 0) {
        return 1;
    }
    int x2 = bpow(x * x % mod, p / 2);
    if (p & 1) {
        return x2 * x % mod;
    }
    else {
        return x2;
    }
}

void solve() {
    int k;
    cin >> k;
    vector<int> a(k);

    bool hasEven = false;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            hasEven = true;
        }
    }

    //calc 2^(n - 1)
    int start = bpow(2, a[0]);
    for (int i = 1; i < a.size(); ++i) {
        start = bpow(start, a[i]);
    }

    start = (start * bpow(2, mod - 2)) % mod;

    if (hasEven) {
        int tmp = (start + 1) * bpow(3, mod - 2) % mod;
        cout << tmp << "/" << start;
    }
    else {
        int tmp = (start - 1) * bpow(3, mod - 2) % mod;
        cout << tmp << "/" << start;
    }
    //cout << bpow(3, mod - 1);
}