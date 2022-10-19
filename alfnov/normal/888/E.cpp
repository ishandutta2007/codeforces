#include<bits/stdc++.h>
using namespace std;
int aa[105],b1[1<<19],b2[1<<19];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&aa[i]),aa[i]%=m;
	int A=n>>1,B=n+1>>1,a=1<<A,b=1<<B;
	for(int i=1;i<=A;i++)b1[(1<<i-1)]=aa[i];
	for(int i=1;i<a;i++)if(i&i-1)
		b1[i]=(b1[i^(i&-i)]+b1[i&-i])%m;
	for(int i=1;i<=B;i++)b2[(1<<i-1)]=aa[i+A];
	for(int i=1;i<b;i++)if(i&i-1)
		b2[i]=(b2[i^(i&-i)]+b2[i&-i])%m;
	set<int>s;
	s.clear();
	for(int i=0;i<b;i++)
	{
		s.insert(m-1-b2[i]);
		s.insert(2*m-1-b2[i]);
	}
	int ans=0;
	for(int i=0;i<a;i++)
	{
		int x=*(s.lower_bound(b1[i]));
		ans=max(ans,(b1[i]+m-1-x%m)%m);
	}
	cout<<ans<<endl;
	return 0;
}