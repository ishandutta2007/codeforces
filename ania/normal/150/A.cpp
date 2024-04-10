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

int main()
{
	long long n,N;
	cin >> n;
	N=n;
	vector<int> dv;
	for(int a = 2; 1LL * a*a <= n; a++)
	{
		while(n%a == 0)
		{
			dv.pb(a);
			n /= a;
		}
	}
	if(n != 1) dv.pb(n);
	if(dv.size() < 2)
	{
		printf("1\n0\n");
	}
	else if(dv.size() == 2)
	{
		printf("2\n");
	}
	else
	{
		cout << 1 << endl << 1LL * dv[0] * dv[1] << endl;
	}
	return 0;
}