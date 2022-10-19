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
        int a = 0;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            a += (x-1);
        }
        if(a%2 == 0){
            cout << "maomao90" << endl;
        }else{
            cout << "errorgorn" << endl;
        }
        
        
    }
    
}