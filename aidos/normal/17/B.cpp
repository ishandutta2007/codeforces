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
	int n, k, u[1111], b[1111], z = 0;
	memset(u, 1000001, sizeof(u));
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> k;
		b[i] = 0;
	}
	cin >> k;
	for(int i=0; i<k; ++i){
		int l, r, a;
		cin >> l >> r >> a;
		l--, r--;
		b[r] = 1;
		u[r] = min(u[r], a);
	}

	for(int i = 0; i<n; i++)
		z += b[i];
	if(z != n-1){
		cout << -1;
	}
	else {
		long long ans = 0;
		for(int i = 0; i<n; i++)
			if(b[i]) ans += u[i];
		cout << ans;
	}
    return 0;
}