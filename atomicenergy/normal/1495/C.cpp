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
        int x, y;
        cin >> x >> y;
        //2 bottom
        //3 middle
        //4 bottom and top
        vector<vector<char> > v(x, vector<char>(y, '.'));
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                cin >> v[i][j];
            }
        }
        if(x == 1 || y == 1){
            for(int i=0; i<x; i++){
                for(int j=0; j<y; j++){
                    cout << 'X';
                }
                cout << endl;
            }
        }else{
        if(x%3 != 0){
            for(int i=1; i<x; i+=3){
                if(v[i][1] == 'X' || (i+1 < x && v[i+1][1] == 'X')){
                    v[i][1] = 'X';
                    if(i+1 < x) v[i+1][1] = 'X';
                }else{
                    v[i][0] = 'X';
                    if(i+1 < x) v[i+1][0] = 'X';
                }
            }
        }
        else{
            for(int i=-1; i<x; i+=3){
                if((i >= 0 && v[i][1] == 'X') || (i+1 < x && v[i+1][1] == 'X')){
                    if(i >= 0) v[i][1] = 'X';
                    if(i+1 < x) v[i+1][1] = 'X';
                }else{
                    if(i >= 0) v[i][0] = 'X';
                    if(i+1 < x) v[i+1][0] = 'X';
                }
            }
        }
         for(int i=0; i<x; i++){
                for(int j=0; j<y; j++){
                    cout << (((v[i][j] == 'X') || ((x%3 == 0 && i%3 == 1) || (x%3 != 0 && i%3 == 0)))?'X':'.');
                }
                cout << endl;
            }
        }
        
    }
    
}