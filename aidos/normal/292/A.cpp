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
    long long t[1100], c[1100], n, k = 0, l = 0, kx;
    cin >> n;
    cin >> t[0] >> c[0];
    k = t[0];
    l = c[0];
    kx = l;
    for(int i=1; i<n; i++){
        cin >> t[i] >> c[i];
        if(t[i]-t[i-1]>l){
            l = c[i];            
        }
        else {
            l += (c[i] - t[i]+t[i-1]);
        }
        k = t[i];
        if(l>kx) kx = l;
    }
    cout << l+k << " " << kx;
    return 0;
}