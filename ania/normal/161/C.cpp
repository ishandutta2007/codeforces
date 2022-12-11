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

int len[31];

int rec(int l1, int r1, int l2, int r2, int depth)
{
	if(l1 >= r1) return 0;
	if(l2 >= r2) return 0;
	if(depth == 1) return 1;
	int L = len[depth-1];
	//printf("rec %d %d %d %d %d %d %d, L = %d\n", l1, r1, l2, r2, r1-l1, r2-l2, depth, L);
	if(l1 > L)
	{
		l1 -= L+1;
		r1 -= L+1;
	}
	if(l2 > L)
	{
		l2 -= L+1;
		r2 -= L+1;
	}
	if(l1 <= l2 && r2 <= r1) return r2 - l2;
	if(l2 <= l1 && r1 <= r2) return r1 - l1;
	if(r1 <= L && r2 <= L) return rec(l1, r1, l2, r2, depth-1);
	if(r2 <= L) return max(rec(l1, L, l2, r2, depth-1), rec(0, r1-L-1, l2, r2, depth-1));
	if(r1 <= L) return max(rec(l1, r1, l2, L, depth-1), rec(l1, r1, 0, r2-L-1, depth-1));
	int res = min(r2-l1, r1-l2);
	res = max(res, rec(l1, L, 0, r2-L-1, depth-1));
	res = max(res, rec(l2, L, 0, r1-L-1, depth-1));
	return res;
}

int main()
{
	len[1] = 1;
	for(int i = 1; i <= 30; i++)
		len[i] = len[i-1] * 2 + 1;
	int l1, r1, l2 ,r2;
	scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
	printf("%d\n", rec(l1-1, r1, l2-1, r2, 30));
	return 0;
}