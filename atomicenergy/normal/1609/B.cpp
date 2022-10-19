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
    
    int t, n;
    cin >> t >> n;

    string s;
    cin >> s;
    int cnt = 0;
    for(int i=0; i<t-2; i++){
        if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') cnt++;
    }
    for(int i=0; i<n; i++){
            int ind;

            char c;
            cin >> ind >> c;
            ind--;
            if(ind >= 2 && s[ind-2] == 'a' && s[ind-1] == 'b' && s[ind] == 'c') cnt--;
            if(ind >= 1 && ind+1<t && s[ind-1] == 'a' && s[ind] == 'b' && s[ind+1] == 'c') cnt--; 
            if(ind+2 < t && s[ind] == 'a' && s[ind+1] == 'b' && s[ind+2] == 'c') cnt--;
            s[ind] = c;
            if(ind >= 2 && s[ind-2] == 'a' && s[ind-1] == 'b' && s[ind] == 'c') cnt++;
            if(ind >= 1 && ind+1<t && s[ind-1] == 'a' && s[ind] == 'b' && s[ind+1] == 'c') cnt++; 
            if(ind+2 < t && s[ind] == 'a' && s[ind+1] == 'b' && s[ind+2] == 'c') cnt++;
            cout << cnt << endl;
    }
    
}