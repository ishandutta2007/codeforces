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
        string s, t;
        cin >> s >> t;
        int a = 0, b = 0;
        int mn = -1;
        int d = 0;
        bool c = false;
        for(int i=0; i<n; i++){
            if(s[i] == '1') a++;
            if(t[i] == '1') b++;
            if(s[i] != t[i]) d++;
            if(s[i] == '1' && t[i] == '1') c = true;
        }   
        if(a > 0){
            if(n-a + 1 == b){
                if(c){
                    mn = 1 + (n-d-1);
                }
                
            }
        }
        if(a == b) {
            if(mn == -1)
                mn = d;
            else mn = min(mn, d);
        }
        cout << mn << endl;
    }
    
    
}