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

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] -= i;
    }
    vector<long long> dpPrev(n), dpNext(n);

    vector<long long> b = a;
    sort(all(b));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) 
            dpNext[j] = dpPrev[j] + abs(b[j] - a[i]);

        for (int j = 1; j < n; ++j) 
            dpNext[j] = min(dpNext[j], dpNext[j - 1]);

        swap(dpNext, dpPrev);
    }
    cout << dpPrev[n - 1] << endl;
    return 0;
}