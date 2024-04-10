using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <ctime>

typedef long long ll;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //srand(time(NULL));

    long long tests;
    cin >> tests;
    for (long long casenum = 1; casenum <= tests; casenum++) {
        long long n, k;
        cin >> n >> k;

        vector<long long> v;

        for (long long i = 0; i < n; i++) {
            long long x;
            cin >> x;
            v.push_back(x);
        }
        k--;
        long long mx = v[0];
        for (auto i : v) mx = max(mx, i);
        for (auto& i : v) i = mx - i;
        k %= 2;
        if (k == 1) {
            long long mx = v[0];
            for (auto i : v) mx = max(mx, i);
            for (auto& i : v) i = mx - i;
        }
        for (auto i : v) cout << i << " ";
        cout << endl;
    }


}