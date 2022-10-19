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
        int n;
        cin >> n;

        vector<ll> v;
        ll tot = 0;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            if (i > 0 && v[i-1] > x) tot += v[i-1] - x;
            v.push_back(x);
        }
        cout << tot << endl;

    }


}