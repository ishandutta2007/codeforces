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
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> ls(n, 0);
        for(int i=0; i<l; i++){
            int x;
            cin >> x;
            x--;
            ls[x]++;
        }
        for(int i=0; i<r; i++){
            int x;
            cin >> x;
            x--;
            ls[x]--;
        }
        int ans = 0;
        int ltot = 0;
        int rtot = 0;
        int lpairs = 0;
        int rpairs = 0;
        for(int i=0; i<n; i++){
            if(ls[i] > 0){
                lpairs += ls[i]/2;
                ltot += ls[i];
            }
            else{
                int b = -ls[i];
                rpairs += b/2;
                rtot += b;
            }
        }
        if(ltot < rtot){
            ans += ltot;
            int z = rtot-ltot;
            if(rpairs >= z/2){
                ans += z/2;
            }else{
                ans += rpairs + (z - rpairs * 2);
            }
        }else{
            ans += rtot;
            int z = ltot-rtot;
            if(lpairs >= z/2){
                ans += z/2;
            }else{
                ans += lpairs + (z - lpairs * 2);
            }
        }
        cout << ans << endl;
    }
    
}