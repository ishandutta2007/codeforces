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
        int n;
        cin >> n;
        vector<long long> v;
        int twos = 0;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            while(x%2 == 0) {
                x/=2;
                twos++;
            }
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        for(int i=0; i<twos; i++){
            v[v.size()-1] *= 2;
            //cout << v[v.size()-1]  << endl;
        }
        long long tot = 0;
        for(auto c : v) tot += c;
        cout << tot << endl;
        
    }
    
}