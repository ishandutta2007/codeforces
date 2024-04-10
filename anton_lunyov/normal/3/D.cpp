#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

#define bit(n) (1<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef __int64 LL;

#define N 55555

char s[N];
set<PII> st;

int main()
{
	//freopen("in.txt","r",stdin);
	while(scanf("%s",s)>0)
	{
		st.cl;
		int d=0;
		LL val=0;
		bool yes=true;
		int i;
		for(i=0;s[i];i++)
		{
			if(s[i]=='?')
			{
				int a,b;
				scanf("%d%d",&a,&b);
				s[i]=')';
				val+=b;
				st.insert(mp(a-b,i));
			}
			if(s[i]=='(') d++; else d--;
			if(d<0)
			{
				if(!st.sz) yes=false; else
				{
					s[st.begin()->second]='(';
					d+=2;
					val+=st.begin()->first;
					st.erase(st.begin());
				}
			}
		}
		if(!yes || d!=0) puts("-1"); else
			printf("%I64d\n%s\n",val,s);
	}
	return 0;
}