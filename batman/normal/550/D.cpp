#include <bits/stdc++.h>
using namespace std;
int k;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>k;
	if(k%2==0)
		return cout<<"NO",0;
	cout<<"YES\n";	
	cout<<2*k+2*(k-1)<<" "<<1+2*(k-1+((k-1)/2)+((k-1)*(k-1)))<<"\n";
	cout<<"1 2\n";
	int p=3+k-1+k-1;
	for(int i=3;i<3+k-1;i++)cout<<"1 "<<i<<"\n";
	for(int i=3+k-1;i<p;i+=2)cout<<i<<" "<<i+1<<"\n";
	for(int i=3;i<3+k-1;i++)for(int j=3+k-1;j<p;j++)cout<<i<<" "<<j<<"\n";
	
	for(int i=p;i<p+k-1;i++)cout<<"2 "<<i<<"\n";
	for(int i=p+k-1;i<p+k-1+k-1;i+=2)cout<<i<<" "<<i+1<<"\n";
	for(int i=p;i<p+k-1;i++)for(int j=p+k-1;j<p+k-1+k-1;j++)cout<<i<<" "<<j<<"\n";	
    return 0;
}