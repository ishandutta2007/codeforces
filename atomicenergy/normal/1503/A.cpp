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
        string s;
        cin >> n >> s;
        string a = "";
        string b = "";
        int aa = 0;
        int bb = 0;
        bool ok = true;
        int tot = 0;
        for(char c : s) if(c == '1') tot++;
        if(tot%2 == 1) ok = false;
        int cur = 0;
        for(char c : s){
            if(c == '1'){
                if(cur < tot/2){
                    aa++;
                    bb++;
                    a += '(';
                    b += '(';
                }else{
                    aa--;
                    bb--;
                    a += ')';
                    b += ')';
                    if(aa < 0 || bb < 0) ok = false;
                }
                cur++;
            }else{
                if(aa < bb){
                    aa++;
                    bb--;
                    a += '(';
                    b += ')';
                }else{
                    bb++;
                    aa--;
                    b += '(';
                    a += ')';
                }
                if(aa < 0 || bb < 0) ok = false;
            }
        }
        if(ok){
            cout << "YES" << endl << a << endl << b << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    
}