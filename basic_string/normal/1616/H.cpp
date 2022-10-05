#include<bits/stdc++.h>
using namespace std;
enum{N=150009,M=N*33,P=998244353};
int p[N],n,x,id=1,c[M][2],s[M];
void ins(int v){for(int i=29,b,p=1;++s[p],~i;p=c[p][b],--i)if(b=v>>i&1,!c[p][b])c[p][b]=++id;}
int dfs(int a,int b,int d){
	if(!a||!b)return p[s[a|b]];
	if(a==b){
		if(d<0)return p[s[a]];
		int l=c[a][0],r=c[a][1];
		if(x>>d&1)return dfs(l,r,d-1);
		return (dfs(l,l,d-1)+dfs(r,r,d-1)-1)%P;
	}
	if(d<0)return p[s[a]+s[b]];
	int la=c[a][0],ra=c[a][1],lb=c[b][0],rb=c[b][1];
	if(x>>d&1)return dfs(la,rb,d-1)*1ll*dfs(ra,lb,d-1)%P;
	return ((p[s[la]]-1ll)*(p[s[ra]]-1)+(p[s[lb]]-1ll)*(p[s[rb]]-1)+dfs(la,lb,d-1)+dfs(ra,rb,d-1)-1)%P;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i,j;
	cin>>n>>x;
	for(i=p[0]=1;i<=n;++i)cin>>j,ins(j),p[i]=p[i-1]*2%P;
	cout<<((dfs(1,1,29)-1)%P+P)%P;
	return 0;
}