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
    int n, m, k = 100, l = 100, h=0, g = 0;
    cin >> n >> m;
    char c[100][100];
    for(int i=0; i<n; i++)
        for(int j = 0; j<m; j++){
            cin >> c[i][j];
            if(c[i][j]=='*'){
                k = min(k, i);
                l = min(l, j);
                h = max(h, i);
                g = max(g, j);
            }
        }
    for(int i=k; i<=h; i++){
        for(int j = l; j<=g; j++)
            cout << c[i][j];
        cout << endl;
    }
    
    return 0;
}