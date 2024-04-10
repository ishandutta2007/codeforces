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
int n, a[11111], sum = 0, k = 25000001, l = 0, c[5555][5555], d[5555][5555];
int get(int l, int r){
	return -c[l][r]+c[l][l] +d[l][r] - d[l][l] + d[r][l] - d[r][r] + c[r][r]-c[r][l];
}
int main () {
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> a[i];
	}
	for(int i = 1; i<=n; i++){
		c[i][0]=d[i][0] = 0;
		for(int j = 1; j<=n; j++){
			c[i][j] = c[i][j-1];
			if(a[i] > a[j]) c[i][j]++;
		}
		for(int j = 1; j<=n;j++){
			d[i][j] = d[i][j-1];
			if(a[i]<a[j]) d[i][j]++;
		}
		sum += d[i][i];
	}
	for(int i = 1; i<=n; i++){
		for(int j = i+1; j<=n; j++){
			if(a[i]>a[j]){
				int t = sum + get(i, j);
				if(t < k){
					k = t;
					l = 1;
				}
				else if(k == t){
					l++;
				}
			}
		}
	}
	cout << k << " " << l;
    return 0;
}