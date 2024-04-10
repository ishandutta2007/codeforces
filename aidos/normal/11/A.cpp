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
ll get(ll a, ll b, ll d){
	if(a>b) return 0;
	ll x = (b-a)/d;
	return x+1;
}
int main () { 
	ll n, x[2222], d[2222], u, ans = 0;
	memset(d, 0, sizeof(d));
	cin >> n >> u;
	for(int i =0; i<n; i++) {
		cin >> x[i];
	}
	for(int i = 1; i<n; i++){
		ll z = get(x[i], x[i-1], u);
		x[i] += z * 1ll * u;
		ans += z;
	}
	cout << ans;
	return 0;
}