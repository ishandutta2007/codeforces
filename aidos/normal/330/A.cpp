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
	int n, m, a[111][111], ans = 0;
	cin >> n >> m;
	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++){
			char d;
			cin >> d;
			if(d == 'S') a[i][j] = 1;
			else a[i][j] = 0;
		}
	for(int i = 0; i<n; i++){
		int b = 0;
		for(int j = 0; j<m; j++){
			b += a[i][j];
		}
		if(b == 0){
			ans += m;
			for(int j = 0; j < m; j++)
				a[i][j] = -1;	
		}
	}
	for(int j = 0; j<m; j++){
		int b = 0, c=0;
		for(int i = 0; i<n; i++){
			if(a[i][j] == 0) {
				b++;
				c++;
			}
			else if(a[i][j] == -1) c++;
		}
		if(c == n) ans += b;
	}
	cout << ans;
    return 0;
}