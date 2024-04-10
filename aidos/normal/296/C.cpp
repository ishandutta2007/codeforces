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
int n, m, k, d[100100], l[100100], r[100100], t[100100], y, x;
long long w[100100], a[100100];    
int main () {   
    for(int i=0; i<100010; i++) {
        d[i] = 0;
        w[i] = 0;
    }
    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
        cin >> a[i];
    a[n] = 0;
    for(int i=0; i<m; i++){
        cin >> l[i] >> r[i] >> t[i];
        l[i]--;    
    }
    for(int i=0; i<k; i++){
        cin >> x >> y;
        x--;
        d[x]++;
        d[y]--;
    }
    w[l[0]] += d[0]*1ll*t[0];
    w[r[0]] -= d[0]*1ll*t[0];
    for(int i=1; i<m; i++){
        d[i] += d[i-1];
        w[l[i]] += d[i]*1ll*t[i];
        w[r[i]] -= d[i]*1ll*t[i];                                       
    }
    for(int i=0; i<n; i++){
        cout << a[i] + w[i] << " " ;
        w[i+1] += w[i];    
    }                  
    return 0;
}