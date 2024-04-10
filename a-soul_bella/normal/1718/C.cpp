#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],f[1000];
priority_queue<int> q1,q2;
void ins(int x)
{
	q1.push(x);
}
void del(int x)
{
	q2.push(x);
}
int ask()
{
	while(!q2.empty()&&q1.top()==q2.top()) q1.pop(),q2.pop();
	return q1.top();
}
vector<int>sum[1005];
bool pr(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return 0;
	return 1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		int n,q;
		cin >> n >> q;
		for(int i=0;i<n;i++)
			cin >> a[i];
		vector<int> v;
		for(int i=1;i<n;i++)
			if(n%i==0&&pr(n/i)) v.push_back(i);
		int nw=0;
		for(int i=0;i<v.size();i++)
			sum[i].clear();
		for(auto t:v)
		{
			for(int i=0;i<t;i++)
			{
				int s=0;
				for(int j=i;j<n;j+=t)
				{
					s+=a[j];
				}
				ins(s*t);
				sum[nw].push_back(s);
			}
			++nw;
		}
		cout << ask() << "\n"; 
		while(q--)
		{
			int p,x;
			cin >> p >> x;
			--p;
			int nw=0;
			for(auto t:v)
			{
				int i=p%t;
				del(sum[nw][i]*(t));
				sum[nw][i]-=a[p];
				sum[nw][i]+=x;
				ins(sum[nw][i]*(t));
				++nw;
			}
			a[p]=x;
			cout << ask() << "\n";
		}
	}
	return 0;
}
/*
1
3
11 5 4
*/