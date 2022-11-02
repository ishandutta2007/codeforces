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
    int n, b[10], l=0, a[1111], k = 0;
    b[0] = b[1] = 0;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    n--;
    while(l<=n){
        if(a[l] > a[n]) {
            b[k]+=a[l];
            l++;
        }
        else {
            b[k]+=a[n];
            n--;
        }
        k = 1-k;
    }
    cout << b[0] << " " << b[1];
    return 0;
}