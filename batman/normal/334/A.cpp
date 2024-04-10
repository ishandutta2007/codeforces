#include <bits/stdc++.h>
using namespace std;
int n,p=1;
int main()
{ 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j+=2)
		{
			cout<<p<<" "<<n*n-p+1<<" ";
			p++;
		}
		cout<<"\n";
			
	}
    return 0;
}