#include<bits/stdc++.h>
#define int long long
#define N 70000
#define P 1000000007
#define mid (l+r)/2
using namespace std;
string st;
int n,K,me[17],ge,p;
int fa[501],son[501][2],dp[251][N+1],pb=1,p0[N+1],p1[N+1],p2[N+1];
char dq[501];
void putin(){
	cin>>st;
	cin>>K;
	for(int i=0;i<K;i++){
		for(int j=0;j<4;j++)cin>>p,me[i]|=p*(1<<j);
		cin>>p,ge|=p*(1<<i);
	}
}
void div(int u,int l,int r){
	if(l==r-1){
		dq[u]=st[l];return;
	}
	int nd=0;
	for(int i=l;i<r;i++){
		if(st[i]=='(')nd++;
		else if(st[i]==')')nd--;
		if(!nd&&st[i]!='('&&st[i]!=')'){
			dq[u]=st[i];
			son[u][0]=++pb,div(pb,l+1,i-1);
			son[u][1]=++pb,div(pb,i+2,r-1);
			fa[son[u][0]]=fa[son[u][1]]=u;
		}
	}
}
void fwt(int*x,int l,int r,int nty,int nfl){
	if(l==r-1)return;
	fwt(x,l,mid,nty,nfl),fwt(x,mid,r,nty,nfl);
	if(nty==1){
		if(nfl==1)for(int i=mid;i<r;i++)x[i]=(x[i]+x[i-mid+l])%P;
		else for(int i=mid;i<r;i++)x[i]=(x[i]-x[i-mid+l]+P)%P;
	}else{
		if(nfl==1)for(int i=l;i<mid;i++)x[i]=(x[i]+x[i-l+mid])%P;
		else for(int i=l;i<mid;i++)x[i]=(x[i]-x[i-l+mid]+P)%P;
	}
}
void cal(int u){
	if(!son[u][0]){
		if(dq[u]>='A'&&dq[u]<='Z'){
			int nt=0;
			for(int i=0;i<K;i++)if(me[i]&(1<<(dq[u]-'A')))nt|=(1<<i);
			dp[u][nt]=1;
		}else if(dq[u]>='a'&&dq[u]<='z'){
			int nt=0;
			for(int i=0;i<K;i++)if(!(me[i]&(1<<(dq[u]-'a'))))nt|=(1<<i);
			dp[u][nt]=1;
		}else{
			for(dq[u]='A';dq[u]<='D';dq[u]++){
				int nt=0;
				for(int i=0;i<K;i++)if(me[i]&(1<<(dq[u]-'A')))nt|=(1<<i);
				dp[u][nt]++;
			}
			for(dq[u]='a';dq[u]<='d';dq[u]++){
				int nt=0;
				for(int i=0;i<K;i++)if(!(me[i]&(1<<(dq[u]-'a'))))nt|=(1<<i);
				dp[u][nt]++;
			}
			dq[u]='?';
		}
	}else{
		cal(son[u][0]),cal(son[u][1]);
		if(dq[u]=='|'){
			fwt(dp[son[u][0]],0,(1<<K),1,1),fwt(dp[son[u][1]],0,(1<<K),1,1);
			for(int i=0;i<(1<<K);i++)dp[u][i]+=dp[son[u][0]][i]*dp[son[u][1]][i],dp[u][i]%=P;
			fwt(dp[u],0,(1<<K),1,-1);
		}else if(dq[u]=='&'){
			fwt(dp[son[u][0]],0,(1<<K),2,1),fwt(dp[son[u][1]],0,(1<<K),2,1);
			for(int i=0;i<(1<<K);i++)dp[u][i]+=dp[son[u][0]][i]*dp[son[u][1]][i],dp[u][i]%=P;
			fwt(dp[u],0,(1<<K),2,-1);
		}else{
			for(int i=0;i<(1<<K);i++)p0[i]=dp[son[u][0]][i],p1[i]=dp[son[u][1]][i];
			fwt(dp[son[u][0]],0,(1<<K),1,1),fwt(dp[son[u][1]],0,(1<<K),1,1);
			fwt(p0,0,(1<<K),2,1),fwt(p1,0,(1<<K),2,1);
			for(int i=0;i<(1<<K);i++)dp[u][i]+=dp[son[u][0]][i]*dp[son[u][1]][i],dp[u][i]%=P,p2[i]=p0[i]*p1[i],p2[i]%=P;
			fwt(dp[u],0,(1<<K),1,-1),fwt(p2,0,(1<<K),2,-1);
			for(int i=0;i<(1<<K);i++)dp[u][i]+=p2[i],dp[u][i]%=P;
		}
	}
}
signed main(){
	putin();
	div(1,0,st.size());
	cal(1);
	printf("%lld\n",dp[1][ge]);
	return 0;
}
/*

*/