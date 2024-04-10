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
        ll n;
        cin >> n;
        if(n%2050 != 0) {
            cout << -1 << endl;
            continue;
        }
        n/=2050;
        int ans = 0;
        while(n!=0){
            ans += n%10;
            n/=10;
        }
        cout << ans << endl;
    }
    
}