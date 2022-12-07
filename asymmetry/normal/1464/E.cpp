//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

#define N 1001 * 1000

int n, m, a, b, l, mod=998244353;
int odw[N];
int war[N];
int stp[N];
vector <long long> t;
vector <int> v[N], r[N];
queue <int> que;

int obr(long long a)
{
	int b=mod-2;
	long long k=1;
	while(b)
	{
		if(b&1) k=k*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return k;
}

void fwht(vector<long long> &t)
{
	int n=1;
	while(n<(int)t.size()) n<<=1;
	t.resize(n);
	for(int i=1; i<n; i<<=1)
	{
		for(int j=0; j<n; j+=(i<<1))
		{
			for(int k=0; k<i; ++k)
			{
				long long v=t[i+j+k];
				t[i+j+k]=t[j+k]-v;
				if(t[i+j+k]<0) t[i+j+k]+=mod;
				t[j+k]+=v;
				if(t[j+k]>=mod) t[j+k]-=mod;
			}
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	int w=1;
	while(w*w<=m) ++w;
	t.resize(w+100);
	for(int i=1; i<=m; ++i)
	{
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		r[b].push_back(a);
	}
	for(int i=1; i<=n; ++i)
	{
		stp[i]=v[i].size();
		if(!stp[i]) que.push(i);
	}
	while(!que.empty())
	{
		int x=que.front();
		que.pop();
		++l;
		for(int i:v[x])
		{
			odw[war[i]]=l;
		}
		war[x]=0;
		while(odw[war[x]]==l) ++war[x];
		t[war[x]]+=obr(n);
		if(t[war[x]]>=mod) t[war[x]]-=mod;
		for(int i:r[x])
		{
			--stp[i];
			if(!stp[i]) que.push(i);
		}
	}
	while(!t.back()) t.pop_back();
	//~ printf("%d\n", (int)t.size());
	fwht(t);
	long long odp=0;
	for(long long i:t)
	{
		odp+=obr((1-i*n%mod*obr(n+1)%mod+mod)*(n+1)%mod*t.size()%mod);
		if(odp>=mod) odp-=mod;
	}
	printf("%lld\n", (1-odp+mod)%mod);
	return 0;
}