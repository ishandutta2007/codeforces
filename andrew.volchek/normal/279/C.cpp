#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef long long llong;

const int MAXN = 100005;

llong tree_sum2[4*MAXN];
llong tree_sum1[4*MAXN];
pair < llong , int > tree_max[4*MAXN];
int a[MAXN];
int dec_a[MAXN];
int inc_a[MAXN];

void build(int v, int l, int r)
{
	if (l == r)
	{
		tree_max[v].first = a[l-1];
		tree_max[v].second = l;
		tree_sum1[v] = inc_a[l-1];
		tree_sum2[v] = dec_a[l-1];
		return;
	}

	int c = (l + r) / 2;

	build(2*v+0, l, c);
	build(2*v+1, c+1, r);;

	tree_sum1[v]=tree_sum1[v*2+0]+tree_sum1[v*2+1];
	tree_sum2[v]=tree_sum2[v*2+0]+tree_sum2[v*2+1];
	tree_max[v]=max(tree_max[v*2+0],tree_max[v*2+1]);


	
	return;
}
/*
void modify(int v, int l, int r, int i, int d)
{
	if (l == r)
	{
		tree[v] += d;
		return;
	}

	int c = (l + r) / 2;

	if (i <= c)
		modify(2*v+0, l, c, i, d);
	else
		modify(2*v+1, c+1, r, i, d);

	tree[v] = tree[2*v+0] + tree[2*v+1];
}*/

pair<llong,int> res_max ;
llong res_sum1 = 0;
llong res_sum2 = 0;


void sum(int v, int l, int r, int i, int j)
{
	if (i <= l && r <= j)
	{
		res_sum1 += tree_sum1[v];
		res_sum2 += tree_sum2[v];
		res_max = max(res_max,tree_max[v]);
		return;
	}

	int c = (l + r) / 2;

	if (i <= c)
		sum(2*v+0, l, c, i, j);
	if (c < j)
		sum(2*v+1, c+1, r, i, j);
}


int main()
{
	int n, q;

	scanf("%d %d\n", &n, &q);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("\n");

	for(int i=0;i<n-1;i++)
	{
		inc_a[i]=a[i]<=a[i+1];
		dec_a[i]=a[i]>=a[i+1];

	}

	inc_a[n-1]=1;
	dec_a[n-1]=1;

	build(1, 1, n);

	for (int i = 0; i < q; i++)
	{
		
		int l, r;
		scanf("%d %d\n", &l, &r);

		res_max = make_pair(0,0);;
		sum(1,1,n,l,r);
		int curr_max = res_max.second;

		bool good = true;

		if(l<=(curr_max-1))
		{

		
		res_sum1 = 0;
		sum(1,1,n,l,curr_max-1);
		if(res_sum1!=(curr_max-1-l+1))
		{
			good = 0;
		}
		}

		if((curr_max)<=r-1)
		{


			res_sum2 = 0;
			sum(1,1,n,curr_max,r-1);
			if(res_sum2!=(r-1-curr_max+1))
			{
				good = 0;
			}
		}

		if(good)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}

			
	}
}