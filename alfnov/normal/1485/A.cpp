#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,ans=INT_MAX;
		cin>>a>>b;
		for(int c=0;c<=5;c++)
		{
			if(b+c==1)continue;
			int aa=a,bb=b+c,gs=c;
			while(aa)aa/=bb,gs++;
			ans=min(ans,gs);
		}
		cout<<ans<<endl;
	}
	return 0;
}