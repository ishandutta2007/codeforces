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
	int n, a[1111], m;
	cin >> n >> m;
	for(int i = 1; i<=n; i++)
		a[i] = 0;
	for(int i = 0; i<m; i++){
		int x, y;
		cin >> x >> y;
		a[x] = 1;
		a[y] = 1;
	}
	cout << n-1 << endl;
	int z = 0;
	for(int i = 1; i<=n; i++)
		if(a[i] == 0) z = i;
	for(int j= 1; j<=n; j++){
		if(z != j) cout <<z << " " << j << endl;
	}
    return 0;
}