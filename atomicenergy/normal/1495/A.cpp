using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <iomanip>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int tests;
    cin >> tests;
    cout << fixed << setprecision(10);
    for(int casenum = 1; casenum <= tests; casenum++){
        int n;
        cin >> n;
        vector<long long> u, v;
        for(int i=0; i<n*2; i++){
            long long x, y;
            cin >> x >> y;
            if(x == 0) u.push_back(abs(y));
            if(y == 0) v.push_back(abs(x));
        }
        sort(u.begin(), u.end());
        sort(v.begin(), v.end());
        double ans = 0;
        for(int i=0; i<n; i++){
            ans += sqrt(u[i] * u[i] + v[i] * v[i]);
        }
        cout << ans << "\n";
    }
    
}