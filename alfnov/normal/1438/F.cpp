#include<bits/stdc++.h>
using namespace std;
int gs[1000005];
priority_queue<pair<int,int> >pq;
int ran()
{
	return 16*rand()+rand();
}
int main()
{
	int h;
	cin>>h;
	int n=(1<<h)-1;
	for(int i=1;i<420;i++)
	{
		int u=ran()%n+1,v=ran()%n+1,w=ran()%n+1;
		while(u==v||u==w||v==w)u=ran()%n+1,v=ran()%n+1,w=ran()%n+1;
		cout<<"?"<<" "<<u<<" "<<v<<" "<<w<<endl;
		int tt;
		cin>>tt;
		gs[tt]++;
	}
	for(int i=1;i<=n;i++)pq.push(make_pair(gs[i],i));
	pair<int,int>p1,p2;
	p1=pq.top(),pq.pop();
	p2=pq.top(),pq.pop();
	int s1=p1.second,s2=p2.second;
	for(int i=1;i<=n;i++)
	{
	    if(i==s1||i==s2)continue;
		cout<<"?"<<" "<<s1<<" "<<s2<<" "<<i<<endl;
		int tt;
		cin>>tt;
		if(tt==i)
		{
			cout<<"!"<<" "<<i<<endl;
			break;
		}
	}
	return 0;
}