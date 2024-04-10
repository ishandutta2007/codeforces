#include<bits/stdc++.h>
using namespace std;
int n,c,d;
const int MAXN = 131072;
int idx1[2*MAXN];
int idx2[2*MAXN];
multiset<int> PD[MAXN];
multiset<int> PC[MAXN];
int b[MAXN];
int p[MAXN];

void setv(int *idx, int a, int v)
{
	a += MAXN;
	idx[a] = v;
	while(a!=1)
	{
		a/=2;
		idx[a] = max(idx[a*2], idx[a*2+1]);
	}
}

int getmax(int *idx, int a, int b)
{
	a += MAXN;
	b += MAXN;
	int ans = 0;
	while(a<=b)
	{
		if(a%2==1) ans = max(ans, idx[a++]);
		if(b%2==0) ans = max(ans, idx[b--]);
		a/=2; b/=2;
	}
	return ans;
}

int main()
{
	scanf("%d%d%d",&n,&c,&d);
	for(int i=0; i<n; ++i)
	{
		char c;
		scanf("%d%d %c",b+i, p+i, &c);
		if(c=='C')
		{
			PC[p[i]].insert(b[i]);
			setv(idx1, p[i], *PC[p[i]].rbegin());
		}
		else
		{
			PD[p[i]].insert(b[i]);
			setv(idx2, p[i], *PD[p[i]].rbegin());
		}
	}
	int ans = 0;
	int ans1 = 0, ans2 = 0;
	for(int i=1; i<=c; ++i)
	{
		if(PC[i].size()==0) continue;
		auto it = PC[i].rbegin();
		int v = *it,v2 = 0;
		ans1 = max(ans1, v);
		++it;
		
		if(it==PC[i].rend()) v2 = 0;
		else v2 = *it;
		setv(idx1, i, v2);
		
		int v3 = getmax(idx1, 0, c-i);

		setv(idx1, i, v);
		if(v3==0) continue;
		ans = max(ans, v3+v);
	}
	for(int i=1; i<=d; ++i)
	{
		if(PD[i].size()==0) continue;
		auto it = PD[i].rbegin();
		int v = *it, v2 = 0;
		ans2 = max(ans2, v);
		++it;
		if(it==PD[i].rend()) v2 = 0;
		else v2 = *it;
		//printf("%d %d\n",v,v2);
		setv(idx2, i, v2);

		int v3 = getmax(idx2, 0, d-i);

		setv(idx2, i, v);

		if(v3==0) continue;
		ans = max(ans, v3+v);
	}
	if(ans1!=0 && ans2!=0) ans = max(ans1+ans2, ans);
	printf("%d\n",ans);
}