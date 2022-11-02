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
	int a[110][110], n, m;
	cin >> n >> m;
	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++)
			cin >> a[i][j];
	for(int i = 0; i<n; i++)
		if(a[i][0] == 1 || a[i][m-1] == 1){
			cout << 2;
			return 0;
		}
	for(int i = 0; i<m; i++)
		if(a[0][i] == 1 || a[n-1][i] == 1){
			cout << 2;
			return 0;
		}
	cout << 4;
	return 0;
}