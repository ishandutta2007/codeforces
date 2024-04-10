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
    //freopen("output.txt", "w", stdout);
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

int n, l, k;
ld v[2];

const ld eps = 1e-06;

bool check(ld x) {
    int rest = n;
    ld time = 0;

    ld cur_aut = 0;

    while (rest) {
        if (time > x + eps) {
            return false;
        }
        ld cur_people = v[0] * time;
        if (cur_people > l) {
            break;
        }
        ld time_to_meet = (cur_aut - cur_people) / (v[0] + v[1]);
        cur_people += time_to_meet * v[0];
        cur_aut -= time_to_meet * v[1];
        assert(fabs(cur_aut - cur_people) < eps);
        rest = max(0, rest - k);
        time += time_to_meet;
        ld tmp = ((x - time) * v[0] * v[1] - (l - cur_aut) * v[0]) / (v[1] - v[0]);
        if (tmp < 0 - eps) {
            return false;
        }
        ld time_on_bus = (l - cur_aut - tmp) / v[1];
        time += time_on_bus;
        cur_aut += time_on_bus * v[1];
    }
    if (time > x + eps) {
        return false;
    }
    return true;
}

void solve() {

    cin >> n >> l >> v[0] >> v[1] >> k;
    ld left = 0;
    ld right = l / v[0];
    for (int it = 0; it < 150; ++it) {
        ld m = (left + right) / 2;
        if (check(m)) {
            right = m;
        }
        else {
            left = m;
        }
    }
    cout << right << endl;
}