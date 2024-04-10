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
        cout << 3*n << endl;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
        }
        for(int i=1; i<=n; i+=2){
            cout << "2 " << i << " " << i+1 << endl;
            cout << "1 " << i << " " << i+1 << endl;
            cout << "2 " << i << " " << i+1 << endl;
            cout << "2 " << i << " " << i+1 << endl;
            cout << "1 " << i << " " << i+1 << endl;
            cout << "2 " << i << " " << i+1 << endl;
        }
    }
    
}