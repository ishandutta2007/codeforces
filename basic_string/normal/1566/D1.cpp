#include<bits/stdc++.h>
using namespace std;
int m,t[100009];
struct P{
	int x,i;
	bool operator<(P a)const{return x<a.x||(x==a.x&&i>a.i);}
}p[100009];
void add(int x){for(;x<=m;x+=x&-x)++t[x];}
int sum(int x){int r=0;for(;x;x-=x&-x)r+=t[x];return r;}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,i,j,k,ans;
	cin>>T;
	while(T--){
		cin>>n>>m,memset(t,0,m*4+4),ans=0;
		for(i=1;i<=m;++i)cin>>p[i].x,p[i].i=i;
		sort(p+1,p+m+1);
		for(i=1;i<=m;++i)ans+=sum(p[i].i),add(p[i].i);
		cout<<ans<<'\n';
	}
	return 0;
}