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

int below(int n, int k){
    int a = n%(1 << (k+1));
    int b = (a > (1 << k))?(a - (1<<k)):0;
    return (n - a)/2 + b;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int tests;
    cin >> tests;
    for(int casenum = 1; casenum <= tests; casenum++){
        int mx = 0;
        int l, r;
        cin >> l >> r;
        for(int i=0; i<20; i++){
            mx = max(mx, below(r+1, i) - below(l, i));
        }
        cout << r-l+1-mx << endl;
    }
    
}