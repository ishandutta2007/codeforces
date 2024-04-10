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
        int first = -1;
        int last = -1;
        for(int i=0; i<n-1; i++){
            if(v[i] == v[i+1]){
                if(first == -1) first = i;
                last = i;
            }
        }
        if(first == -1 || first == last){
            cout << 0 << endl;
        }
        else if(first + 1 == last ){
            cout << 1 << endl;
        }else{
            cout << last-first-1 << endl;
        }
        
    }
    
}