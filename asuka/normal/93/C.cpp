#include<bits/stdc++.h>
#define ll long long
#define N
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
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
int n,m;
int a[105];
string ans[105];
string get(int i){
	string s = "e";
	s += ('a'+i);
	s += "x";
	return s;
}
bool dfs(int mdep,int dep){
	// printf("%d %d %d\n",mdep,dep,a[dep]);
	if(a[dep] > n) return 0;
	if(dep == mdep){
		// puts("END");
		if(a[dep] != n) return 0;
		cout << mdep << endl;
		rep(i,1,mdep) cout << ans[i] << endl;
		return 1;
	}
	rep(i,0,dep) rep(k,0,3){
		a[dep+1] = a[i]*(1<<k);
		if(dep+1 == mdep && a[dep+1] != n) continue;
		if(a[dep+1] > n) continue;
		ans[dep+1] = "lea " + get(dep+1) + ", [" + (char)('0'+(1<<k)) + "*" + get(i) + "]";
		if(dfs(mdep,dep+1)) return 1;
	}
	rep(i,0,dep) rep(j,0,dep) rep(k,0,3){
		a[dep+1] = a[i] + (1<<k)*a[j];
		if(dep+1 == mdep && a[dep+1] != n) continue;
		if(a[dep+1] > n) continue;
		ans[dep+1] = "lea " + get(dep+1) + ", [" + get(i) + " + " +(char)('0'+(1<<k)) + "*" + get(j) + "]";
		if(dfs(mdep,dep+1)) return 1;
	}
	return 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> n;
	a[0] = 1;
	rep(i,0,10) if(dfs(i,0)) return 0;
	return 0;
}