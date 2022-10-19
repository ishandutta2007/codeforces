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
        vector<int> v(n);
        map<int, vector<int>> m;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            m[x].push_back(i);
        }
        int k = 0;
        while(k < n){
            int first = -1;
            int prev = -1;
            vector<int> erasers;
            for(auto& p : m){
                int z = p.second[p.second.size()-1];
                v[z] = prev;
                if(first == -1){
                    first = z;
                }
                k++;
                prev = p.first;
                p.second.pop_back();
                if(p.second.size() == 0){
                    erasers.push_back(p.first);
                }
            }
            for(auto c : erasers){
                m.erase(c);
            }
            v[first] = prev;
        }
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";      
        }
        cout << endl;
        
        
    }
    
}