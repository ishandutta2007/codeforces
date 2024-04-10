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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sm = 0;
    for (int i = 0; i < n; i++) {
        sm += a[i];
    }
    int need = -1;
    for (int i = 0; i < n; i++) {
        need = max(need, a[i] - (sm - a[i]));
    }
    need++;
    need = max(need, 1);
    cout << need << endl;
}