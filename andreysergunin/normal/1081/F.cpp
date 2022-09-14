#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>
#include <chrono>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int request(int l, int r) {
    cout << "? " << l + 1 << " " << r + 1 << endl;
    int t;
    cin >> t;
    return t;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");


    int n, t;
    cin >> n >> t;
    vector<int> res(n, -1); 

    if (n == 1) {
        cout << "! " << t << endl;
        return 0;
    }   


    bool ok = false;
    int cur = t;

    while (!ok || cur != t) {
        request(0, n - 2);
        cur = request(0, n - 2);

        if (cur != t && !ok) {
            ok = true;
            if (cur < t) {
                res[n - 1] = 1;
            } else {
                res[n - 1] = 0;
            }
        }
    }

    ok = false;

    while (!ok || cur != t) {
        request(1, n - 1);
        cur = request(1, n - 1);

        if (cur != t && !ok) {
            ok = true;
            if (cur < t) {
                res[0] = 1;
            } else {
                res[0] = 0;
            }
        }
    }

    while (abs(2 * cur - n) == 1)   {
        if (rnd() & 1) {
            request(0, n - 2);
            cur = request(0, n - 2);
        } else {
            request(1, n - 1);
            cur = request(1, n - 1);
        }
    }

    t = cur;

    for (int i = 1; i < n - 1; ++i) {
        ok = false;
        while (!ok || cur != t) {
            request(i, i);
            cur = request(i, i);
            if (cur != t && !ok) {
                ok = true;
                if (cur + t == n + 1) {
                    res[i] = 1;
                } else {
                    res[i] = 0;
                }
            }
        }
    }

    cout << "! "; 
    for (int i = 0; i < n; ++i) {
        cout << res[i];
    }
    cout << endl;

}