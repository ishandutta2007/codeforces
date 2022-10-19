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
        set<string> s;
        bool b = false;
        for(int i=0; i<n; i++){
            string a;
            cin >> a;
            if(a.size() == 1) b = true;
            if(a.size() == 2){
                string oth = "";
                oth += a[1];
                oth += a[0];
                if(s.count(oth)) b = true;
                if(a[0] == a[1]) b= true;
                for(char c = 'a'; c<= 'z'; c++){
                     oth = "";
                oth += a[1];
                oth += a[0];
                oth += c;
                    if(s.count(oth)) b = true;
                }
            }
            if(a.size() == 3){
                string oth = "";
                oth += a[2];
                oth += a[1];
                oth += a[0];
                if(s.count(oth)) b = true;
                if(a[0] == a[2]) b= true;
                oth = "";
                oth += a[2];
                oth += a[1];
                if(s.count(oth)) b = true;
            }

            s.insert(a);
        }
        cout << (b?"YES":"NO") << endl;
    }
    
}