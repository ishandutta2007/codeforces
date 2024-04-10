#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T=1;
	cin>>T;
	while(T--)
	{
		int u,v;
		cin>>u>>v;
		cout<<(1ll*u*v+2)/3<<endl;
	}
	return 0;
}