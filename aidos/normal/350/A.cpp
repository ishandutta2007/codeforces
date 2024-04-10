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
	int n, m, mx=-1, mn = 101, a, b[111], mu = 101;
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		cin >> a;
		if(a > mx) mx=a;
		if(mu > a) mu = a;
	}
	mx = max(mx, 2*mu);
	for(int i = 0; i<m; i++){
		cin >> a;
		if(a < mn) mn=a;
	}
	if(mx < mn) cout << mx;
	else cout << -1;
    return 0;
}