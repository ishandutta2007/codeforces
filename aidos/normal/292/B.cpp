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
    int n, m, x, l;
    cin >> n >> m;
    map <int, int> z;
    map <int, int> d;
    for(int i=0; i<m; i++) {
        cin >> x >> l;
        z[x]++;
        z[l]++;
    }
    for(int i=1; i<=n; i++)
        d[z[i]]++;
    if(d[1]==n-1 && d[n-1]==1 && m==n-1){
        cout << "star topology";
    }
    else if(d[2]==n && (n==2 && m==1 || m==n)){
        cout << "ring topology";
    }
    else if(d[1]==2 && n == m+1 && d[2] == n-2){
        cout << "bus topology";
    }
    else cout << "unknown topology";
    return 0;
}