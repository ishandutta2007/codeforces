#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
char s[510];
int ch[510][2],S,mat[510],rt,f[510][1<<16],n,g[5],h[4],all,A[1<<16],B[1<<16];
stack<int>stk;
int build(int l,int r){
	if(l==r)return l;
	int x=mat[l]+1;
	ch[x][0]=build(l+1,mat[l]-1);
	ch[x][1]=build(mat[r]+1,r-1);
	return x;
}
void ORFMT(int *a,int tp){for(int i=0;i<n;i++)for(int j=0;j<all;j++)if(j&(1<<i))(a[j]+=(mod+tp*a[j^(1<<i)])%mod)%=mod;}
void OR(int *a,int *b,int *c){
	for(int i=0;i<all;i++)A[i]=a[i],B[i]=b[i];
	ORFMT(A,1),ORFMT(B,1);
	for(int i=0;i<all;i++)A[i]=1ll*A[i]*B[i]%mod;
	ORFMT(A,-1);
	for(int i=0;i<all;i++)(c[i]+=A[i])%=mod;
}
void ANDFMT(int *a,int tp){for(int i=0;i<n;i++)for(int j=all-1;j>=0;j--)if(j&(1<<i))(a[j^(1<<i)]+=(mod+tp*a[j])%mod)%=mod;}
void AND(int *a,int *b,int *c){
	for(int i=0;i<all;i++)A[i]=a[i],B[i]=b[i];
	ANDFMT(A,1),ANDFMT(B,1);
	for(int i=0;i<all;i++)A[i]=1ll*A[i]*B[i]%mod;
	ANDFMT(A,-1);
	for(int i=0;i<all;i++)(c[i]+=A[i])%=mod;
}
void dfs(int x){
//	printf("%d\n",x);
	if(!ch[x][0]&&!ch[x][1]){
		if('a'<=s[x]&&s[x]<='d')f[x][h[s[x]-'a']]=1;
		if('A'<=s[x]&&s[x]<='D')f[x][g[s[x]-'A']]=1;
		if(s[x]=='?')for(int i=0;i<4;i++)f[x][g[i]]++,f[x][h[i]]++;
//		printf("%d:",x);for(int i=0;i<all;i++)printf("%d ",f[x][i]);puts("");
		return;
	}
	dfs(ch[x][0]),dfs(ch[x][1]);
	if(s[x]=='&'||s[x]=='?')AND(f[ch[x][0]],f[ch[x][1]],f[x]);
	if(s[x]=='|'||s[x]=='?')OR(f[ch[x][0]],f[ch[x][1]],f[x]);
//	for(int i=0;i<all;i++)printf("%d ",f[x][i]);puts("");
}
int main(){
	scanf("%s",s+1),S=strlen(s+1);
	for(int i=1;i<=S;i++){
		if(s[i]=='(')stk.push(i);
		if(s[i]==')')mat[stk.top()]=i,mat[i]=stk.top(),stk.pop();
	}
	rt=build(1,S);
	scanf("%d",&n),all=1<<n;
	for(int i=0,x;i<n;i++)for(int j=0;j<5;j++)scanf("%d",&x),g[j]|=x<<i;
	for(int i=0;i<4;i++)h[i]=(~g[i])&(all-1);
	dfs(rt);
	printf("%d\n",f[rt][g[4]]);
	return 0;
}