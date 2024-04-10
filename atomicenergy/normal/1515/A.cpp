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
        int n, w;
        cin >> n >> w;
        vector<int> v;
        int s = 0;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            v.push_back(x);
            s+=x;
        }
        if(w == s){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            int cur = 0;
            sort(v.begin(), v.end());
            for(int i=0; i<n; i++){
                if(cur + v[i] == w){
                    swap(v[i], v[i+1]);
                }
                cur += v[i];
                cout << v[i] << " ";
            }
            cout << endl;
            
        }
        
        
    }
    
}