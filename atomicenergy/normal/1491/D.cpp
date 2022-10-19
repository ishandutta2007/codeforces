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
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int u, v;
        cin >> u >> v;
        int num =0;
        bool ok = true;
        for(int i=0; i<30; i++){
            if(u&(1 << i)) num++;
            if(v&(1 << i)) num--;
            if(num < 0) ok = false;
        }
        cout << (ok&&(u<=v)?"YES":"NO") << endl;
    }
    
}