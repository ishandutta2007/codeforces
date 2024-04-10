#include <bits/stdc++.h>
using namespace std;

typedef long long int longl;

int find_set(int v, vector<int>& parent) 
{
	if(v == parent[v])
	{
	     return v;
      }
	return parent[v] = find_set(parent[v],parent);
}

void union_sets(int a, int b, vector<int>& parent, vector<int>& size) 
{
    a = find_set(a,parent);
    b = find_set(b,parent);
    if (a != b) 
    {
        if (size[a] < size[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
    return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	cin>>n>>m;

	std::vector<int> parent(n,0);
	std::vector<int> size(n,1);

	for (int i = 0; i < n; ++i)
	{
		parent[i]=i;
	}

	int x,y;
	for (int i = 0; i < m; ++i)
	{	
		cin>>x>>y;	
		union_sets(x-1,y-1,parent,size);
	}	

	int count=0;
	for (int i = 0; i < n; ++i)
	{
		if(parent[i]==i)
		{
			count++;
		}
	}
	long long int ans=pow(2,n-count);
	cout<<ans;
	return 0;
}