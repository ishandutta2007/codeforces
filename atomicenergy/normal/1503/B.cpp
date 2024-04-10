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
    int re = 1;
    int ce = 1;
    int ro = 1;
    int co = 2;
    for(int i=0; i<n*n; i++){
        int a;
        cin >> a;
        if(a == 1){
            if(re <= n && ce <= n){
                cout << 2 << " " << re << " " << ce << endl;
                ce += 2;
                if(ce > n){
                    ce=1;
                    re++;
                    if(re%2 == 0) ce++;
                }
            }else{
                cout <<  3<<" " <<ro << " " << co <<   endl;
                co += 2;
                if(co > n){
                    co=1;
                    ro++;
                    if(ro%2 == 1) co++;
                }
            }
        }
        if(a == 2){
            if(ro <= n && co <= n){
                cout << 1 <<" " <<ro << " " << co <<   endl;
                co += 2;
                if(co > n){
                    co=1;
                    ro++;
                    if(ro%2 == 1) co++;
                }
            }else{
                cout << 3 <<" " <<re << " " << ce <<   endl;
                ce += 2;
                if(ce > n){
                    ce=1;
                    re++;
                    if(re%2 == 0) ce++;
                }
            }
        }
        if(a == 3){
            if(ro <= n && co <= n){
                cout << 1 <<" " << ro << " " << co <<  endl;
                co += 2;
                if(co > n){
                    co=1;
                    ro++;
                    if(ro%2 == 1) co++;
                }
            }else{
                cout << 2 << " " << re << " " << ce << endl;
                ce += 2;
                if(ce > n){
                    ce=1;
                    re++;
                    if(re%2 == 0) ce++;
                }
            }
        }
    }
    
}