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
	ll c[111111], n, k = 0, t;
	cin >> n;
	c[0] = 0;
	for(int i = 1; i<=n; i++){
		cin >> t;
		c[i] = c[i-1] + t;
	}
	for(int i = 1; i<n; i++){
		if(c[i] == c[n]-c[i]) k++;
	}
	cout << k;
	return 0;
}