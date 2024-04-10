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
    int x, d[50][50], a[111], b[111];
    cin >> x;
    for(int i = 0; i<x; i++){
        for(int j = 0; j < x; j++)
            cin >>  d[i][j];
    }
    for(int i = 0; i<x; i++){
        a[i] = b[i] = 0;
        for(int j = 0; j<x; j++){
            a[i] += d[i][j];
            b[i] += d[j][i];
        }
    }
    int ans = 0;
    for(int i = 0; i<x; i++){
        for(int j = 0; j<x; j++){
            if(a[i] < b[j]) ans++;
        }
    }
    cout << ans;
    return 0;
}