#include <bits/stdc++.h>

using namespace std;

int n, a, b, c, l, q;
int gle[200001];
int odw[200001];
int pod[200001];
vector <int> v[200001];
long long odp;
priority_queue <int> pq;

void dfs(int x)
{
	odw[x]=l;
	pod[x]=1;
	for(int i:v[x])
	{
		if(odw[i]<l)
		{
			gle[i]=gle[x]+1;
			dfs(i);
			pod[x]+=pod[i];
		}
	}
	pq.push(gle[x]-pod[x]+1);
}

int main()
{
	scanf("%d%d", &n, &q);
	for(int i=1; i<n; ++i)
	{
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	++l;
	dfs(1);
	++l;
	while(q)
	{
		odp+=pq.top();
		pq.pop();
		--q;
	}
	cout<<odp<<endl;
	return 0;
}