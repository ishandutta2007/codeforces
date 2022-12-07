#include <bits/stdc++.h>

using namespace std;

int n, m, q, rb, a, b, ndw;
int kr[200011][2];
int rep[200011];
int roz[200011];
int odl[200011];
int bip[200011];
int rlb[2000000][4];
int odp[200011];

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

void uni(int a, int b)
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
				++ndw;
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
}

void roll_back()
{
	int w1=rlb[rb][0], w2=rlb[rb][1], w3=rlb[rb][2], w4=rlb[rb][3];
	--rb;
	if(!w1)
	{
		--bip[w2];
		if(!bip[w2])
		{
			--ndw;
		}
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
	uni(kr[x][0], kr[x][1]);
	return ndw;
}

void rek(int l, int ll, int r, int rr)
{
	if(l>ll)
	{
		return;
	}
	int mid=(l+ll)/2;
	for(int i=l; i<mid; ++i)
	{
		add(i);
	}
	int pr=rr;
	while(true)
	{
		add(pr);
		--pr;
		if(ndw || pr<r)
		{
			roll_back();
			++pr;
			break;
		}
	}
	odp[mid]=pr;
	for(int i=pr; i<rr; ++i)
	{
		roll_back();
	}
	for(int i=l; i<mid; ++i)
	{
		roll_back();
	}
	if(l==ll)
	{
		return;
	}
	for(int i=rr; i>pr; --i)
	{
		add(i);
	}
	rek(l, mid-1, r, pr);
	for(int i=rr; i>pr; --i)
	{
		roll_back();
	}
	for(int i=l; i<=mid; ++i)
	{
		add(i);
	}
	rek(mid+1, ll, max(mid+1, pr), rr);
	for(int i=l; i<=mid; ++i)
	{
		roll_back();
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for(int i=1; i<=n+1; ++i)
	{
		rep[i]=i;
		roz[i]=1;
		bip[i]=0;
		odl[i]=0;
	}
	for(int i=1; i<=m; ++i)
	{
		scanf("%d%d", &kr[i][0], &kr[i][1]);
	}
	kr[m+1][0]=0;
	kr[m+1][1]=n+1;
	rek(1, m, 1, m+1);
	for(int i=1; i<=q; ++i)
	{
		scanf("%d%d", &a, &b);
		if(b>=odp[a])
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}