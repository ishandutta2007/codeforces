#include <iostream>

#define M 1010

using namespace std;

int n,p[M],x,a[M],m=0,e[M],l=1;
bool u[M];

void read(void){
	cin>>n>>x;
	for (int i=1; i<=n; ++i){
		cin>>p[i];
		e[p[i]]++;
	}
}

void dfs(void){
	for (int i=1; i<=n; ++i)
	if (e[i]==0){
		int k=1,y=i;
		bool fl=0;
		while (p[y]!=0){
			if (y==x)
			fl=1;
			y=p[y],k++;
		}
		if (y==x)
		fl=1;
		if (!fl)
		a[m++]=k;
	}
	
	while (p[x]!=0)
	x=p[x],l++;
	
	u[0]=1;
	for (int i=0; i<m; ++i)
	for (int j=n; j>=a[i]; --j)
	u[j]|=u[j-a[i]];
	
	for (int i=0; i<=n; ++i)
	if (u[i])
	cout<<i+l<<"\n";
}

int main()
{
	read();
	dfs();	
	return 0;
}