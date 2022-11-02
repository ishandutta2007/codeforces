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
    int n, k, l, r, sa, sk, a[1111], z = 0, t  = 0;
    cin >> n >> k >> l >> r >> sa >> sk;
    for(int i = 0; i<n; i++){
        sa -= l;
        a[i] = l;
    }
    sk -= k*l;
    if(k != n) {
        sa-=sk;
        z = sa/(n - k);
    }
    t = sk/k;
    for(int i = k; i<n; i++) {
        a[i] += z;
        if(sa != (n - i) * z){
            a[i]++;
            sa--;        
        }
        sa-=z;
    }
    for(int i = 0; i<k; i++) {
        a[i] += t;
        if(sk != (k - i) * t){
            sk--;
            a[i]++;
        }
        sk -= t;
    }
    for(int i = 0; i<n; i++) cout << a[i] << " ";
    return 0;
}