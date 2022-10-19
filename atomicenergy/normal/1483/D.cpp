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


int a[600][600]; //minimum distance from i to j
int b[600][600]; //paths from i to j in less than this value are of use

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a[i][j] = 1000000005;
        }
    }
        vector<vector<int> > v;
    for(int i=0; i<n; i++){
        a[i][i] = 0;
    }
    for(int i=0; i<m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({x-1, y-1, z});
        a[x-1][y-1] = min(z, a[x-1][y-1]);
        a[y-1][x-1] = min(z, a[y-1][x-1]);
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                a[i][j] = min(a[i][k] + a[k][j], a[i][j]);
            }
        }
    }

    int q;
    cin >> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            b[i][j] = -1;
        }
    }
    for(int i=0; i<q; i++){
        int x, y, z;
        cin >> x >> y >> z;
        b[x-1][y-1] = max(z, b[x-1][y-1]);
        b[y-1][x-1] = max(z, b[y-1][x-1]);
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                b[i][j] = max(b[i][k] - a[j][k], b[i][j]);
                b[i][j] = max(b[k][j] - a[k][i], b[i][j]);
                b[i][k] = max(b[i][j] - a[k][j], b[i][k]);
                b[i][k] = max(b[j][k] - a[j][i], b[i][k]);
                b[k][j] = max(b[k][i] - a[j][i], b[k][j]);
                b[k][j] = max(b[i][j] - a[i][k], b[k][j]);
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
           // cout << i << " " << j << " " << a[i][j] << " " << b[i][j] << endl;
        }
    }
    int tot = 0;
    for(auto vv : v){
        if(b[vv[0]][vv[1]] >= vv[2]) tot++;
    }
    cout << tot << endl;
}