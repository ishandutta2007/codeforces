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

bool line(int a, int b, int c, int d, int e, int f){
    int g = c-a;
    int h = d-b;
    int i = e-a;
    int j = f-b;
    return g*j == h*i;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int tests;
    cin >> tests;
    for(int casenum = 1; casenum <= tests; casenum++){
        int n;
        cin >> n;
        vector<int> v;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        int mx = 0;
        if(n <= 2){
            cout << 0 << endl;
            continue;
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                
                int correct = 2;
                for(int k=0; k<n; k++){
                    if(i ==k || j == k) continue;
                    if(line(i, v[i], j, v[j], k, v[k])) correct++;
                }
                mx = max(mx, correct);
            }
        }
        cout << n-mx << endl;
    }
    
}