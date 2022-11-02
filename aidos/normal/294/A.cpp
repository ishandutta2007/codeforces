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
int n, a[110], m, x, y;
cin >> n;
for(int i=0; i<n; i++)
    cin >> a[i];
cin >> m;
for(int i=0; i<m; i++){
    cin >> y >> x;
    if(y<n) a[y] += (a[y-1]-x);
    if(y>1) a[y-2] += (x-1);
    a[y-1] = 0;
}
for(int i=0; i<n; i++)
    cout << a[i] << endl;
return 0;
}