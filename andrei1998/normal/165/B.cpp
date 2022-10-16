#include <bits/stdc++.h>

#define mod 1000000007
#define lint long long int
#define mp make_pair
#define pb push_back
#define lsb(x) ((x) & (-(x)))
using namespace std;

lint get_written (lint v, lint k) {
    lint ans = 0;
    while (v) {
        ans += v;
        v /= k;
    }

    return ans;
}

lint get_ans (lint n, lint k) {
    lint st = 1;
    lint dr = 2 * 1000000005;
    lint mijl;
    lint ans = dr + 1;

    while (st <= dr) {
        mijl = (st + dr) / 2;

        if (get_written(mijl, k) >= n) {
            ans = mijl;
            dr = mijl - 1;
        }
        else {
            st = mijl + 1;
        }
    }

    return ans;
}

int main()
{
    lint n, k;
    cin >> n >> k;

    cout << get_ans(n, k) << endl;

    return 0;
}