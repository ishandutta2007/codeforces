#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
#define endl "\n"
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
#define int ll
char s[N],ans[N];
void Solve(){
	scanf("%s",s); int n=strlen(s),x=read();
	repeat(i,0,n)ans[i]='1';
	repeat(i,0,n)
	if(s[i]=='0'){
		if(i-x>=0)ans[i-x]='0';
		if(i+x<n)ans[i+x]='0';
	}
	repeat(i,0,n)
	if(s[i]=='1'){
		if(i-x>=0 && ans[i-x]=='1');
		else if(i+x<n && ans[i+x]=='1');
		else{puts("-1"); return;}
	}
	repeat(i,0,n)putchar(ans[i]);
	puts("");
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	while(T--)Solve();
	return 0;
}