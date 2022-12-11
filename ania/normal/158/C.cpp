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

char cmd[1234];

int main()
{
	int tt;
	vector<string> path;
	scanf("%d", &tt);
	while(tt--)
	{
		scanf("%s", cmd);
		if(cmd[0] == 'p')
		{
			FOREACH(i,path) printf("/%s", i->c_str());
			printf("/\n");
		}
		else
		{
			scanf("%s", cmd);
			if(cmd[0] == '/') path.clear();
			string cur;
			int pos = 0;
			for(; cmd[pos]; pos++) ;
			cmd[pos] = cmd[pos+1] = 0;
			if(cmd[pos-1] != '/') cmd[pos] = '/';
			for(int i = (cmd[0]=='/'); cmd[i]; i++)
			{
				if(cmd[i] == '/')
				{
					if(cur == "..") path.pop_back();
					else path.pb(cur);
					cur = "";
				}
				else
				{
					cur = cur + cmd[i];
				}
			}
		}
	}
	return 0;
}