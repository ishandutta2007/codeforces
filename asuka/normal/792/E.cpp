#include<bits/stdc++.h>
#define ll long long
#define N 555
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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
using namespace std;
int n, a[N];
VI get(int x) {
	VI res;
	for(int l = 1, r; l <= x; l = r + 1) {
		r = x / (x / l);
		res.emplace_back(x / l);
		if(x % l == 0 && x / l > 1) res.emplace_back(x / l - 1);
	}
	reverse(all(res));
	res.erase(unique(all(res)), res.end());
	return res;
}
VI getunion(VI x, VI y) {
	VI res;
	int px = 0, py = 0;
	while(px < SZ(x) && py < SZ(y)) {
		if(x[px] == y[py]) {
			res.emplace_back(x[px]);
			px++;
			py++;
		} else if(x[px] < y[py]) px++;
		else py++;
	}
	return res;
}
int main(){
	// freopen("data.in","r",stdin);
	// freopen(".out","w",stdout);
	// clock_t st = clock();
	scanf("%d", &n);
	VI uni;
	rep(i, 1, n) {
		scanf("%d", &a[i]);
// 		VI vec = get(a[i]);
		if(i == 1) uni = get(a[i]);
		else uni = getunion(uni, get(a[i]));
		// printf("uni:\n");
		// for(auto oo : uni) printf("%d ", oo);
		// printf("\n");
	}
	int x = uni.back();
	ll res = 0;
	rep(i, 1, n) {
		if(a[i] % (x + 1) != 0) res++; 
		res += a[i] / (x + 1);
	}
	// cerr << (double) (clock() - st) / CLOCKS_PER_SEC << endl;
	printf("%lld\n", res);
	return 0;
}