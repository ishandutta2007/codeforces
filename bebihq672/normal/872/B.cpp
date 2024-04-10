#include<iostream>
using namespace std;
int a[101010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(k==1)
	{
		int mi=a[1];
		for(int i=1;i<=n;i++)
			mi=min(mi,a[i]);
		cout<<mi<<endl;
	}
	else if(k==2)
	{
		cout<<max(a[1],a[n])<<endl;
	}
	else
	{
		int ma=a[1];
		for(int i=1;i<=n;i++)
			ma=max(ma,a[i]);
		cout<<ma<<endl;
	}
	return 0;
}