#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ans,x;
int main()
{
	cout<<"? ";
	for(int i=1;i<101;i++)
		cout<<i<<" ";
	fflush(stdout);
	cin>>x;
	ans=x-x%128;
	cout<<endl;
	cout<<"? ";
	for(int i=1;i<101;i++)
		cout<<i*128<<" ";
	cout<<endl;
	fflush(stdout);
	cin>>x;
	cout<<"! "<<ans+x%128;
	fflush(stdout);
    return 0;
}