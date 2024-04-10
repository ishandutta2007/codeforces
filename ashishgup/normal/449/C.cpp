#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int sieve[N], vis[N];
vector<pair<int, int> > ans;

void preprocess()
{
	fill(sieve+2, sieve+N, 1);
	for(int i=2;i<N;i++)
	{
		if(!sieve[i])
			continue;
		for(int j=2;i*j<N;j++)
			sieve[i*j]=0;
	}
}
int32_t main()
{
	IOS;
	preprocess();
	cin>>n;
	for(int i=n/2;i>=2;i--)
	{
		if(!sieve[i])
			continue;
		vector<int> v;
		int cur=i;
		while(cur<=n)
		{
			if(vis[cur])
			{
				cur+=i;
				continue;
			}
			v.push_back(cur);
			vis[cur]=1;
			cur+=i;
		}
		if(v.size()>2 && v.size()%2)
		{
			vis[v[1]]=0;
			v.erase(v.begin()+1, v.begin()+2);
		}
		for(int j=0;j<v.size();j+=2)
		{
			ans.push_back({v[j], v[j+1]});
		}
	}
	cout<<ans.size()<<endl;
	for(auto &it:ans)
		cout<<it.first<<" "<<it.second<<endl;
	return 0;
}