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
            if(i == 0){
                v.push_back(1);
                cout << "1" << endl;
            }else{
                if(x == 1){
                    v.push_back(1);
                    cout << v[0];
                    for(int i=1; i<v.size(); i++){
                        cout << "." << v[i];
                    }
                    cout << endl;
                }else{
                    while(x!=v.back()+1){
                            v.pop_back();
                            }
                            v[v.size()-1]++;
                            cout << v[0];
                        for(int i=1; i<v.size(); i++){
                            cout << "." << v[i];
                        }
                        cout << endl;
                    
                }
            }
        }
    }
    
}