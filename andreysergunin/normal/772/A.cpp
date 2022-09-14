#include <stdio.h>
#include <iostream>
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
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

const ll INF = 1e15 + 10;
const int OPS = 100;

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
        
    int n, p;
    cin >> n >> p;
    vector<int> a(n), b(n);

    double tm = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    if (sum <= p) {
        cout << "-1\n";
        return 0;
    }

    double l = 0, r = INF;
    for (int op = 0; op < OPS; ++op) {
        double t = (l + r) / 2;
        double delta = 0;
        for (int i = 0; i < n; ++i)
            delta += max(a[i] * t - b[i], 0.0);
        if (delta / p < t) {
            l = t;
        } else {
            r = t;
        }
    }

    cout << l << endl;

}