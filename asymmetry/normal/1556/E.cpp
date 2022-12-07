//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>
#pragma GCC optimize "O3"

using namespace std;

#define N 101 * 1000

struct node
{
	long long war, mn, mx;
};

int n, q, a, b, com;
int t[N];
vector <node> st;

long long zap(int a, int b)
{
	a+=com;
	b+=com;
	long long ret=0;
	vector <int> lf, rg;
	while(a<=b)
	{
		if(a&1)
		{
			lf.push_back(a);
			++a;
		}
		if(!(b&1))
		{
			rg.push_back(b);
			--b;
		}
		a>>=1;
		b>>=1;
	}
	reverse(rg.begin(), rg.end());
	for(int i:rg) lf.push_back(i);
	long long x=0, y=0;
	for(int i:lf)
	{
		if(x+st[i].mn<0) return -1;
		x+=st[i].war;
		long long nad=max(0ll, st[i].mx-y);
		y-=st[i].war-nad;
		ret+=nad;
	}
	if(x!=0) return -1;
	return ret;
}

int main()
{
	scanf("%d%d", &n, &q);
	com=1;
	while(com<n) com<<=1;
	st.resize(com<<1);
	--com;
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &a);
		t[i]-=a;
	}
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &a);
		t[i]+=a;
		st[i+com]={t[i], t[i], t[i]};
	}
	for(int i=com; i; --i)
	{
		int l=i*2;
		int r=l+1;
		st[i]={st[l].war+st[r].war, min(st[l].mn, st[l].war+st[r].mn), max(st[l].mx, st[l].war+st[r].mx)};
	}
	for(int i=1; i<=q; ++i)
	{
		scanf("%d%d", &a, &b);
		printf("%lld\n", zap(a, b));
	}
	return 0;
}