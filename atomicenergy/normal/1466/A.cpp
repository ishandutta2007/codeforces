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
        vector<int> v;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        set<int> s;
        for(int i : v){
            for(int j : v){
                if(i >= j) continue;
                s.insert(j-i);
            }
        }
        cout << s.size() << endl;
        
    }
    
}