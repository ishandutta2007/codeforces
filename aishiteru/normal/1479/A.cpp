#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=998244353,E=262144;
int n,x;
int Q(int x)
{
	int y;
	cout<<'?'<<' '<<x<<endl;
	cin>>y;
	return y;
}
int main()
{
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	int l=1,r=n;
	while(l<r)
	{
		int mid=l+r>>1;
		if(Q(mid)<Q(mid+1))
			r=mid;
		else
			l=mid+1;
	}
	cout<<'!'<<' '<<l<<endl;
}