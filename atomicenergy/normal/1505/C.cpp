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

//7 4 11 15

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    bool ok = true;
    for(int i=2; i<s.size(); i++){
        if(s[i]-'A' != (s[i-1] + s[i-2] - 'A' - 'A')%26) ok = false;
    }
    cout << ((ok?"YES":"NO")) << endl;
    
}