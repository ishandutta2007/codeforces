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

int n;
char s[1111];
int p[1111];
int same[1111];
int ct[1111];
int r,S;

int main()
{
	scanf("%s", s);
	for(n=0;s[n];n++) ;
	for(int i = 2; i <= n; i++) p[i] = 1;
	for(int i = 2; i*i <= n; i++) if(p[i])
		for(int j = i*i; j <= n; j += i) p[j] = 0;
	for(int i = 2; i*2 <= n; i++) if(p[i])
		for(int j = 1; j*i <= n; j++) if(same[i*j] == 0)
		{
			same[j*i] = 1;
			r++;
		}
	for(int j = 1; 2*j <= n; j++) if(same[2*j] == 0)
	{
		same[2*j] = 1;
		r++;
	}
	bool fnd = 0;
	FOR(i,n) ct[s[i]-'a']++;
	//FOR(i,26) printf("%d ", ct[i]); printf("\n");
	FOR(i,26) if(ct[i] >= r)
	{
		S = i;
		ct[i] -= r;
		fnd = 1;
		break;
	}
	if(!fnd)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	//FOR(i,26) printf("%d ", ct[i]); printf("\n");
	//FORI(i,n) printf("%d", same[i]); printf("\n");
	FORI(i,n)
	{
		if(same[i]) printf("%c", 'a'+S);
		else
		{
			FOR(j,26) if(ct[j] > 0)
			{
				printf("%c", 'a'+j);
				ct[j]--;
				break;
			}
		}
	}
	printf("\n");
	return 0;
}