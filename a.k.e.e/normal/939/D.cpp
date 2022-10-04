#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN=100005,SIGMA=31;

int n;
char s1[MAXN],s2[MAXN];
bool G[SIGMA][SIGMA],vis[SIGMA];
int fa[SIGMA],ru[SIGMA],rv[SIGMA],ans=0;

int getpa(int v)
{
	return v==fa[v]?v:fa[v]=getpa(fa[v]);
}

int main()
{
	#ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%s%s",&n,s1+1,s2+1);
    for(int i=1;i<=n;i++)
    	G[s1[i]-'a'][s2[i]-'a']=true;
    for(int i=0;i<26;i++)fa[i]=i;
    int u,v;
    for(int i=0;i<26;i++)
    	for(int j=0;j<26;j++)
    	{
    		if(!G[i][j] || i==j)continue;
    		u=getpa(i);v=getpa(j);
    		if(u==v)continue;
    		fa[u]=v;
    		ru[++ans]=i;
    		rv[ans]=j;
    	}
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++)
    	printf("%c %c\n",ru[i]+'a',rv[i]+'a');
    return 0;
}