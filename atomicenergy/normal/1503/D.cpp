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
    vector<int> v(2*n + 1);
    vector<int> first(2*n + 1);
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        v[x] = y;
        v[y] = x;
        first[x] = 1;
        first[y] = 0;
    }
    int l = 1;
    int r = 2*n;
    set<int> lo;
    set<int> hi;
    
    int tot = 0;
    
    bool ok = true;
    int hr = n+1;
    int lr = 0;
    while(l < r){
        int li = l+1;
        int ri = r;
        int cur = 0;
        int cursz = 0;
        //lo.insert(l);
        hi.insert(v[l]);
        cursz += first[v[l]];
        hr = v[l];
        cur++;
        while(li < l+cur || ri > r-cur){
            if(li < l + cur){
                if(!lo.count(li)){
                    if(hr < v[li]) ok = false;
                    hi.insert(v[li]);
                    hr = v[li];
                    cursz += first[v[li]];
                    cur++;
                }
                li++;
                continue;
            }
            if(ri > r - cur){
                if(!hi.count(ri)){
                    if(lr > v[ri]) ok = false;
                    lo.insert(v[ri]);
                    lr = v[ri];
                    cursz += (first[v[ri]]);
                    cur++;
                }
                ri--;
                continue;
            }
            
        }
        //cout << li << " " << ri << " " << cur << " " << cursz << endl;
        if(li > ri + 1) ok = false;
        l = l + cur;
        r = r - cur;
        tot += min(cursz, cur - cursz);

    }
    if(!ok) cout << -1 << endl;
    else{
        cout << tot << endl;
    }
    
}