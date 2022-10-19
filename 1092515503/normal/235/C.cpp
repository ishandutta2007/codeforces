#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1001000;
int cnt=1;
struct Suffix_Automaton{int ch[26],fa,len;}t[N<<1];
char s[N];
int S,q,sz[N<<1],Z[N];
int Add(int x,int c){
	int xx=++cnt;t[xx].len=t[x].len+1,sz[xx]=1;
	for(;x&&!t[x].ch[c];x=t[x].fa)t[x].ch[c]=xx;
	if(!x){t[xx].fa=1;return xx;}
	int y=t[x].ch[c];
	if(t[y].len==t[x].len+1){t[xx].fa=y;return xx;}
	int yy=++cnt;t[yy]=t[y],t[yy].len=t[x].len+1;
	t[y].fa=t[xx].fa=yy;
	for(;x&&t[x].ch[c]==y;x=t[x].fa)t[x].ch[c]=yy;
	return xx;
}
vector<int>v[N<<1];
void dfs(int x){for(auto y:v[x])dfs(y),sz[x]+=sz[y];}
void Zalgorithm(){
	int Centre=-1,Rpos=-1;
	for(int i=1;i<S;i++){
		if(i<=Rpos)Z[i]=min(Rpos-i,Z[i-Centre]);else Z[i]=0;
		while(i+Z[i]<S&&s[Z[i]]==s[i+Z[i]])Z[i]++;
		if(i+Z[i]>Rpos)Rpos=i+Z[i],Centre=i;
	}
}
ll Cyclical(){
	ll ret=0;
	for(int i=0,j=0,x=1;i<S&&(i+Z[i]<S||!i||S%i);i++){
		if(!x)x=1;
		for(j=max(i,j);j!=i+S;j++)if(t[x].ch[s[j%S]-'a'])x=t[x].ch[s[j%S]-'a'];else break;
//		printf("%d %d %d %d\n",i,j,x,sz[x]);
		if(j==i+S)ret+=sz[x];
		if(j-i==t[t[x].fa].len+1)x=t[x].fa;
	}
	return ret;
}
int main(){
	scanf("%s%d",s,&q),S=strlen(s);
	for(int i=0,las=1;i<S;i++)las=Add(las,s[i]-'a');
	for(int i=2;i<=cnt;i++)v[t[i].fa].push_back(i);
	dfs(1);
//	for(int i=1;i<=cnt;i++)for(int j=0;j<26;j++)if(t[i].ch[j])printf("%d %d %c\n",i,t[i].ch[j],'a'+j);
//	for(int i=1;i<=cnt;i++)printf("%d %d\n",t[i].fa,t[i].len);
//	for(int i=1;i<=cnt;i++)printf("%d ",sz[i]);puts("");
	while(q--){
		scanf("%s",s),S=strlen(s);
		Zalgorithm();
		printf("%lld\n",Cyclical());
	}
	return 0;
}
/*
babbabbabbabbabbabbabbabbabbab
1
abbabbab
*/