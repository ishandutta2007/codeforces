#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a>1ll*b*c)puts("-1");
		else if(c<=d)printf("%d\n",a);
		else
		{
			int k=a/(1ll*b*d);
			cout<<1ll*(k+1)*a-1ll*b*d*k*(k+1)/2<<endl;
		}
	}
	return 0;
}