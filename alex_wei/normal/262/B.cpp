#include<bits/stdc++.h>
using namespace std;
int n,k,x[100005],sum,mi=1e4; 
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>x[i],sum+=x[i],mi=min(mi,abs(x[i]));
	sort(x+1,x+n+1);
	for(int i=1;k>0&&x[i]<0;i++,k--)
		sum+=x[i]*-2;
	if(k%2)sum-=mi*2;
	cout<<sum<<endl;
	return 0;
}