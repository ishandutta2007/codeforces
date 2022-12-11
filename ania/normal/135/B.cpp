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

struct pt
{
		int x,y;
		pt(int X = 0, int Y = 0) { x=X; y=Y; }
		void read() { scanf("%d%d", &x, &y); }
		int abs() { return x*x + y*y; }
		int operator* (pt a) { return x*a.x + y*a.y;}
		pt operator- (pt a) { return pt(x-a.x, y-a.y); }
};

pt t[11];
int p[11];

int main()
{
		int n = 8;
		FOR(i,n) t[i].read();
		FOR(i,n) p[i] = i;
		do
		{
				bool wrong = 0;
				int dist = (t[p[0]]-t[p[3]]).abs();
				FOR(i,3)
				{
						int cur = (t[p[i]]-t[p[i+1]]).abs();
						if(cur != dist) wrong = 1;
				}
				dist = (t[p[4]]-t[p[7]]).abs();
				int d2 = (t[p[4]]-t[p[5]]).abs();
				if(dist != (t[p[5]]-t[p[6]]).abs()) wrong = 1;
				if(d2 != (t[p[6]]-t[p[7]]).abs()) wrong = 1;
				if(wrong) continue;
				FOR(i,2) if((t[p[i]]-t[p[i+1]])*(t[p[i+1]]-t[p[i+2]]) != 0) wrong = 1;
				REP(i,4,5) if((t[p[i]]-t[p[i+1]])*(t[p[i+1]]-t[p[i+2]]) != 0) wrong = 1;
				if(wrong) continue;
				printf("YES\n");
				FOR(i,4) printf("%d ", p[i]+1);
				printf("\n");
				REP(i,4,7) printf("%d ", p[i]+1);
				printf("\n");
				return 0;
		} while(next_permutation(p,p+n));
		printf("NO\n");
		return 0;
}