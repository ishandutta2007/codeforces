#include<cstdio>
#include<cstring>
#include<queue>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int t,n,m,k,x,y,z,ans[10039],flag[10039],cnt,dp[2][5039],tot=1e9,a[1039],last,nows,now;
struct ac{int son[13],fail;}f[10039];
char s[1039];
inline int check(int now){
	register int i,j,ans=0;
	for(i=1;i<=now;i++){
		for(ans=0,j=i;j<=now;j++) {
			ans+=a[j];
			if(ans!=x&&x%ans==0) return 0;
		}
	}
	return 1;
}
inline void get(int x){
	register int i;now=0;
	for(i=1;i<=x;i++) now=f[now].son[a[i]]?f[now].son[a[i]]:(f[now].son[a[i]]=++cnt);ans[now]++;
}
inline void dfs(int now,int sum){
	if(sum>x) return;
 	if(sum==x){if(check(now-1))get(now-1);return;}
 	for(int i=1;i<=9;i++)a[now]=i,dfs(now+1,sum+i),a[now]=0;
} 
queue<int> q;
inline void bfs(){
	register int i;
	for(i=1;i<=9;i++) if(f[0].son[i]) q.push(f[0].son[i]);
	while(!q.empty()){
		now=q.front();q.pop();
		for(i=1;i<=9;i++) {
			if(f[now].son[i]) f[f[now].son[i]].fail=f[f[now].fail].son[i],q.push(f[now].son[i]);
			else f[now].son[i]=f[f[now].fail].son[i];
		}
	}
}
inline void find(int x){
	if(!x||flag[x]) return;flag[x]=1;
	find(f[x].fail);ans[x]|=ans[f[x].fail];
}
int main(){
	//freopen("1.in","r",stdin);
	register int i,j;
	scanf("%s",s+1);n=strlen(s+1);scanf("%d",&x);
	dfs(1,0);bfs();
	for(i=1;i<=n;i++) find(i);
	memset(dp,0x3f,sizeof(dp));dp[0][0]=0;
	for(now=0,i=0;i<n;i++){
		nows=i&1;last=nows^1;
		for(j=0;j<=cnt;j++) dp[last][j]=1e9+7;
 		for(j=0;j<=cnt;j++){
			if(dp[nows][j]>=1e9) continue;
   			now=f[j].son[s[i+1]-'0'];
			dp[last][j]=min(dp[nows][j]+1,dp[last][j]);
			if(!ans[now]) dp[last][now]=min(dp[last][now],dp[nows][j]);
		}
	}
	for(i=0;i<=cnt;i++)tot=min(tot,dp[n&1][i]);
	printf("%d\n",tot);
}