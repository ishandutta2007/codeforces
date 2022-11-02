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
    int n, mx = 0, mn, a[1111], t = 0;
    cin >> n;
    mn = n-1;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n; i++)
        if(a[mx] < a[i]) mx = i;
    for(int i = mx; i>0; i--){
        swap(a[i], a[i-1]);
        t++;
    }
    for(int i=n-1; i>=0; i--){
        if(a[mn] > a[i]) mn = i;
    }
    for(int i=mn+1; i<n; i++){
        t++;
    }
    cout << t;
    return 0;
}