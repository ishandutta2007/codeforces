#include <bits/stdc++.h>

using namespace std;

#define INF 1000000001

int gh, n1, n2, n3, a, bp, bk, bs, bs1, bs2, poz;
int bl[300010][3];
int t1[100010];
int t2[100010];
int t3[100010];
pair <int, int> t[300001];
long long odp;

long long roz(int a, int b, int c)
{
	return (long long)(a-b)*(a-b)+(long long)(b-c)*(b-c)+(long long)(c-a)*(c-a);
}

int fin(int a, int b, int c)
{
	int x, y;
	if(c==0)
	{
		bp=0;
		bk=n1+1;
		bs=(bp+bk)>>1;
		while(bp<bs)
		{
			if(t1[bs]<a)
			{
				bp=bs;
			}
			else
			{
				bk=bs;
			}
			bs=(bp+bk)>>1;
		}
		x=bs+1;
		bp=0;
		bk=n1+1;
		bs=(bp+bk)>>1;
		while(bp<bs)
		{
			if(t1[bs]<=b)
			{
				bp=bs;
			}
			else
			{
				bk=bs;
			}
			bs=(bp+bk)>>1;
		}
		y=bs;
		if(!x || x>n1 || !y || y>n1)
		{
			return -1;
		}
		bp=x;
		bk=y+1;
		bs=(bp+bk)>>1;
		while(bk-bp>8)
		{
			if(roz(a, b, t1[bs])<roz(a, b, t1[bs+1]))
			{
				bk=bs;
			}
			else
			{
				bp=bs;
			}
			bs=(bp+bk)>>1;
		}
		long long rz=4e18;
		for(int i=bp; i<=bk; ++i)
		{
			if(i<=n1)
			{
				long long g=roz(a, b, t1[i]);
				if(rz>g)
				{
					rz=g;
					poz=i;
				}
			}
		}
	}
	if(c==1)
	{
		bp=0;
		bk=n2+1;
		bs=(bp+bk)>>1;
		while(bp<bs)
		{
			if(t2[bs]<a)
			{
				bp=bs;
			}
			else
			{
				bk=bs;
			}
			bs=(bp+bk)>>1;
		}
		x=bs+1;
		bp=0;
		bk=n2+1;
		bs=(bp+bk)>>1;
		while(bp<bs)
		{
			if(t2[bs]<=b)
			{
				bp=bs;
			}
			else
			{
				bk=bs;
			}
			bs=(bp+bk)>>1;
		}
		y=bs;
		if(!x || x>n2 || !y || y>n2)
		{
			return -1;
		}
		bp=x;
		bk=y+1;
		bs=(bp+bk)>>1;
		while(bk-bp>8)
		{
			if(roz(a, b, t2[bs])<roz(a, b, t2[bs+1]))
			{
				bk=bs;
			}
			else
			{
				bp=bs;
			}
			bs=(bp+bk)>>1;
		}
		long long rz=4e18;
		for(int i=bp; i<=bk; ++i)
		{
			if(i<=n2)
			{
				long long g=roz(a, b, t2[i]);
				if(rz>g)
				{
					rz=g;
					poz=i;
				}
			}
		}
	}
	if(c==2)
	{
		bp=0;
		bk=n3+1;
		bs=(bp+bk)>>1;
		while(bp<bs)
		{
			if(t3[bs]<a)
			{
				bp=bs;
			}
			else
			{
				bk=bs;
			}
			bs=(bp+bk)>>1;
		}
		x=bs+1;
		bp=0;
		bk=n3+1;
		bs=(bp+bk)>>1;
		while(bp<bs)
		{
			if(t3[bs]<=b)
			{
				bp=bs;
			}
			else
			{
				bk=bs;
			}
			bs=(bp+bk)>>1;
		}
		y=bs;
		if(!x || x>n3 || !y || y>n3)
		{
			return -1;
		}
		bp=x;
		bk=y+1;
		bs=(bp+bk)>>1;
		while(bk-bp>8)
		{
			if(roz(a, b, t3[bs])<roz(a, b, t3[bs+1]))
			{
				bk=bs;
			}
			else
			{
				bp=bs;
			}
			bs=(bp+bk)>>1;
		}
		long long rz=4e18;
		for(int i=bp; i<=bk; ++i)
		{
			if(i<=n3)
			{
				long long g=roz(a, b, t3[i]);
				if(rz>g)
				{
					rz=g;
					poz=i;
				}
			}
		}
	}
	return poz;
}

int main()
{
	scanf("%d", &gh);
	for(int hg=0; hg<gh; ++hg)
	{
		scanf("%d%d%d", &n1, &n2, &n3);
		for(int i=1; i<=n1; ++i)
		{
			scanf("%d", &t[i].first);
			t[i].second=0;
			t1[i]=t[i].first;
		}
		for(int i=1; i<=n2; ++i)
		{
			scanf("%d", &t[i+n1].first);
			t[i+n1].second=1;
			t2[i]=t[i+n1].first;
		}
		for(int i=1; i<=n3; ++i)
		{
			scanf("%d", &t[i+n1+n2].first);
			t[i+n1+n2].second=2;
			t3[i]=t[i+n1+n2].first;
		}
		sort(t1+1, t1+1+n1);
		sort(t2+1, t2+1+n2);
		sort(t3+1, t3+1+n3);
		sort(t+1, t+1+n1+n2+n3);
		bl[n1+n2+n3+1][0]=INF;
		bl[n1+n2+n3+1][1]=INF;
		bl[n1+n2+n3+1][2]=INF;
		int xd=0, sm=n1+n2+n3;
		for(int i=1; i<n1; ++i)
		{
			if(t1[i]!=t1[i+1])
			{
				++xd;
				t1[xd]=t1[i];
			}
		}
		++xd;
		t1[xd]=t1[n1];
		n1=xd;
		xd=0;
		for(int i=1; i<n2; ++i)
		{
			if(t2[i]!=t2[i+1])
			{
				++xd;
				t2[xd]=t2[i];
			}
		}
		++xd;
		t2[xd]=t2[n2];
		n2=xd;
		xd=0;
		for(int i=1; i<n3; ++i)
		{
			if(t3[i]!=t3[i+1])
			{
				++xd;
				t3[xd]=t3[i];
			}
		}
		++xd;
		t3[xd]=t3[n3];
		n3=xd;
		/*printf("T1: ");
		for(int i=1; i<=n1; ++i)
		{
			printf("%d ", t1[i]);
		}
		printf("\n");
		printf("T2: ");
		for(int i=1; i<=n2; ++i)
		{
			printf("%d ", t2[i]);
		}
		printf("\n");
		printf("T3: ");
		for(int i=1; i<=n3; ++i)
		{
			printf("%d ", t3[i]);
		}
		printf("\n");*/
		odp=4e18;
		for(int i=sm; i; --i)
		{
			bl[i][0]=bl[i+1][0];
			bl[i][1]=bl[i+1][1];
			bl[i][2]=bl[i+1][2];
			bl[i][t[i].second]=t[i].first;
			//printf("%d %d: %d %d %d\n", t[i].first, t[i].second, bl[i][0], bl[i][1], bl[i][2]);
			if(t[i].second==0)
			{
				if(bl[i][1]!=INF)
				{
					int g=fin(t[i].first, bl[i][1], 2);
					//printf("g=%d\n", g);
					if(g!=-1)
					{
						odp=min(odp, roz(t[i].first, bl[i][1], t3[g]));
					}
				}
				if(bl[i][2]!=INF)
				{
					int g=fin(t[i].first, bl[i][2], 1);
					//printf("g=%d\n", g);
					if(g!=-1)
					{
						odp=min(odp, roz(t[i].first, bl[i][2], t2[g]));
					}
				}
			}
			if(t[i].second==1)
			{
				if(bl[i][0]!=INF)
				{
					int g=fin(t[i].first, bl[i][0], 2);
					//printf("g=%d\n", g);
					if(g!=-1)
					{
						odp=min(odp, roz(t[i].first, bl[i][0], t3[g]));
					}
				}
				if(bl[i][2]!=INF)
				{
					int g=fin(t[i].first, bl[i][2], 0);
					//printf("g=%d\n", g);
					if(g!=-1)
					{
						odp=min(odp, roz(t[i].first, bl[i][2], t1[g]));
					}
				}
			}
			if(t[i].second==2)
			{
				if(bl[i][1]!=INF)
				{
					int g=fin(t[i].first, bl[i][1], 0);
					//printf("g=%d\n", g);
					if(g!=-1)
					{
						odp=min(odp, roz(t[i].first, bl[i][1], t1[g]));
					}
				}
				if(bl[i][0]!=INF)
				{
					int g=fin(t[i].first, bl[i][0], 1);
					//printf("g=%d\n", g);
					if(g!=-1)
					{
						odp=min(odp, roz(t[i].first, bl[i][0], t2[g]));
					}
				}
			}
		}
		printf("%lld\n", odp);
	}
	return 0;
}