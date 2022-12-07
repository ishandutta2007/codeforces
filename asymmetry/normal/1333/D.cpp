#include <bits/stdc++.h>

using namespace std;

int n, k, l, r, a, b;
int t[3011];
int odw[3001];
vector <int> v[2];
vector <int> odp[3000001];
char c;

void sh()
{
	for(int i=1; i<=a; ++i)
	{
		for(int j:odp[i])
		{
			printf("%d ", j);
		}
		printf("\n");
	}
}

void sh_t()
{
	for(int i=1; i<=n; ++i)
	{
		printf("%d ", t[i]);
	}
	printf("\n");
}

int main()
{
	l=0;
	r=1;
	cin>>n>>k;
	t[n+1]=1;
	t[n+2]=1;
	t[n+3]=1;
	for(int i=1; i<=n; ++i)
	{
		cin>>c;
		if(c=='R')
		{
			t[i]=1;
		}
		else
		{
			if(t[i-1])
			{
				v[l].push_back(i-1);
			}
		}
	}
	//sh_t();
	while(!v[l].empty())
	{
		++a;
		v[r].clear();
		for(int i:v[l])
		{
			odp[a].push_back(i);
			++b;
			t[i]^=1;
			t[i+1]^=1;
		}
		for(int i:v[l])
		{
			if(t[i-1] && odw[i-1]<a)
			{
				odw[i-1]=a;
				v[r].push_back(i-1);
			}
			if(t[i+1] && odw[i+1]<a && !t[i+2])
			{
				odw[i+1]=a;
				v[r].push_back(i+1);
			}
		}
		swap(l, r);
		//sh_t();
	}
	//sh();
	if(a>k || b<k)
	{
		printf("-1\n");
		return 0;
	}
	k-=a;
	for(int i=1; i<=a; ++i)
	{
		while(!odp[i].empty())
		{
			if(k)
			{
				if(odp[i].size()>1)
				{
					--k;
				}
				printf("1 %d\n", odp[i].back());
				odp[i].pop_back();
			}
			else
			{
				printf("%d ", (int)odp[i].size());
				for(int j:odp[i])
				{
					printf("%d ", j);
				}
				printf("\n");
				odp[i].clear();
			}
		}
	}
	return 0;
}