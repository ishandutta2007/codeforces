#include<bits/stdc++.h>
using namespace std;
struct apple
{
	int s,a;
	bool operator<(const apple &other)const
	{
		if(max(s,a)!=max(other.s,other.a))
			return max(s,a)<max(other.s,other.a);
		if(s!=other.s)return s<other.s;
		return a<other.a;
	}
}e[500005];
int main()
{
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)scanf("%d%d",&e[i].s,&e[i].a);
	sort(e+1,e+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)if(e[i].s>=d)
	{
		ans++;
		d=max(d,e[i].a);
	}
	cout<<ans<<endl;
	return 0;
}