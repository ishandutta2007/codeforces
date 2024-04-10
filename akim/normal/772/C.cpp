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
const int N = int(3e5) + 10, mod = int(1e9)  + 7; 

int n,m;

bool bad[N];

vi g[N], di, rb;
int cnt[N];

int dp[N], from[N];

ll modpow(ll a,ll b, ll c){
	ll res = 1;
	while(b){
		if(b & 1) res =  res * a % c;
		a = a * a % c;
		b >>= 1;
	}
	return res % c;
}

int phi(int n){
	int m = n;
	for(int i=2;i*i<=n;i++){
		if(n%i == 0){
			while(n%i == 0){
				n /= i;
			}
			m -= m/i;
		}
	}
	if (n > 1) m -= m/n;
	return m;
}

int main () {
	scanf("%d%d",&n,&m);
	for(int i = 1,x; i <= n; i++){
		scanf("%d",&x);
		bad[x] = 1;
	}
	for(int i = 0; i < m; i++){
		if(!bad[i]){
			int d = __gcd(i,m);
			g[d].pb(i);
			cnt[d]++;
		}
	}
	for(int i = 1; i <= m; i++){
		if(m % i == 0) di.pb(i);
	}

	int mx = 0, c = 0;
	dp[0] = cnt[di[0]];
	from[0] = -1;
	c = 0;
	mx = dp[0];
	for(int i = 1; i < di.size(); i++){
		int x = di[i];
		dp[i] = 0;
		from[i] = -1;
		for(int j = 0; j < i; j++){
			if(x % di[j] == 0){
				if(dp[i] < dp[j]){
					dp[i] = dp[j];
					from[i] = j;
				}
			}
		}
		dp[i] += cnt[di[i]];
		if(mx < dp[i]){
			mx = dp[i];
			c = i;
		}
	}
	printf("%d\n", mx);
	while(c != -1){
		for(int i = 0; i < g[di[c]].size(); i++){
			rb.pb(g[di[c]][i]);
		}
		c = from[c];
	}
	reverse(rb.begin(), rb.end());
	int ph = phi(m);
	printf("%d ", rb[0]);
	int pref = rb[0];
	for(int i = 1; i < rb.size(); i++){
		int y = rb[i - 1];
		int x = rb[i];
		int gd = __gcd(x,y);
		x /= gd;
		y /= gd;
		pref = pref *(1ll* x * modpow(y, ph - 1, m) % m) % m;
		printf("%d ",1ll*x * modpow(y, ph - 1, m) % m);
	}
return 0;
}