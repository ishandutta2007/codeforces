#include<bits/stdc++.h>
using namespace std;
struct apple
{
	int a,c;
	bool operator<(const apple &other)const
	{
		return a<other.a;
	}
}e[100005];
int main()
{
	long long ans=0;
	int n,dd=0;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d%d",&e[i].a,&e[i].c),ans+=e[i].c;
	sort(e+1,e+n+1);
	for(int i=1;i<n;i++)ans+=max(0,e[i+1].a-(dd=max(dd,e[i].a+e[i].c)));
	cout<<ans<<endl;
	return 0;
}