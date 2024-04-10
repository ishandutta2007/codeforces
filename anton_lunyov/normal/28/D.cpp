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

struct item
{
	int ind,v,c,l;
	item(){}
	item(int ind_,int v_,int c_,int l_){ind=ind_;v=v_;c=c_;l=l_;}
};

#define N 101010

vector<item> a[3*N];
int res;
VI ans;

map<int,PII> f;
int next[N];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,s,i;
	while(scanf("%d",&n)>0)
	{
		for(s=0;s<3*N;s++) a[s].cl;
		for(i=0;i<n;i++)
		{
			int v,c,l,r;
			scanf("%d%d%d%d",&v,&c,&l,&r);
			a[c+l+r].pb(item(i+1,v,c,l));
		}
		res=0;
		ans.cl;
		for(s=0;s<3*N;s++) if(a[s].sz)
		{
			f.cl;
			int m=a[s].sz;
			f[s]=mp(0,inf);
			for(i=m-1;i>=0;i--)
			{
				int l=a[s][i].l;
				int c=a[s][i].c;
				int v=a[s][i].v;
				int cnt=l+c;
				if(f.find(cnt)==f.end()) continue;
				int val=v+f[cnt].first;
				next[i]=f[cnt].second;
				if(f[l].first<val)
					f[l]=mp(val,i);
			}
			if(res<f[0].first)
			{
				res=f[0].first;
				ans.cl;
				for(i=f[0].second;i<inf/2;i=next[i])
					ans.pb(a[s][i].ind);
			}
		}
		printf("%d\n",ans.sz);
		for(i=0;i<ans.sz;i++)
			printf("%d%c",ans[i],i<ans.sz-1?' ':'\n');
	}
	return 0;
}