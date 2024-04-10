#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=5010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
#define int ll
int a[N];
int work(int l,int r,int base){
	if(l>r)return 0;
	int p=min_element(a+l,a+r+1)-a;
	return min(r-l+1,
		work(l,p-1,a[p])+a[p]-base+work(p+1,r,a[p]));
}
void Solve(){
	int n=read();
	repeat(i,0,n)a[i]=read();
	printf("%lld\n",work(0,n-1,0));
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	while(T--)Solve();
	return 0;
}