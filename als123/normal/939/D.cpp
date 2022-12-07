#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
const int N=100005;
int n;
char ss[N],ss1[N];
int f[30];
int find (int x){return f[x]==x?f[x]:f[x]=find(f[x]);}
vector<int> t[N];
int main()
{
	for (int u=1;u<=30;u++) f[u]=u;
	scanf("%d",&n);
	scanf("%s%s",ss+1,ss1+1);
	for (int u=1;u<=n;u++)
	{
		int x=ss[u]-'a',y=ss1[u]-'a';
		f[find(x)]=find(y);
	}
	for (int u=0;u<=26;u++)
	{
		int x=find(u);
		t[x].push_back(u);
	}
	/*for (int u=0;u<=26;u++)
		printf("%d ",t[u].size());*/
	int ans=0;
	for (int u=0;u<=26;u++)	
		if (t[u].size()>=2)
			ans=ans+t[u].size()-1;
	printf("%d\n",ans);
	for (int u=0;u<=26;u++)
		for (int i=1;i<t[u].size();i++)
			printf("%c %c\n",t[u][i]+'a',t[u][i-1]+'a');
	return 0;
}