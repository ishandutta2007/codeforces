#include <bits/stdc++.h>
#pragma GCC optimize "O3"

using namespace std;

int n, m, a, b, c, l, wie, gg;
int odw[100001];
int kol[100001];
int gle[100001];
int kr[200001][3];
vector <int> v_kr;
vector <pair <int, int> > v[100001];
long double dok=1e-7, sum, bp, bk, bs1, bs2, sum1, sum2, zli;
long double wyn[100001];
bitset <200001> kr_odw, kr_odw2;
int que[400001];
int sq;

bool dfs_bi(int x, int k)
{
	odw[x]=l;
	kol[x]=k;
	bool ret=true;
	for(auto i:v[x])
	{
		if(odw[i.first]==l)
		{
			if(kol[i.first]==k)
			{
				ret=false;
			}
		}
		else
		{
			if(!dfs_bi(i.first, k^1))
			{
				ret=false;
			}
		}
	}
	return ret;
}

bool dfs_det(int x)
{
	odw[x]=l;
	for(auto i:v[x])
	{
		if(odw[i.first]==l)
		{
			if(abs(wyn[x]+wyn[i.first]-kr[i.second][2])>dok)
			{
				return false;
			}
		}
		else
		{
			wyn[i.first]=kr[i.second][2]-wyn[x];
			if(!dfs_det(i.first))
			{
				return false;
			}
		}
	}
	return true;
}

bool dfs_det_wie(int x)
{
	odw[x]=l;
	++wie;
	bool ret=true;
	for(auto i:v[x])
	{
		if(odw[i.first]==l)
		{
			if(abs(wyn[x]+wyn[i.first]-kr[i.second][2])>dok)
			{
				ret=false;
			}
		}
		else
		{
			wyn[i.first]=kr[i.second][2]-wyn[x];
			if(!dfs_det_wie(i.first))
			{
				ret=false;
			}
		}
	}
	return ret;
}

void dfs_det_sum(int x)
{
	sq=1;
	que[1]=x;
	odw[x]=l;
	int dx;
	while(sq)
	{
		dx=que[sq];
		--sq;
		sum+=abs(wyn[dx]);
		for(auto i:v[dx])
		{
			if(odw[i.first]<l)
			{
				wyn[i.first]=kr[i.second][2]-wyn[dx];
				++sq;
				que[sq]=i.first;
				odw[i.first]=l;
			}
		}
	}
}

void dfs_gle(int x, int gl)
{
	if(a)
	{
		return;
	}
	odw[x]=l;
	gle[x]=gl;
	for(auto i:v[x])
	{
		if(odw[i.first]<l)
		{
			kr_odw[i.second]=1;
			dfs_gle(i.first, gl+1);
		}
		else if(!kr_odw[i.second] && !((gle[x]^gle[i.first])&1))
		{
			a=x;
			b=i.first;
			c=i.second;
			return;
		}
	}
}

bool dfs_zli(int x, int r)
{
	odw[x]=l;
	if(x==gg)
	{
		return true;
	}
	for(auto i:v[x])
	{
		if(odw[i.first]<l && kr_odw[i.second])
		{
			if(dfs_zli(i.first, r^1))
			{
				if(r)
				{
					zli-=kr[i.second][2];
				}
				else
				{
					zli+=kr[i.second][2];
				}
				return true;
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		v[a].push_back({b, i});
		v[b].push_back({a, i});
		kr[i][0]=a;
		kr[i][1]=b;
		kr[i][2]=c;
	}
	++l;
	for(int i=1; i<=n; ++i)
	{
		if(!odw[i])
		{
			if(dfs_bi(i, 0))
			{
				wyn[i]=0.0;
				wie=0;
				++l;
				if(dfs_det_wie(i))
				{
					bp=-2*wie;
					bk=2*wie;
					while(abs(bk-bp)>dok)
					{
						bs1=(bk+bp)/2;
						bs2=bs1+1e-7;
						wyn[i]=bs1;
						sum=0;
						++l;
						dfs_det_sum(i);
						sum1=sum;
						wyn[i]=bs2;
						sum=0;
						++l;
						dfs_det_sum(i);
						sum2=sum;
						if(sum1<sum2)
						{
							bk=bs1;
						}
						else
						{
							bp=bs2;
						}
					}
					wyn[i]=bp;
					++l;
					dfs_det(i);
				}
				else
				{
					printf("NO\n");
					return 0;
				}
			}
			else
			{
				++l;
				v_kr.clear();
				a=0;
				dfs_gle(i, 0);
				gg=b;
				zli=kr[c][2];
				++l;
				dfs_zli(a, 0);
				wyn[a]=zli/2;
				++l;
				if(!dfs_det(a))
				{
					printf("NO\n");
					return 0;
				}
			}
		}
	}
	printf("YES\n");
	for(int i=1; i<=n; ++i)
	{
		printf("%.6Lf ", wyn[i]);
	}
	return 0;
}