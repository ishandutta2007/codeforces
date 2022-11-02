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
    int n, a[100100], m[100100], x[100100], t, z;
    cin >> n;
    cin >> a[0];
    m[0] = 0;
    x[0] = 0;
    for(int i=1; i<n; i++){
        cin >> a[i];
        if(a[i]<=a[m[i-1]]) m[i] = i;
        else m[i] = m[i-1];
        if(a[i]>=a[x[i-1]]) x[i] = i;
        else x[i] = x[i-1];
    }
    if(n>2) {
        t = n-1, z = n-1;
        for(int i=n-2; i>0; i--){
            if(a[i]<=a[t]) t = i;
            if(a[i]>=a[z]) z = i;
            if(t!=i && m[i]!=i){
                cout << "3\n" << m[i]+1<< " " << i+1 << " "<<  t+1;
                return 0;
            }        
            if(z!=i && x[i]!=i){
                cout << "3\n" << x[i]+1<< " " << i+1 << " "<<  z+1;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}