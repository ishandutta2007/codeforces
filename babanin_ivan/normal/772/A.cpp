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

#define int long long

struct g {
    int a, b;
};

bool comp(const g& first, const g& second) {
    return first.b * second.a < second.b * first.a;
}

void solve() {
    int n, p;
    cin >> n >> p;
    vector <g> a(n);

    int sum_a = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].a >> a[i].b;
        sum_a += a[i].a;
    }
    sort(all(a), comp);
    
    if (sum_a <= p) {
        cout << -1 << endl;
        return;
    }
    
    int cur_sum_a = 0;
    int cur_sum_b = 0;
    for (int i = 0; i < n; ++i) {
        cur_sum_a += a[i].a;
        cur_sum_b += a[i].b;
        if (cur_sum_a <= p) {
            continue;
        }
        if (i + 1 < n) {
            if (cur_sum_b * a[i + 1].a > (cur_sum_a - p) * a[i + 1].b) {
                continue;
            }
        }
        cout << ld(cur_sum_b) / (cur_sum_a - p);
        return;
    }
}