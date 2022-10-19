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
        vector<int> u;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            u.push_back(x);
        }
        int j = 0;
        map<int, int> m;
        bool ok = true;
        for(int i=0; i<u.size(); i++){
            //cout << m[2] << endl;
            if(i > 0 && u[i] == u[i-1] && m[u[i]] > 0){
                m[u[i]]--;
                continue;
            }
            if(j == v.size()){
                    i = u.size();
                    ok = false;
                    continue;
                }
            while(v[j] != u[i]){
                m[v[j]]++;
                j++;
                if(j == v.size()){
                    i = u.size();
                    ok = false;
                    break;
                }
            }
            j++;
            //if(i == u.size()) continue;

        }
        cout << (ok?"YES":"NO") << endl;
        
        
        
        
    }
    
}