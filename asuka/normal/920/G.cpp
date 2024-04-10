#include<bits/stdc++.h>
#define ll long long
#define N 1000015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int T, mu[N], pri[N], tot;
bool notp[N];
void init() {
	mu[1] = 1;
	rep(i, 2, 1000000) {
		if(!notp[i]) {pri[++tot] = i; mu[i] = -1;}
		for(int j = 1; j <= tot && i * pri[j] <= 1000000; ++j) {
			notp[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
			else mu[i * pri[j]] = -mu[i];
		}
	}
}
int calc(int p, int L, int R) {
	int ans = 0;
	for(int i = 1; i * i <= p; ++i) {
		if(p % i) continue;
		ans += mu[i] * (R / i - L / i);
		if(p / i != i) ans += mu[p / i] * (R / (p / i) - L / (p / i));
	}
	return ans;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	init();
	scanf("%d", &T);
	while(T--) {
		int x, p, k;
		scanf("%d%d%d", &x, &p, &k);
		int l = 1, r = 10000000, ans = -1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(calc(p, x, mid) >= k) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}