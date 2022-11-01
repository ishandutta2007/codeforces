#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (4444)

ll n,v[N],d[N],p[N];
bool mark[N];
vector <ll> ans;
queue <ll> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>v[i]>>d[i]>>p[i];
	for(int i=0;i<n;i++)
		if(!mark[i])
		{
			ans.push_back(i+1);
			for(int j=i+1,ex=0;j<n && ex<v[i];j++)
				if(!mark[j])
				{
					p[j]-=(v[i]-ex);
					if(p[j]<0)mark[j]=1,q.push(j);
					ex++;
				}
			while(q.size())
			{
				ll ex=q.front();
				q.pop();
				for(int j=ex+1;j<n;j++)
					if(!mark[j])
					{
						p[j]-=d[ex];
						if(p[j]<0)mark[j]=1,q.push(j);
					}	
			}	
		}
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";	
    return 0;
}