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

char s[100100];

int main()
{
		int n,p0=0,p1=0;
		scanf("%s", s);
		for(n=0;s[n];n++) ;
		int nd = n/2, nu = n-nd;
		FOR(i,n) if(s[i] == '0') p0++;
		else if(s[i] == '1') p1++;
		int pz = n-p0-p1;
		if(p1 <= nu-1) printf("00\n");
		if(s[n-1] == '0')
		{
				if(p0 + pz >= nd && nd >= p0) printf("10\n");
		}
		else if(s[n-1] == '1')
		{
				if(p1 + pz >= nu && nu >= p1) printf("01\n");
		}
		else
		{
				if(p1 + pz >= nu && nu >= p1+1) printf("01\n");
				if(p0 + pz >= nd && nd >= p0+1) printf("10\n");
		}
		if(p0 <= nd-1) printf("11\n");
		return 0;
}