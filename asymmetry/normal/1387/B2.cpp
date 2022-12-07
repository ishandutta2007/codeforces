#include <bits/stdc++.h>

using namespace std;

int n, a, b, l, c, d, e, f, g, h, gg, hh;
int odw[100001];
int pod[100001];
int gle[100001];
int sko[100001];
vector <int> av, bv;
vector <int> v[100001];
vector <int> lu[100001];
vector <int> mi[100001];
long long odp;
priority_queue <pair <int, int> > pq1, pq2;

#define D if(0)

void dfs_pod(int x)
{
	odw[x]=l;
	pod[x]=1;
	for(int i:v[x])
	{
		if(odw[i]<l)
		{
			dfs_pod(i);
			pod[x]+=pod[i];
		}
	}
}

void dfs_gle(int x, int gl)
{
	odw[x]=l;
	gle[x]=gl;
	lu[b].push_back(x);
	mi[b].push_back(x);
	for(int i:v[x])
	{
		if(odw[i]<l)
		{
			dfs_gle(i, gl+1);
		}
	}
}

void dfs1(int x)
{
	odw[x]=l;
	av.push_back(x);
	pod[x]=2;
	for(int i:v[x])
	{
		if(odw[i]<l)
		{
			dfs1(i);
			pod[x]+=pod[i];
		}
	}
	//~ odp+=pod[x];
}

void dfs2(int x)
{
	odw[x]=l;
	bv.push_back(x);
	pod[x]=2;
	for(int i:v[x])
	{
		if(odw[i]<l)
		{
			dfs2(i);
			pod[x]+=pod[i];
		}
	}
	//~ odp+=pod[x];
}

void dfss(int x, int pop=0, int dl=0)
{
	odp+=dl;
	for(int i:v[x]) if(i!=pop) dfss(i, x, dl+1);
}

int main()
{
	scanf("%d", &n);
	for(int i=1; i<n; ++i)
	{
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	if(n==2)
	{
		printf("2\n2 1\n");
		return 0;
	}
	++l;
	dfs_pod(1);
	a=1;
	b=1;
	++l;
	while(b)
	{
		b=0;
		odw[a]=l;
		for(int i:v[a])
		{
			if(pod[i]>=(n+1)/2 && odw[i]<l)
			{
				a=i;
				b=1;
				break;
			}
		}
	}
	++l;
	dfs_pod(a);
	for(int i:v[a])
	{
		if(pod[i]>=(n+1)/2)
		{
			b=i;
			break;
		}
	}
	if(b)
	{
		odw[b]=1e9;
		++l;
		dfs1(a);
		odw[a]=1e9;
		++l;
		dfs2(b);
		for(int i=0; i<n>>1; ++i)
		{
			sko[av[i]]=bv[i];
			sko[bv[i]]=av[i];
		}
		//~ odp-=n;
		dfss(a);
		odp<<=1;
		printf("%lld\n", odp);
		for(int i=1; i<=n; ++i)
		{
			printf("%d ", sko[i]);
		}
		return 0;
	}
	b=0;
	odw[a]=1e9;
	++l;
	D printf("a=%d;\n", a);
	for(int i:v[a])
	{
		++b;
		dfs_gle(i, 1);
	}
	for(int i=1; i<=b; ++i)
	{
		D {printf("i=%d; ", i);
		for(int j:lu[i])
		{
			printf("%d ", j);
		}
		printf("\n");}
		pq1.push({lu[i].size(), i}); // ludzie po przydzielenia
		pq2.push({mi[i].size(), i}); // miejsca do przydzialu
	}
	for(int i=1; i<n; ++i)
	{
		if(pq1.size()==2)
		{
			if(pq2.size()==1)
			{
				c=pq1.top().first;
				d=pq1.top().second;
				pq1.pop();
				e=pq2.top().first;
				f=pq2.top().second;
				pq2.pop();
				if(d==f)
				{
					g=pq2.top().first;
					h=pq2.top().second;
					pq2.pop();
					swap(e, g);
					swap(f, h);
					pq2.push({g, h});
				}
				sko[lu[d].back()]=mi[f].back();
				lu[d].pop_back();
				mi[f].pop_back();
				if(c>1)
				{
					pq1.push({c-1, d});
				}
				if(e>1)
				{
					pq2.push({e-1, f});
				}
			}
			else
			{
				c=pq1.top().first;
				d=pq1.top().second;
				pq1.pop();
				e=pq1.top().first;
				f=pq1.top().second;
				pq1.pop();
				g=pq2.top().first;
				h=pq2.top().second;
				pq2.pop();
				gg=pq2.top().first;
				hh=pq2.top().second;
				pq2.pop();
				if(d==h)
				{
					pq1.push({e, f});
					pq2.push({g, h});
					sko[lu[d].back()]=mi[hh].back();
					lu[d].pop_back();
					mi[hh].pop_back();
					if(c>1)
					{
						pq1.push({c-1, d});
					}
					if(gg>1)
					{
						pq2.push({gg-1, hh});
					}
				}
				else if(d==hh)
				{
					pq1.push({e, f});
					pq2.push({gg, hh});
					sko[lu[d].back()]=mi[h].back();
					lu[d].pop_back();
					mi[h].pop_back();
					if(c>1)
					{
						pq1.push({c-1, d});
					}
					if(g>1)
					{
						pq2.push({g-1, h});
					}
				}
				else if(f==h)
				{
					pq1.push({e, f});
					pq2.push({gg, hh});
					sko[lu[d].back()]=mi[h].back();
					lu[d].pop_back();
					mi[h].pop_back();
					if(c>1)
					{
						pq1.push({c-1, d});
					}
					if(g>1)
					{
						pq2.push({g-1, h});
					}
				}
				else if(f==hh)
				{
					pq1.push({e, f});
					pq2.push({g, h});
					sko[lu[d].back()]=mi[hh].back();
					lu[d].pop_back();
					mi[hh].pop_back();
					if(c>1)
					{
						pq1.push({c-1, d});
					}
					if(gg>1)
					{
						pq2.push({gg-1, hh});
					}
				}
				else
				{
					pq1.push({e, f});
					pq2.push({gg, hh});
					sko[lu[d].back()]=mi[h].back();
					lu[d].pop_back();
					mi[h].pop_back();
					if(c>1)
					{
						pq1.push({c-1, d});
					}
					if(g>1)
					{
						pq2.push({g-1, h});
					}
				}
			}
		}
		else
		{
			c=pq1.top().first;
			d=pq1.top().second;
			pq1.pop();
			e=pq2.top().first;
			f=pq2.top().second;
			pq2.pop();
			if(d==f)
			{
				g=pq2.top().first;
				h=pq2.top().second;
				pq2.pop();
				swap(e, g);
				swap(f, h);
				pq2.push({g, h});
			}
			sko[lu[d].back()]=mi[f].back();
			lu[d].pop_back();
			mi[f].pop_back();
			if(c>1)
			{
				pq1.push({c-1, d});
			}
			if(e>1)
			{
				pq2.push({e-1, f});
			}
		}
	}
	if(a==1)
	{
		sko[a]=sko[2];
		sko[2]=a;
	}
	else
	{
		sko[a]=sko[1];
		sko[1]=a;
	}
	for(int i=1; i<=n; ++i)
	{
		odp+=gle[i]+gle[sko[i]];
	}
	printf("%lld\n", odp);
	for(int i=1; i<=n; ++i)
	{
		printf("%d ", sko[i]);
	}
	return 0;
}