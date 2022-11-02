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
int gcd(int l, int m){
    if(l==0) return m;
    return gcd(m%l, l);
}
int check(int l, int n){
    int z = 0;
    while(n){
        z+=(n%l);
        n/=l;
    }
    return z;
}
int main () {   
    int n, m = 0, k = 0;
    cin >> n;
    for(int i=2; i<n; i++){
        k+=check(i, n);
        m++;                
    }
    int t = k>m ? gcd(m, k) : gcd(k, m);
    cout << k/t << "/" << m/t;
    return 0;
}