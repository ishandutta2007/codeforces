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
    
    vector<vector<int> > v;
    int n;
    cin >> n;
    vector<int> cur;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        cur.push_back(x);
    }
    v.push_back(cur);
    for(int i=1; i<n; i++){
        vector<int> cur2;
        for(auto u : cur){
            if(u != i) cur2.push_back(u);
        }
        swap(cur, cur2);
        v.push_back(cur);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << v[i-j][j]<< " ";
        }
        cout << endl;
    }
    
}