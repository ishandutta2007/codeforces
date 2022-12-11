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

int a[100100];

int main()
{
		int n;
		scanf("%d", &n);
		FOR(i,n) scanf("%d", &a[i]);
		sort(a,a+n);
		if(n == 1)
		{
				if(a[0] == 1) printf("2\n");
				else printf("1\n");
				return 0;
		}
		FOR(i,n)
		{
				if(i == n-1)
				{
						if(a[i] > 1) printf("%d\n", a[i-1]);
						else printf("2\n");
				}
				else if(i == 0)
				{
						printf("1 ");
				}
				else printf("%d ", a[i-1]);
		}
		return 0;
}