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
        vector<int> a;
        map<int, int> freq;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            a.push_back(x);
            freq[x]++;
        }
        vector<int> b;
        int i = 0;
        while(true){
            int z = 0;
            while(freq[z]) z++;
            b.push_back(z);
            if(z == 0){
                i++;
                if(i == a.size()) break;
                continue;   
            }
            set<int> s;
            
            while(s.size() < z && i < a.size()){
                freq[a[i]]--;
                if(a[i] < z) s.insert(a[i]);
                i++;
            }
            if(i == a.size()) break;
        }
        cout << b.size() << endl;
        for(auto ii : b){
            cout << ii << " ";
        }
        cout << endl;
        
    }
    
}