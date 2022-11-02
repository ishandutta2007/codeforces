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
#define pll pair <long long,long long>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define MAXN 1000000
#define INF 1000000000
using namespace std; 
int main () {
    int n, a[111], k =0, l =0, cur = 0;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        k+=a[i];
    }
    sort(a, a+n);
    for(int i = n-1; i>=0; i--){
        if(cur > k) break;
        cur += a[i];
        k-=a[i];
        l++;
    }
    cout << l;
    return 0;
}