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
    for(int casenum = 1; casenum <= tests; casenum++){
        long long n;
        cin >> n;
        vector<long long> v;
        for(long long i=0; i<n; i++){
            long long x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        long long ans = 0;
        long long cur = 0;
        for(long long i=0; i<v.size(); i++){
            ans += cur - (v[i] * i) ;
            cur += v[i];
            
        }
        ans += v.back();
        cout << ans << endl;
        
    }
    
}