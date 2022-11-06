#include<bits/stdc++.h>
using namespace std;
int taxi,n,flag=0,la,x;
int main()
{
	cin>>taxi;
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		cin>>n;
		la=0,flag=0;
		cin>>la;
		for(int i=2;i<=n;i++)
		{
			cin>>x;
			if(x>=la)
			{
				//cout<<i<<endl;
				flag=1;
			}
			la=x;
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}