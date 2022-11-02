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
	int n, a[111][111], b[111], m, ok = 1, d[111], ans = 0;
	for(int i = 0; i<105; i++){
		b[i] = 0;
		for(int j = 0; j<105; j++)
			a[i][j] = 0;
	}
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
		b[x]++;
		b[y]++;
	}
	while(ok){
		ok = 0;
		for(int i = 1; i<=n; i++){
			d[i] = b[i];
		}
		for(int i = 1; i<=n; i++){
			if(d[i] == 1 && b[i] == 1){
				ok=1;
				for(int j = 1; j<=n; j++)
					if(a[i][j] == 1) {
						d[i]--;
						d[j]--;
						a[i][j] = 0;
						a[j][i] = 0;
					}
			}
		}
		for(int i = 1; i<=n; i++)
			b[i] = d[i];
		ans+=ok;
	}
	cout << ans;
    return 0;
}