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
    
    int n, q;
    cin >> n >> q;
    vector<int> v;
    int s = 0;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
        s+=x;
    }
    for(int i=0; i<q; i++){
        int a, b;
        cin >> a >> b;
        if(a == 1){
            b--;
            s-= v[b];
            v[b] = 1- v[b];
            s+=v[b];
        }
        else{
            if(s >= b) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    
    
}