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
	ll n, ans = 0, k = 3ll;
	cin >> n;
	while( n % k == 0){
		k  = k * 3ll;
	}
	ll x = n/k;
	ans = x*1ll*k;
	while(ans < n) ans += k;
	cout << ans/k;
    return 0;
}