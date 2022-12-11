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

int lucky(int x)
{
	int res = 0;
	FORI(k,9) FOR(i,1<<k)
	{
		int q=0;
		FOR(j,k) if(i&(1<<j)) q=q*10+4; else q=q*10+7;
		if(q<=x) res++;
	}
	return res;
}

bool islucky(int x)
{
	while(x)
	{
		if(x%10 != 4 && x%10 != 7) return 0;
		x /= 10;
	}
	return 1;
}

int t[33], res[33];
ll f[33];

int main()
{
	int n,k,m;
	scanf("%d%d", &n, &k);
	m = min(n, 14);
	FOR(i,m) t[i] = n-m+i+1;
	int R = lucky(n-m);
	f[0] = 1;
	for(int i = 1; i <= 14; i++) f[i] = f[i-1] * i;
	if(n == m && f[n] < k)
	{
		printf("-1\n");
		return 0;
	}
	k--;
	for(int i = 0; i < m; i++)
	{
		int v = k / f[m-i-1];
		k -= v * f[m-i-1];
		res[i] = t[v];
		for(int j = v; j < m-i; j++) t[j] = t[j+1];
		if(islucky(res[i]) && islucky(n-m+i+1)) R++;
	}
	//FOR(i,m) printf("%d ", res[i]); printf("\n");
	printf("%d\n",R);
	return 0;
}