#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

#define M (1<<18)

int tt[M*2+13];
bool lucky[10100];
int seq[100100];
char cmd[33];
int l,r,d;

bool islucky(int x)
{
	while(x)
	{
		if(x%10!=4 && x%10 != 7) return 0;
		x /= 10;
	}
	return 1;
}

void add(int pos, int x)
{
	pos += M;
	while(pos >= 1)
	{
		tt[pos]+=x;
		pos >>= 1;
	}
}

int get(int r)
{
	r += M;
	int res = 0;
	while(r > 1)
	{
		if(r&1) res += tt[r-1];
		r >>= 1;
	}
	return res;
}

int main()
{
	int n,m;
	/*
	n = 100000;
	m = 10000;
	FOR(i,n) seq[i] = 1;
	*/
	scanf("%d%d", &n, &m);
	FOR(i,n) scanf("%d", &seq[i]);
	FOR(i,10000) if(islucky(i)) lucky[i] = 1;
	FOR(i,n) if(lucky[seq[i]]) add(i,1);
	FOR(i,m)
	{
		scanf("%s", cmd);
		if(cmd[0] == 'c')
		{
			scanf("%d%d", &l, &r);
			l--; r--;
			printf("%d\n", get(r+1) - get(l));
		}
		else
		{
			scanf("%d%d%d", &l, &r, &d);
			//l = 1; r = 100000; d = 1;
			l--; r--;
			for(int j = l; j <= r; j++)
			{
				if(lucky[seq[j]]) add(j,-1);
				seq[j] += d;
				if(lucky[seq[j]]) add(j,1);
			}
		}
	}
	return 0;
}