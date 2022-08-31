#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
int n; pii p[SZ];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*4+1;++i)
	{
		scanf("%d%d",&p[i].fi,&p[i].se);
	}
	for(int i=1;i<=n*4+1;++i)
	{
	int x1=2e9,x2=-2e9,y1=2e9,y2=-2e9;
	for(int j=1;j<=n*4+1;++j) if(i!=j)
	{
		x1=min(x1,p[j].fi);
		x2=max(x2,p[j].fi);
		y1=min(y1,p[j].se);
		y2=max(y2,p[j].se);
	}
	bool ok=1;
	int c1=0,c2=0,c3=0,c4=0;
	for(int j=1;j<=n*4+1;++j) if(i!=j)
	{
		if((p[j].fi==x1||p[j].fi==x2)
		||((p[j].se==y1||p[j].se==y2)))
		{
			if(p[j].fi==x1) ++c1;
			if(p[j].fi==x2) ++c2;
			if(p[j].se==y1) ++c3;
			if(p[j].se==y2) ++c4;
		}
		else ok=0;
	}
	if(ok&&c1>=n&&c2>=n&&c3>=n&&c4>=n&&x2-x1==y2-y1)
	{
		cout<<p[i].fi<<" "<<p[i].se<<"\n";
		return 0;
	}
	}
}