#include<bits/stdc++.h>
using namespace std;
enum{N=1048599};
int l[N],r[N],rt,mn[N],mx[N],ans[N],len[N],id,w[N];
void up(int p){
	mn[p]=min(mn[l[p]],mn[r[p]]+len[p]),mx[p]=max(mx[l[p]],mx[r[p]]+len[p]);
	ans[p]=min(min(ans[l[p]],ans[r[p]]),mn[r[p]]+len[p]-mx[l[p]]);
}
void ins(int&p,int v,int t){
	if(!p){
		if(p=++id,t<0){mn[p]=mx[p]=0;return;}
		len[p]=1<<t;
	}
	ins((v>>t&1)?r[p]:l[p],v,t-1),up(p);
}
void flip(int p,int t2,int t){
	if(t>t2)flip(l[p],t2,t-1),flip(r[p],t2,t-1);else swap(l[p],r[p]);
	up(p);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,m,k,i,j,o;
	cin>>n>>k,m=1<<k,memset(ans,9,N*4),memset(mn,9,N*4),memset(mx,-9,N*4);
	for(i=1;i<=n;++i)cin>>j,ins(rt,j,k-1);
	for(w[0]=ans[rt],i=1;i<m;++i){
		for(j=o=0;j<k;++j)if(o|=(i>>j&1)<<(k-j-1),(i-1>>k-j-1&1)!=(i>>k-j-1&1))flip(rt,j,k-1);
		w[o]=ans[rt];
	}
	for(i=0;i<m;++i)cout<<w[i]<<' ';
	return 0;
}