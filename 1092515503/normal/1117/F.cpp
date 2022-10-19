#include<bits/stdc++.h>
using namespace std;
int n,p,nxt[100100][18],MAXN,cnt[18],res=0x3f3f3f3f;
bool ok[18][18],f[1<<18],mask[1<<18][18][18],g[1<<18];
char s[100100];
void dye(int sta,int a,int b){
	if(!mask[sta][a][b])return;mask[sta][a][b]=f[sta]=false;
	for(int i=0;i<p;i++)if(!(sta&(1<<i))&&i!=a&&i!=b)dye(sta|(1<<i),a,b);
}
int main(){
	scanf("%d%d",&n,&p),memset(nxt,0x3f3f3f3f,sizeof(nxt)),memset(f,true,sizeof(f)),memset(mask,true,sizeof(mask)),MAXN=1<<p;
	scanf("%s",s);
	for(int i=0;i<n;i++)cnt[s[i]-'a']++;
	for(int i=n-2;i>=0;i--){
		for(int j=0;j<p;j++)nxt[i][j]=nxt[i+1][j];
		nxt[i][s[i+1]-'a']=i+1;
	}
//	for(int i=0;i<p;i++){for(int j=0;j<n;j++)printf("%d ",nxt[j][i]);puts("");}
	for(int i=0;i<p;i++)for(int j=0;j<p;j++)scanf("%d",&ok[i][j]);
	for(int i=0;i<n;i++)for(int j=0;j<p;j++){
		if(ok[s[i]-'a'][j]||nxt[i][j]==0x3f3f3f3f||nxt[i][s[i]-'a']<nxt[i][j])continue;
		int sta=0;
		for(int k=0;k<p;k++)if(nxt[i][k]<nxt[i][j])sta|=(1<<k);
//		printf("%d:%d(%d %d)\n",i,sta,s[i]-'a',j);
		dye(sta,s[i]-'a',j);
	}
	g[0]=true;
	for(int i=0;i<MAXN;i++)if(f[i]&&g[i])for(int j=0;j<p;j++)if(!(i&(1<<j))&&f[i|(1<<j)])g[i|(1<<j)]|=g[i];
	for(int i=0;i<MAXN;i++){
		if(!g[i])continue;
		int sum=n;
		for(int j=0;j<p;j++)if(i&(1<<j))sum-=cnt[j];
		res=min(res,sum);
	}
	printf("%d\n",res);
	return 0;
}