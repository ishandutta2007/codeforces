#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
map<int,int> fa;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
	int n,x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(fa.count(x))x=find(x)+1;
		printf("%d ",x);
		if(fa.count(x+1))fa[x]=x+1;else fa[x]=x;
		if(fa.count(x-1))fa[x-1]=x;
	}
	return 0;
}