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
	int a[111], n, k, b[111], d[111];
	a[0] = b[0] = 0;
	cin >> n >> k;
	for(int i = 1; i<=n; i++)
		cin >> a[i];
	for(int j = 1; j <= k; j++){
		if(a[j] == 1) {
			b[j] = 1;
			d[j] = 0;
		}
		else {
			b[j] = 0;
			d[j] = 1;
		}
	}
	for(int i = k+1; i <= n; i++){
		b[i] = b[i-k];
		d[i]=d[i-k];
		if(a[i] == 1) b[i]++;
		else d[i]++;
	}
	int ans = 0;
	for(int i = n-k+1; i<=n; i++){
		ans += min(b[i], d[i]);
	}
	cout << ans;
    return 0;
}