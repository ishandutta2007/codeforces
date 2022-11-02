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
	int n, m, a[111], b[111];
	cin >> n >> m;
	string s[111];
	for(int i=0; i<n; i++){
		cin >> s[i];
		a[i] = 0;
	}
	for(int i = 0; i<m; i++){
		b[i] = 0;
		for(int j = 0; j<n; j++){
			if(s[j][i] > b[i]) b[i] = s[j][i];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			if(b[j] == s[i][j]) a[i] = 1;
	}
	int k = 0;
	for(int i = 0; i<n; i++)
		if(a[i]) k++;
	cout << k;
	return 0;
}