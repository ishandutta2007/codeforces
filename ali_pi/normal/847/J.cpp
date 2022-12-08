#include<bits/stdc++.h>

#define N 6000
using namespace std;

int n,m,x,y,a,b,i,v[N];
vector<int>V[N];

bool k(int x,int y)
{
	v[x]=a;
	if(V[x].size()<b)
		return V[x].push_back(y),1;
	for(int i=0,z;
	i<V[x].size();
	i++)if(v[z=V[x][i]]!=a&&k(z,x))
		return V[x][i]=y,1;
		return 0;
}
int main(){
	cin>>n>>m;
	for(;m--;)
	{
		cin>>x>>y;
		if(++a,!k(x,y))
		if(++a,!k(y,x))
		b++,V[x].push_back(y);
	}
	cout<<b<<endl;
	for(x=1;x<=n;x++)
	for(i=0;i<V[x].size();i++)
	printf("%d %d\n",x,V[x][i]);
}