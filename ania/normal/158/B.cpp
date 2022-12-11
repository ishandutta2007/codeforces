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

int c[6];

int main()
{
	int n,x;
	scanf("%d", &n);
	FOR(i,n)
	{
		scanf("%d", &x);
		c[x]++;
	}
	int res = c[4];
	c[4] = 0;
	int cur = min(c[3], c[1]);
	res += cur;
	c[3] -= cur;
	c[1] -= cur;
	res += c[3];
	c[3] = 0;
	res += c[2] / 2;
	c[2] = c[2] % 2;
	if(c[2] > 0)
	{
		res++;
		c[2] = 0;
		c[1] -= 2;
		if(c[1] < 0) c[1] = 0;
	}
	res += (c[1] + 3) / 4;
	printf("%d\n", res);
	return 0;
}