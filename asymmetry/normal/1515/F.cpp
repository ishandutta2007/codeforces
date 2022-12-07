//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

#define N 301 * 1000

int n, m, x, a, b;
int rep[N];
int roz[N];
int kto[N];
long long t[N];
priority_queue <pair <long long, int> > pq;
vector <int> odp;
vector <pair <int, int> > v[N];

int fin(int x)
{
	if(x!=rep[x]) rep[x]=fin(rep[x]);
	return rep[x];
}

bool uni(int a, int b)
{
	a=fin(a);
	b=fin(b);
	if(a==b || t[a]+t[b]<x) return false;
	if(roz[a]<roz[b]) swap(a, b);
	if(v[kto[a]].size()<v[kto[b]].size()) swap(kto[a], kto[b]);
	for(auto i:v[kto[b]]) v[kto[a]].push_back(i);
	t[a]+=t[b]-x;
	roz[a]+=roz[b];
	rep[b]=a;
	return true;
}

int main()
{
	scanf("%d%d%d", &n, &m, &x);
	for(int i=1; i<=n; ++i)
	{
		scanf("%lld", &t[i]);
		rep[i]=i;
		roz[i]=1;
		kto[i]=i;
		pq.push({t[i], i});
	}
	for(int i=1; i<=m; ++i)
	{
		scanf("%d%d", &a, &b);
		v[a].push_back({b, i});
		v[b].push_back({a, i});
	}
	int l=0;
	while(!pq.empty())
	{
		int x=pq.top().second;
		long long war=pq.top().first;
		pq.pop();
		int y=fin(x);
		if(t[y]!=war)
		{
			pq.push({t[y], y});
			continue;
		}
		//~ printf("Y=%d: ", y);
		for(int i=0; i<(int)v[kto[y]].size(); ++i)
		{
			//~ printf("(%d %d) ", fin(v[kto[y]][i].first), v[kto[y]][i].second);
			int w=v[kto[y]][i].second;
			if(uni(y, v[kto[y]][i].first))
			{
				++l;
				odp.push_back(w);
				pq.push({t[fin(y)], fin(y)});
				//~ printf("A\n");
				break;
			}
			else
			{
				swap(v[kto[y]][i], v[kto[y]][v[kto[y]].size()-1]);
				v[kto[y]].pop_back();
				--i;
				continue;
			}
		}
		//~ printf("\n");
	}
	if(l<n-1)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(auto i:odp) printf("%d\n", i);
	return 0;
}