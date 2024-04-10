#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
int main () {   
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    long long n, m, y[111000], x = 0, c, t, v;
    cin >> n >> m;
    cin >> c >> t;
    y[0] = c*t;
    for(int i = 1; i<n; i++){
        cin >> c >> t;
        y[i] = (c*1ll*t+y[i-1]);    
    }
    for(int i = 0; i<m; i++){
        cin >> v;
        while(y[x]<v){
            x++;
        }
        cout << x+1 << endl;
    }
    return 0;
}