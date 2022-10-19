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
    int a = -1;
    int b = -1;
    int score = 0;
    for(int i=0; i<n; i++){
        if(v[i] == a && v[i] == b) continue;
        else if(v[i] == a){
            b = v[i];
            score++;
        }
        else if(v[i] == b){
            a = v[i];
            score++;
        }
        else {
            if(a != b){
                b = -1;
            }
            a = v[i];
            
            score++;
        }
    }
    cout << score << endl;
    
    
}