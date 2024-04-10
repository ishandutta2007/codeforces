#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,k,i,a[N],t[N];
long long ans;
struct str{
	long long a;
	int x;
};
bool operator <(str a,str b)
{
	return a.a<b.a;
}
priority_queue<str> q;
long long cal(long long a,int n)
{
	long long x=a/n;
	return (a%n)*(x+1)*(x+1)+(n-a%n)*x*x;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		t[i]=1;
		ans+=1ll*a[i]*a[i];
		if(a[i]!=1)
			q.push((str){cal(a[i],1)-cal(a[i],2),i});
	}
	k-=n;
	while(k--)
	{
		str x=q.top();
		q.pop();
		ans-=x.a;
		++t[x.x];
		if(t[x.x]!=a[x.x])
			q.push((str){cal(a[x.x],t[x.x])-cal(a[x.x],t[x.x]+1),x.x});
	}
	cout<<ans;
}