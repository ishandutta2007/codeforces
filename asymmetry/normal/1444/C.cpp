#include <bits/stdc++.h>

using namespace std;

int n, m, k, a, b, rb, l;
int t[500001];
int rep[500001];
int roz[500001];
int odl[500001];
int bip[500001];
int kr[500001][2];
int rlb[500001][4];
map <pair <int, int>, vector <int> > mp;
long long odp;

int fin(int x, int &gl)
{
	gl^=odl[x];
	while(x!=rep[x])
	{
		x=rep[x];
		gl^=odl[x];
	}
	return x;
}

bool uni(int a, int b)
{
	int oda=0, odb=0;
	int fa=fin(a, oda);
	int fb=fin(b, odb);
	if(roz[fa]<roz[fb])
	{
		swap(a, b);
		swap(fa, fb);
	}
	++rb;
	if(fa==fb)
	{
		if(oda==odb)
		{
			rlb[rb][0]=0;
			rlb[rb][1]=fa;
			rlb[rb][2]=fb;
			if(!bip[fa])
			{
				++bip[fa];
				return true;
			}
			++bip[fa];
		}
		else
		{
			rlb[rb][0]=1;
			rlb[rb][1]=a;
			rlb[rb][2]=b;
		}
	}
	else
	{
		odl[fb]^=oda^odb^1;
		roz[fa]+=roz[fb];
		rep[fb]=fa;
		rlb[rb][0]=2;
		rlb[rb][1]=fa;
		rlb[rb][2]=fb;
		rlb[rb][3]=oda^odb^1;
	}
	return false;
}

void roll_back()
{
	int w1=rlb[rb][0], w2=rlb[rb][1], w3=rlb[rb][2], w4=rlb[rb][3];
	--rb;
	if(!w1)
	{
		--bip[w2];
	}
	else if(w1&2)
	{
		odl[w3]^=w4;
		roz[w2]-=roz[w3];
		rep[w3]=w3;
	}
}

bool add(int x)
{
	return uni(kr[x][0], kr[x][1]);
}

int dp[500001];

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &t[i]);
		rep[i]=i;
		roz[i]=1;
	}
	for(int i=1; i<=m; ++i)
	{
		scanf("%d%d", &a, &b);
		kr[i][0]=a;
		kr[i][1]=b;
		if(t[a]==t[b])
		{
			dp[t[a]]+=add(i);
		}
		else
		{
			if(t[a]>t[b])
			{
				swap(a, b);
			}
			mp[{t[a], t[b]}].push_back(i);
		}
	}
	int dx=k;
	for(int i=1; i<=k; ++i)
	{
		if(dp[i])
		{
			--dx;
		}
	}
	odp=(long long)dx*(dx-1)/2;
	l=rb;
	for(auto i:mp)
	{
		if(dp[i.first.first] || dp[i.first.second])
		{
			continue;
		}
		vector <int> tym=i.second;
		int xd=0;
		for(int j:tym)
		{
			if(add(j))
			{
				xd=1;
				break;
			}
		}
		odp-=xd;
		while(rb>l)
		{
			roll_back();
		}
	}
	printf("%lld\n", odp);
	return 0;
}