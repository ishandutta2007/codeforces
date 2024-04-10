#include<bits/stdc++.h>
using namespace std;
int an[10]={0,0,1,2,2,3,2,3,2,3};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n<=9)cout<<an[n]<<endl;
		else
		{
			if(n%2==0)cout<<2<<endl;
			else cout<<3<<endl;
		}
	}
	return 0;
}