#include<bits/stdc++.h>
using namespace std;
int n,k,r[205]; 
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n*2+1;i++)
		cin>>r[i];
	for(int i=2;i<=n*2&&k;i+=2)
		if(r[i]>r[i-1]+1&&r[i]>r[i+1]+1)
			r[i]--,k--;
	for(int i=1;i<=2*n+1;i++)
		cout<<r[i]<<" ";
    return 0;
}