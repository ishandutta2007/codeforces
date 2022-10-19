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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> v(n);
        vector<int> u(n);
        int c = k+10;
        for(int i=0; i<n; i++){
            c++;
            if(s[i] == '1') c=0;
            v[i] = c;
        }
        c =k+10;
        for(int i=n-1; i>=0; i--){
            c++;
            if(s[i] == '1') c=0;
            u[i] = c;
        }
        for(int i=0; i<n; i++){
            if(v[i] <= k || u[i] <= k){
                if(v[i] != u[i]|| v[i] == 0){
                    cout << "1";
                }
                else cout << "0";
            }
            else cout << "0";
        }
        cout << endl;
    }
    
}