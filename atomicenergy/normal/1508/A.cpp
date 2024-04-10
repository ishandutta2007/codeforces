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
        string s, t, u;
        cin >> s >> t >> u;
        int sc = 0, tc = 0, uc = 0;
        for(char c : s) if(c == '1') sc++;
        for(char c : t) if(c == '1') tc++;
        for(char c : u) if(c == '1') uc++;
        int amt = 0;
        if(sc >= n) amt++;
        if(tc >= n) amt++;
        if(uc >= n) amt++;
        if(amt >= 2){
            if(sc < n){
                swap(s, u);
            }
            if(tc < n){
                swap(t, u);
            }
            int si = 0;
            int ti = 0;
            int ct = 0;
            while(si < 2*n || ti < 2*n|| ct < 3*n){
                if(si < s.size() && ti < t.size() && s[si] == t[ti]){
                    cout << s[si];
                    ct++;
                    si++;
                    ti++;
                    continue;
                }
                if(si < s.size() && s[si] == '0'){
                    cout << '0';
                    ct++;
                    si++;
                    continue;
                }
                if(ti < t.size() && t[ti] == '0'){
                    cout << '0';
                    ct++;
                    ti++;
                    continue;
                }
                if(si < s.size()){
                    cout << s[si];
                    ct++;
                    si++;
                    continue;
                }
                if(ti < s.size()){
                    cout << t[ti];
                    ct++;
                    ti++;
                    continue;
                }
                cout << '0';
                ct++;
            }
            cout << endl;
        }else{
            if(sc >= n){
                swap(s, u);
            }
            if(tc >= n){
                swap(t, u);
            }
            int si = 0;
            int ti = 0;
            int ct = 0;
            while(si < 2*n || ti < 2*n || ct < 3*n){
                if(si < s.size() && ti < t.size() && s[si] == t[ti]){
                    cout << s[si];
                    ct++;
                    si++;
                    ti++;
                    continue;
                }
                if(si < s.size() && s[si] == '1'){
                    cout << '1';
                    ct++;
                    si++;
                    continue;
                }
                if(ti < t.size() && t[ti] == '1'){
                    cout << '1';
                    ct++;
                    ti++;
                    continue;
                }
                if(si < s.size()){
                    cout << s[si];
                    ct++;
                    si++;
                    continue;
                }
                if(ti < s.size()){
                    cout << t[ti];
                    ct++;
                    ti++;
                    continue;
                }
                cout << '0';
                ct++;
            }
            cout << endl;
        }
    }
    
}