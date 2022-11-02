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
	int n, a, b, c, x, d[400][400];
	cin >> n;
	if(n == 1){
		cin >> x;
	}
	else if(n == 2){
		cin >> a >> b;
		for(int i= 1; i<330; i++)
			d[0][i] = d[i][0] = 1;
		d[0][0] = 0;
		for(int i = 1; i<320; i++)
			for(int j = 1; j<320; j++){
				d[i][j] = 0;
				int z= min(i, j);
				for(int u = 1; u<=z; u++)
					if(!d[i-u][j-u]) d[i][j] = 1;
				for(int u=1; u<i; u++)
					if(!d[u][j]) d[i][j] = 1;
				for(int u=1; u<j; u++)
					if(!d[i][u]) d[i][j] = 1;
			}
		x = d[a][b];
	}
	else {
		cin >> a >> b >> x;
		x ^= a;
		x ^= b;
	}
	if(x > 0) cout << "BitLGM";
	else cout << "BitAryo";
    return 0;
}