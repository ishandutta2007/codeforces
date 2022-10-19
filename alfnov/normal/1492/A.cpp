#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b,c,d;
		cin>>a>>b>>c>>d;
		cout<<min(min(b-(a-1)%b-1,c-(a-1)%c-1),d-(a-1)%d-1)<<endl;
	}
	return 0;
}