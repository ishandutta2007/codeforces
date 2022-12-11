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

#define inf 1000000000
#define maxn 20202

int n;
int t[maxn];

int get(int d)
{
	if(d < 3) return -inf;
	int res = -inf;
	int k = n/d;
	for(int i = 0; i < k; i++)
	{
		int cur = 0;
		for(int j = 0; j < d; j++)
			cur += t[i+j*k];
		res = max(res, cur);
	}
	return res;
}

int main()
{
	int res = -inf;
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &t[i]);
	for(int d = 1; d*d <= n; d++) if(n % d == 0)
	{
		res = max(res, get(d));
		res = max(res, get(n/d));
	}
	printf("%d\n", res);
	return 0;
}