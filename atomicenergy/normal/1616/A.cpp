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
        int n ;
        cin >> n;
        map<int, int> m;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            if(x < 0) x *= -1;
            m[x]++;
        }
        int ans = 0;
        for(auto p : m){
            if(p.second == 1 || p.first == 0) ans += 1;
            else ans += 2;
        }
        cout << ans << endl;
    }

    
}