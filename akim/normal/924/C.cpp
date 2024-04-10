#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
using namespace std;    
const int N = int(3e5), mod = int(1e9)  + 7; 

int n, a[N], b[N], c[N];

int main () {
	scanf("%d", &n);
	int mx = 0, f = 0;
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		c[i] = a[i];
	}
	mx = 0;
	for(int i = 1; i <= n; i++){
		mx = max(mx, c[i]);
		a[i] = mx;
	}
	ans += a[n] - c[n];
	b[n] = a[n];
	for(int i = n - 1; i > 0; i--){
		b[i] = max(a[i], b[i + 1] - 1);	
		ans += b[i] - c[i];
	}
	cout << ans;
return 0;
}