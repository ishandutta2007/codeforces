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

int n,k;
int a[55];

int main()
{
	scanf("%d%d", &n, &k);
	k--;
	FOR(i,n) scanf("%d", &a[i]);
	FOR(i,n) a[i] = -a[i];
	sort(a,a+n);
	while(k+1 < n && a[k+1] == a[k]) k++;
	while(k >= 0 && a[k] >= 0) k--;
	printf("%d\n", k+1);
	return 0;
}