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
	int n, a[1111], x, y,k=0;
	cin >> n;
	for(int i = 1; i<n; i++)
		cin >> a[i];
	cin >> x >> y;

	while(x!=y){
		k+=a[x];
		x++;
	}
	cout << k;
	return 0;
}