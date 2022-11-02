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
	ll n, k, a[211111];
	cin >> n >> k;
	a[0] = 0;
	for(int i = 1; i<=n; i++){
		cin >> a[i];
		a[i] += a[i-1];
	}
	ll mx = a[k], u = 1;
	for(int i = 2; i+k-1<=n; i++){
		if(mx > a[i+k-1] - a[i-1]){
			mx = a[i+k-1] - a[i-1];
			u = i;
		}
	}
	cout << u;
    return 0;
}