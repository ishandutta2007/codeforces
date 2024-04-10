#include <iostream>
#include <vector>
using namespace std;

int n,m,k,a[200003];
bool z,c[200003];
vector<int> gra[200003];
void nerkel(int t)
{
	a[t]*=-1;
}
void dfs(int x,int y)
{
	int i,h,j;
	if(y!=0)
	{
		printf("%d",x);
		printf(" ");
		nerkel(x);
	}
	for(i=0;i<gra[x].size();i++)
	{
		h=gra[x][i];
		if(!c[h])
		{
			c[h]=true;
			dfs(h,x);
			printf("%d",x);
			printf(" ");
			nerkel(x);
		}
	}
	if(a[x]==-1 && y!=0)
	{
		printf("%d",y);
		printf(" ");
		nerkel(y);
		printf("%d",x);
		printf(" ");
		nerkel(x);
	}
}
int main()
{
	int i,j,x,y;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==-1)
			z=true;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%d",&x);
		scanf("%d",&y);
		gra[x].push_back(y);
		gra[y].push_back(x);
	}
	if(z==false)
	{
		cout<<'1'<<endl;
		return 0;
	}
	c[1]=true;
	cout<<"1 ";
	dfs(1,0);
	if(a[1]==-1)
		cout<<gra[1][0]<<" 1 "<<gra[1][0]<<endl;
	return 0;
}