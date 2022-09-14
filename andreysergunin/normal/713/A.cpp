#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <random>
#include <tuple>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define fs first
#define sc second

const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> a(1 << 20);

    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == '+') {
            long long k;
            cin >> k;
            long long t = 0;
            vector<int> b;
            while (k > 0) {
                b.push_back(k % 2);
                k /= 10;
            }
            for (int i = sz(b) - 1; i >= 0; --i) {
                t *= 2;
                t += b[i];
            }
            ++a[t];
        }
        if (c == '-') {
            long long k;
            cin >> k;
            long long t = 0;
            vector<int> b;
            while (k > 0) {
                b.push_back(k % 2);
                k /= 10;
            }
            for (int i = sz(b) - 1; i >= 0; --i) {
                t *= 2;
                t += b[i];
            }
            --a[t];
        }
        if (c == '?') {
            long long k;
            cin >> k;
            long long t = 0;
            vector<int> b;
            while (k > 0) {
                b.push_back(k % 2);
                k /= 10;
            }
            for (int i = sz(b) - 1; i >= 0; --i) {
                t *= 2;
                t += b[i];
            }
            cout << a[t] << endl;
        }
    }

}