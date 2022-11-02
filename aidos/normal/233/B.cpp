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
bool check(ll a, int s){
	int y = 0;
	while(a != 0){
		y+=a%10;
		a/=10;
	}
	return y == s;
}
int main () {
	ll n;
	cin >> n;
	vector < ll > v;
	for(int i=1; i<200;i++) {
		ll z = i*i + 4ll * n, sq = (ll) sqrt(1.0 * z);
		if(sq*1ll*sq != z ||  i%2 != sq % 2 || sq <= i) continue;
		ll x = (sq-i) >> 1;
		if(check(x, i)) v.pb(x);
	}
	if(v.size() == 0) cout << -1;
	else {
		sort(v.begin(), v.end());
		cout << v[0];
	}
    return 0;
}