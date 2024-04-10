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
    int n, m[1100], a, b, x, y = 1010, z = 1;
    for(int i=0; i<1050; i++)
        m[i] = 0;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        if(a>b) swap(a, b);
        m[a]++;
        m[b+1]--;
    }
    for(int i = 1; i<1010; i++)
        m[i]+=m[i-1];
    for(int i=0; i<1010; i++){
        if(m[i]==n){
            z = 0;
            y = min(y, abs(x-i));    
        }    
    }
    if(z) cout << -1;
    else cout << y;
    return 0;
}