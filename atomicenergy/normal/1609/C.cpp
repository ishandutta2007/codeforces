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

bool isprime(int x){
    if(x < 2) return false;
    for(int i=2; i*i<=x; i++){
        if(x%i == 0) return false;
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int tests;
    cin >> tests;
    for(int casenum = 1; casenum <= tests; casenum++){
        int n, e;
        cin >> n >> e;
        vector<int> v;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            v.push_back(x);
        }

        vector<long long> onesafter (n, 0);
        vector<long long> onesbefore (n, 0);
        for(int i=e; i<n; i++){
            if(v[i-e] == 1) onesbefore[i] = onesbefore[i-e] + 1;
        }
        for(int i=n-1-e; i>=0; i--){
            if(v[i+e] == 1) onesafter[i] = onesafter[i+e] + 1;
        }
        long long tot = 0;
        for(int i=0; i<n; i++){
            if(isprime(v[i])){
                tot += ((onesbefore[i] + 1) * (onesafter[i] + 1) - 1);
            }
        }
        cout << tot << endl;
    }
    
}