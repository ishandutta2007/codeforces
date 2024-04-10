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
	int n,k;
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	int pos = 0;
	while(1)
	{
		if(pos+1 == n) break;
		if(k == 0) break;
		if(s[pos] == '4' && s[pos+1] == '7')
		{
			if(pos & 1)
			{
				if(pos > 0 && s[pos-1] == '4')
				{
					if(k&1) s[pos] = '7';
					break;
				}
				s[pos] = '7';
				pos--;
				k--;
			}
			else
			{
				if(pos+2 < n && s[pos+2] == '7')
				{
					if(k&1) s[pos+1] = '4';
					break;
				}
				s[pos+1] = '4';
				pos++;
				k--;
			}
		}
		else pos++;
	}
	printf("%s\n", s);
	return 0;
}