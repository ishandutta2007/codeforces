#include <iostream>
#include <vector>
using namespace std;
const int N=102,INF=999999;

int n,m;
char a[N][N];
int k1=INF,k2,k3,k4=INF;
int v,r;
int b[5];
int ans;
int main()
{
	int i,j,k=0;
	cin>>n>>m;
	for(i=0;i<n;++i)
		cin>>a[i];
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			if(a[i][j]=='B')
			{
				k1=min(k1,i);
				k3=max(k3,i);
				k2=max(k2,j);
				k4=min(k4,j);
				++k;
			}
		}
	}
	if(!k)
	{
		cout<<'1'<<endl;
		return 0;
	}
	v=(k2-k4+1);
	r=(k3-k1+1);
	for(i=k1;i<=k3;++i)
		for(j=k4;j<=k2;++j)
			if(a[i][j]=='W')
				++ans;
	if(v-r>0)
	{
		if(k1+(n-k3-1)>=(v-r))
		{
			cout<<ans+(v-r)*v<<endl;
			return 0;
		}

	}
	else
	{
		if(k4+(m-k2-1)>=(r-v))
		{
			cout<<ans+(r-v)*r<<endl;
			return 0;
		}
	}
	cout<<"-1"<<endl;
	return 0;
}