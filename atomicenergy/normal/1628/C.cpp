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
        vector<vector<int> > v(n, vector<int> (n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> v[i][j];
            }
        }
        int ans = 0;
        for(int s = 0; s <= 2*n; s+=4){
            bool b = true;
            for(int i=0; i<=s; i++){
                int j = s-i;
                if(i >= 0 && j >= 0 && i < n && j < n){
                    if(b){
                        ans ^= v[i][j];
                        ans ^= v[n-1-i][j];
                    }else{

                    }
                    b = !b;
                }
            }
        }

        cout << ans << endl;
    }
    
}