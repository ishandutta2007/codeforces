#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>

const int N=2e4+5;
int n,m,k,g,d[55][N],dp[55][N],s[55][N];
int val[N<<2],laz[N<<2];
void build(int day,int l,int r,int x){
	if(l==r){
		val[x]=dp[day][l]+s[day+1][l+k-1]-s[day+1][l-1];
		return;
	}
	int m=l+r>>1;
	build(day,l,m,x<<1);
	build(day,m+1,r,x<<1|1);
	val[x]=max(val[x<<1],val[x<<1|1]);
}
void push(int x){
	if(laz[x]){
		val[x<<1]+=laz[x];
		val[x<<1|1]+=laz[x];
		laz[x<<1]+=laz[x];
		laz[x<<1|1]+=laz[x];
		laz[x]=0;
	}
}
void modify(int l,int r,int ql,int qr,int x,int v){
	if(ql<=l&&r<=qr){
		val[x]+=v;
		laz[x]+=v;
		return;
	}
	int m=l+r>>1;
	push(x);
	if(ql<=m)modify(l,m,ql,qr,x<<1,v);
	if(m<qr)modify(m+1,r,ql,qr,x<<1|1,v);
	val[x]=max(val[x<<1],val[x<<1|1]);
}
void add(int day,int pos){
	if(pos)modify(1,g,max(1,pos-k+1),min(g,pos),1,-d[day][pos]);
}
void del(int day,int pos){
	if(pos)modify(1,g,max(1,pos-k+1),min(g,pos),1,d[day][pos]);
}
int main(){
	cin>>n>>m>>k,g=m-k+1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&d[i][j]),s[i][j]=s[i][j-1]+d[i][j];
	for(int i=1;i<=n;i++){
		if(i>1)for(int j=1;j<k;j++)add(i,j);
		for(int j=1;j+k-1<=m;j++){
			int l=j,r=j+k-1;
			if(i==1)dp[1][j]=s[1][r]-s[1][l-1];
			else del(i,l-1),add(i,r),dp[i][j]=s[i][r]-s[i][l-1]+val[1];
		}
		memset(val,0,sizeof(val));
		memset(laz,0,sizeof(laz));
		if(i<n)build(i,1,g,1);
	}
	int ans=0;
	for(int i=1;i<=g;i++)ans=max(ans,dp[n][i]);
	cout<<ans<<endl;
    return 0;
}