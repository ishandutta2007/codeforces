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

//zy

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tests;
    cin >> tests;
    for(int casenum = 1; casenum <= tests; casenum++){
        string s;
        int n;
        cin >> n;
        cin >> s;
        string ans;
        ans += s[0];
        if(n == 1 || s[0] <= s[1]){
            ans += s[0];
            cout << ans << endl;
            continue;
        }
        ans += s[1];
        for(int i=2; i<n; i++){
            if(s[i] <= s[i-1]) ans += s[i];
            else break;
        }
        for(int i=ans.size()-1; i>=0; i--){
            ans += s[i];
        }

        cout << ans << endl;
    }
    
    
}