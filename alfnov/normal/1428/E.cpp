#include<bits/stdc++.h>
using namespace std;
long long sol2(int a,int b)
{
	return 1ll*(a%b)*(a/b+1)*(a/b+1)+1ll*(b-a%b)*(a/b)*(a/b);
}
long long sol(int a,int b)
{
	if(a<b)return 0;
	return sol2(a,b-1)-sol2(a,b);
}
struct apple
{
	int gs,fs;
	apple(int gs=0,int fs=0):gs(gs),fs(fs){}
	bool operator<(const apple &other)const
	{
		return sol(gs,fs+1)<sol(other.gs,other.fs+1);
	}
};
priority_queue<apple>pq;
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		pq.push(apple(a,1));
	}
	int sz=n;
	while(sz<k)
	{
		apple ap=pq.top();
		pq.pop();
		ap.fs++;
		sz++;
		pq.push(ap);
	}
	long long ans=0;
	while(pq.size())
	{
		apple ap=pq.top();
		pq.pop();
		ans+=sol2(ap.gs,ap.fs);
	}
	cout<<ans<<endl;
	return 0;
}