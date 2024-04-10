#include <stdio.h>
#include <map>
#include <iostream>
using namespace std;

typedef long long ll;

struct Q{
	ll type, x, y;
};

map<ll,ll> hash;
long long a[112345], bitv[212345], bitn[212345];
Q q[112345];

void insert(ll bit[], int pos, ll val)
{
	for(int i = pos; i < 212345; i+= -i&i)
		bit[i] += val;
}

long long get(ll bit[], int pos)
{
	ll retv = 0LL;
	for(int i = pos; i > 0; i -= -i&i)
		retv += bit[i];
	return retv;
}

double foo(double d)
{
	map<ll,ll> ::iterator it = (hash.upper_bound(ll(d)));
	it--;
	return (get(bitn, it->second) * d) - get(bitv, it->second);
}


int
main(void)
{
	ll n, nq, id = 1;
	cin >> n >> nq;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		hash[a[i]] = 0;
	}
	for(int i = 0; i < nq; i++)
	{
		cin >> q[i].type;
		if(q[i].type == 1)
		{
			cin >> q[i].x >> q[i].y;
			hash[q[i].y] = 0;
		}
		else
			cin >> q[i].x;
	}
	for(map<ll,ll>::iterator it = hash.begin(); it != hash.end(); it++)
		it->second = id++;
	for(int i = 0; i < n; i++)
	{
		insert(bitv, hash[a[i]], a[i]);
		insert(bitn, hash[a[i]], 1);
	}
	for(int i = 0; i < nq; i++)
	{
		if(q[i].type == 1)
		{
			q[i].x--;
			insert(bitv, hash[a[q[i].x]], -a[q[i].x]);
			insert(bitn, hash[a[q[i].x]], -1);
			a[q[i].x] = q[i].y;
			insert(bitv, hash[q[i].y], q[i].y);
			insert(bitn, hash[q[i].y], 1);
		}
		else
		{
			double bot = 0.0, top = 1e15, mid;
			while(top-bot > 1e-5)
			{
				mid = (top + bot)/2;
				if(foo(mid) >=(double) q[i].x)
					top = mid;
				else
					bot = mid;
			}
			printf("%.5lf\n", mid);
		}
	}
}