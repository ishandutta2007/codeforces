#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
unordered_map<int,int>mp;
int a[N],b[N],he[N],to[N],ne[N],c;
basic_string<int>w[N];
bool v[N];
void dfs(int x){v[x]=1;for(int i;i=he[x];)he[x]=ne[i],dfs(to[i]),w[c]+=i;}
int main(){
	int t=0,i,j,k,n,s;
	scanf("%d%d",&n,&s);
	for(i=1;i<=n;++i)if(scanf("%d",a+i),b[i]=a[i],!mp[a[i]])mp[a[i]]=++t;
	for(i=1,sort(b+1,b+n+1);i<=n;++i)if(a[i]!=b[i])--s,j=mp[a[i]],k=mp[b[i]],ne[i]=he[j],to[i]=k,he[j]=i;
	if(s<0)puts("-1"),exit(0);
	for(i=1;i<=t;++i)if(!v[i])if(++c,dfs(i),!w[c].size())--c;
	if(!c)puts("0"),exit(0);
	if((s=min(s,c))>1){
		printf("%d\n%d\n",c-s+2,s);
		for(i=s,j=0;i;--i)printf("%d ",w[i].back()),j+=w[i].size();
		for(printf("\n%d\n",j),i=1;i<=s;++i)for(int o:w[i])printf("%d ",o);
		puts("");
	}else printf("%d\n",c),i=1;
	for(;i<=c;++i,puts("")){
		cout<<w[i].size()<<'\n';
		for(int o:w[i])printf("%d ",o);
	}
	return 0;
}