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
    
    int tests;
    cin >> tests;
    for(int casenum = 1; casenum <= tests; casenum++){
        int n, a, b;
        cin >> n >> a >> b;
        if(a - b > 1 || b - a > 1 || a + b + 2 > n){
            cout << -1 << endl;
            continue;
        }

        if(a == b){
            a++;
            b++;
            for(int i=1; i<=a; i++){
                cout << i << " " << a+i << " ";
            }
            for(int i=2*a+1; i<=n; i++){
                cout << i << " ";
            }
            cout << endl;
            continue;
        }
        if(a - b == 1){
        
            for(int i=1; i<=a; i++){
                cout << i << " " << n+1-i << " ";
            }
            for(int i=n-a; i>=a+1; i--){
                cout << i << " ";
            }
            cout << endl;
            continue;
        }
        if(b - a == 1){
            a++;
            b++;
            for(int i=1; i<=a; i++){
                cout << a+i << " " << i << " ";
            }
            for(int i=2*a+1; i<=n; i++){
                cout << i << " ";
            }
            cout << endl;
            continue;
        }

    }
    
}