#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef __int64 LL;
typedef unsigned __int64 ULL;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) {if(a>(b)) a=(b);}
#define MAX(a,b) {if(a<(b)) a=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));


struct Tree {
	Tree * l, * r;
	int x, y;
	int cnt;
	LL sum;

	Tree(int xx = 0, int yy = 0)
	{
		cnt = 1;
		l = r = 0;
		sum = x = xx;
		y = yy;
	}

	void Check()
	{
		sum = x;
		cnt = 1;
		if (l != 0)
			cnt += l -> cnt,
			sum += l -> sum;
		if (r != 0)
			cnt += r -> cnt,
			sum += r -> sum;
	}
};

Tree * Merge(Tree * l, Tree * r)
{
	if (l == 0)
		return r;
	if (r == 0)
		return l;
	if (l -> y < r -> y)
	{
		l -> r = Merge(l -> r, r);
		l -> Check();
		return l;
	}
	else
	{
		r -> l = Merge(l, r -> l);
		r -> Check();
		return r;
	}
}

void Split(Tree * t, int x, Tree * &l, Tree * &r)
{
	if (t == 0)
	{
		l = r = 0;
		return ;
	}

	if (x < t -> x)
	{
		Split(t -> l, x, l, t -> l);
		r = t;
	}
	else
	{
		Split(t -> r, x, t -> r, r);
		l = t;
	}

	t -> Check();
}

Tree * Insert(Tree * t, int x, int y)
{
	if (t == 0)
		return new Tree(x, y);
	if (y < t -> y)
	{
		if (x < t -> x)
			t -> l = Insert(t -> l, x, y);
		else
			t -> r = Insert(t -> r, x, y);

		t -> Check();

		return t;
   	}
	else
	{
		Tree * p = new Tree(x, y);
		Split(t, x, p -> l, p -> r);

		p -> Check();

		return p;
    }
}

Tree * Remove(Tree * t, int x)
{
	if (t == 0)
		assert(false);
	if (t -> x == x)
	{
		Tree * p = Merge(t -> l, t -> r);
		delete t;
		return p;
	}

	if (x < t -> x)
		t -> l = Remove(t -> l, x);
	else
		t -> r = Remove(t -> r, x);

	t -> Check();

	return t;
}

int rnd()
{
	return (rand() << 16) ^ rand();
}

int main()
{
#ifdef XDEBUG
	freopen("d.in","r",stdin);
#endif
	int n;
	while(scanf("%d",&n)>0)
	{

		Tree * tot = 0;
		Tree * totl;
		Tree * totr;
		Tree * t[5];
		for(int i=0;i<5;i++)
			t[i]=0;
		Tree * tl[5];
		Tree * tr[5];

		for (int j = 0; j < n; ++j)
		{
			int i,k,x;
			char type[10];
			scanf("%s", type);
			switch (*type)
			{
				case 'a':
					scanf("%d",&x);
					Split(tot,x,totl,totr);
					k=0;
					if(totl) k=(totl->cnt)%5;
					tot=Merge(totl,totr);
					tot = Insert(tot, x, rnd());
					for(i=0;i<5;i++)
						Split(t[i],x,tl[i],tr[i]);
					for(i=0;i<5;i++)
						t[i] = Merge(tl[i],tr[(i+4)%5]);
					t[k] = Insert(t[k], x, rnd());
					break;
				case 'd':
					scanf("%d",&x);
					tot=Remove(tot,x);
					Split(tot,x,totl,totr);
					k=0;
					if(totl) k=(totl->cnt)%5;
					tot=Merge(totl,totr);
					t[k] = Remove(t[k], x);
					for(i=0;i<5;i++)
						Split(t[i],x,tl[i],tr[i]);
					for(i=0;i<5;i++)
						t[i] = Merge(tl[i],tr[(i+1)%5]);
					break;
				case 's':
					LL res=0;
					if(t[2]) res=t[2]->sum;
					printf("%I64d\n", res);
					break;
			}
		}
	}
	return 0;
}