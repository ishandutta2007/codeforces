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
        vector<int> v;
        long long tot = 0;
        cin >> n;
        for(int i=0; i<n; i++){
            long long x;
            cin >> x;
            
            v.push_back(x);
            
        }
        //cout << tot << endl;
        vector<int> k(n+1, 0);
        for(int i=0; i<n; i++){
            tot += max(0, v[i] - 1 - k[i]);
            if(k[i] > v[i]-1){
                k[i+1] += k[i] - v[i] +1;
            }
            if(v[i] == 1) continue;
            if(v[i]+i > n){
                v[i] = n-i;
            }
            
            
            while(v[i] > 1){
                int a = i + v[i];
                if(a < n){
                    k[a]++;
                }
                v[i]--;
            }
        }
        cout << tot << endl;
    }
    
}