#include<bits/stdc++.h>
#define ll long long
#define N 4000015
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
int n, m, f[N], suf[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &m);
	const int mod = m;
	f[n] = 1;
	per(i, 1, n) {
		f[i] += suf[i + 1];
		if(f[i] >= mod) f[i] -= mod;
		for(int z = 2; i * z <= n; z++) {
			f[i] += suf[i * z] - suf[min(n + 1, i * z + z)];
			if(f[i] < 0) f[i] += mod;
			if(f[i] >= mod) f[i] -= mod;
		}
		suf[i] = suf[i + 1] + f[i];
		if(suf[i] >= mod) suf[i] -= mod;
	}
	printf("%d\n", f[1]);
	return 0;
}