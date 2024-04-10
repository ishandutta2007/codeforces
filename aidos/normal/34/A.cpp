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
	int n, a[1111], mm = 1111, k;
	cin >> n;
	for(int i = 0; i<n; i++)
		cin >> a[i];
	for(int i = 0; i<n; i++){
		if(abs(a[i] - a[(i+1)%n]) < mm){
			mm = abs(a[i]-a[(i+1)%n]);
			k = i;
		}
	}
	cout<<k+1 << " " << (k+1) % n + 1;
	return 0;
}