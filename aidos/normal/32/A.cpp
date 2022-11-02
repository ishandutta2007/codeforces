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
	int n, a[1111], d, k = 0;
	cin >> n >> d;
	for(int i = 0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	for(int i = 0; i<n; i++)
		for(int j = i+1; j<n; j++){
			if(a[j] - a[i] <= d) k+=2;
		}
	cout << k;
	return 0;
}