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
        int x;
        cin >> x;
        double a = x;
        double b = sqrt(a);
        bool ok = false;
        double c = x;
        c/=2;
        double d = sqrt(c);
        for(int i=b-20; i<b+20; i++) if(i*i == x && x%4 == 0) ok = true;
        for(int i=d-20; i<d+20; i++) if(i*i*2 == x) ok = true;
        cout << (ok?"YES":"NO") << endl;
    }
    
}