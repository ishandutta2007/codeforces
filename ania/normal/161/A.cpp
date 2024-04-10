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

#define maxn 100100

pair<int,int> a[maxn], b[maxn];
vector<pair<int,int> > res;

int main()
{
	int n,m,x,y;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	FOR(i,n) scanf("%d", &a[i].fi);
	FOR(i,n) a[i].se = i;
	FOR(i,m) scanf("%d", &b[i].fi);
	FOR(i,m) b[i].se = i;
	sort(a,a+n);
	sort(b,b+m);
	int i = 0, j = 0;
	while(i < n && j < m)
	{	
		if(a[i].fi - x <= b[j].fi && b[j].fi <= a[i].fi + y)
		{
			res.pb(mp(a[i].se, b[j].se));
			i++;
			j++;
		}
		else if(a[i].fi - x > b[j].fi)
			j++;
		else
			i++;
	}
	printf("%d\n", res.size());
	FOREACH(k,res)
		printf("%d %d\n", k->fi+1, k->se+1);
	return 0;
}