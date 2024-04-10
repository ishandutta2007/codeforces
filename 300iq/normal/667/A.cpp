/*
HACK ME IF YOU CAN!















*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>
#include <set>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
#define mp make_pair
#define pb push_back
#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define int ll

#define max(a, b) (a > b ? a : b)
#define pi 3.141592653589793238462643383279

using namespace std;

main() {
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    #ifndef __linux__
        //
        //
    #endif 
    double d, h, v, e;
    cin >> d >> h >> v >> e;
    double a = pi;
    cout.precision(20);
    double b = (100 / (d / 2) * (d / 2));
    double go = b / a;
    double ans = e - ((4 * v) / (pi * d * d));
    if (ans < 0 && ans >= -1e4) {
        cout << "YES" << endl;
        cout << -h / ans << endl;
    } else {
        cout << "NO" << endl;;
    }
}