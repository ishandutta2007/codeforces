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
double MIN(double a, double b){
	if(a > b) return b;
	return a;
}

int main () {
	double a[1111], d = 0.0, n, v, b, x;
	cin >> n >> v;
	for(int i=0; i<n; i++){
		cin >> a[i];
		d+=a[i];
	}
	x = v/d;
	for(int i = 0; i<n; i++){
		cin >> b;
		x = MIN(x, b/a[i]);
	}
	cout << x * d;
	return 0;
}