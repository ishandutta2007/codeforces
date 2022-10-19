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
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector<int> u(n);
    vector<int> w(n);
    int mx = 0;
    int cnt = 1;
    int mxc = 0;
    for(int i=1; i<n; i++){
        if(v[i] < v[i-1]) {
            cnt = 0;
        }
        cnt++;
        u[i] = cnt;
        if(mx == cnt){
            mxc++;
        }else if (cnt > mx){
            mxc = 1;
        }
        mx = max(mx, cnt);
    }
    cnt = 1;
    for(int i=n-2; i>=0; i--){
        if(v[i] < v[i+1]) {
            cnt = 0;
        }
        cnt++;
        w[i] = cnt;
        if(mx == cnt){
            mxc++;
        }else if (cnt > mx){
            mxc = 1;
        }
        mx = max(mx, cnt);
    }
    int tot = 0;
    for(int i=1; i<n-1; i++){
        if(v[i] > v[i-1] && v[i] > v[i+1]){

            if(u[i] == mx && w[i] == mx && mx%2 == 1 && mxc == 2){
                tot++;
            }
        }
    }
    cout << tot << endl;
    
}