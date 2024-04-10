#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], idx[N], mark[N];
priority_queue<pair<int, int>, vector<pair<int, int> > > pq;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int start=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			int j=0;
			while(!pq.empty())
			{
				idx[++j]=pq.top().second;
				pq.pop();
				if(j<=3)
					mark[idx[j]]=1;
			}
			j=min(j, 3LL);
			sort(idx+1, idx+j+1);
			int ctr=0;
			vector<string> v;
			for(int k=start;k<i;k++)
			{
				if(!mark[k])
				{
					cout<<"pushBack"<<endl;
				}
				else
				{
					ctr++;
					if(ctr==1)
					{
						cout<<"pushStack"<<endl;
						v.push_back("popStack");
					}
					else if(ctr==2)
					{
						cout<<"pushQueue"<<endl;
						v.push_back("popQueue");
					}
					else 
					{
						cout<<"pushFront"<<endl;
						v.push_back("popFront");
					}
				}
			}
			cout<<v.size();
			for(auto it:v)
				cout<<" "<<it;
			cout<<endl;
			start=i+1;
		}
		else
		{
			pq.push({a[i], i});
		}
	}
	for(int k=start;k<=n;k++)
	{
		cout<<"pushStack"<<endl;
	}
	return 0;
}