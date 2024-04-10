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
	ll n, d, m, l, ans=0, t, q = 0, z = 0;
	cin >> n >> d >> m >> l;
	while(z < n){
		if(ans < z*1ll*m) break;
		ll x = (z*1ll*m + l)/d;
		ans = (x+1) * 1ll * d;
		z++;
	}
	cout << ans;
	return 0;
}