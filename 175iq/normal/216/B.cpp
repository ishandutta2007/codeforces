#include <bits/stdc++.h>
using namespace std;

typedef long long int longl;

std::vector<int> parent(101,0);
std::vector<int> size(101,1);

int find_set(int a)
{
	if(parent[a]==a)
	{
		return a;
	}
	return parent[a]=find_set(parent[a]);
}

void union_sets(int a,int b)
{
	a=find_set(a);
	b=find_set(b);
	if(a!=b)
	{
		if(size[a]<size[b])
		{
			swap(a,b);
		}
		size[a]+=size[b];
		parent[b]=a;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m,x,y;
	cin>>n>>m;
	for(int i=0;i<101;i++)
	{
	    parent[i]=i;
	    size[i]=1;
	}

	int count=0;
	for (int i = 0; i < m; ++i)
	{
		cin>>x>>y;
		int p=find_set(x);
		int q=find_set(y);
		if(p==q)
		{
			if(size[p]&1)
			{
				count++;
			}
		}
		else
		{
			union_sets(x,y);
		}
	}
	if((n-count)&1)
	{
	    count++;
	}
	cout<<count;
	return 0;
}