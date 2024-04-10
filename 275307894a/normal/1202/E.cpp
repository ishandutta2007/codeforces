#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int n,m,k,x,y,z,g1[200039],g2[200039],now,flag[200039];
long long tot;
char s[200039],t[200039],b[200039];
struct AC{int son[26],fail;};
struct _ac{
	AC f[200039];int cnt;int ans[200039],flag[200039];
	inline void get(){
	    register int i,now=0;
    	for(i=1;i<=m;i++)now=f[now].son[s[i]-'a']?f[now].son[s[i]-'a']:(f[now].son[s[i]-'a']=++cnt);
    	ans[now]++;
    }
    queue<int> q;
    inline void bfs(){
    	register int i;
    	for(i=0;i<=25;i++) if(f[0].son[i]) q.push(f[0].son[i]);
    	while(!q.empty()){
    		now=q.front();q.pop();
	    	for(i=0;i<=25;i++){
		    	if(f[now].son[i]) f[f[now].son[i]].fail=f[f[now].fail].son[i],q.push(f[now].son[i]);
		    	else f[now].son[i]=f[f[now].fail].son[i];
		    }
	    }
    }
    inline void dfs(int x){
    	if(!x||flag[x])return;flag[x]=1;
    	dfs(f[x].fail);ans[x]+=ans[f[x].fail];
    }
}s1,s2;
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%s",t+1);scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s",s+1),m=strlen(s+1);s1.get();
		for(j=1;j<=m;j++) b[j]=s[m-j+1];
		for(j=1;j<=m;j++) s[j]=b[j];s2.get();
	}
	s1.bfs();s2.bfs();m=strlen(t+1);
	for(i=0;i<=s1.cnt;i++) s1.dfs(i);
	for(i=0;i<=s2.cnt;i++) s2.dfs(i);
	for(now=0,i=1;i<=m;i++){
		now=s1.f[now].son[t[i]-'a'];
		g1[i]=s1.ans[now];
	}
	for(now=0,i=m;i;i--){
		now=s2.f[now].son[t[i]-'a'];
		g2[i]=s2.ans[now];
	}
	for(i=1;i<m;i++) tot+=(long long)g1[i]*g2[i+1];
	printf("%lld\n",tot);
}