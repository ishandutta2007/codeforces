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
    int n,k,a[1111], z;
    cin >> n>> k;
    for(int i = 0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);
    reverse(a, a+n);
    k--;
    if(a[k] > 0){
       z = k+1;
       while(z<n && a[z]==a[k]){
            z++; 
       }     
       cout << z;
    }
    else {
        z = k;
        while(z >= 0 && a[z] <= 0){
            z--;
        }
        cout << z + 1;
    }
    return 0;
}