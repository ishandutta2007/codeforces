#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <complex>
#pragma comment(linker, "/STACK:266777216")
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef pair<double,double> PDD;

const int inf=1000000000;
//const LL INF=LL(inf)*inf;
const double eps=1e-9;
const double PI=2*acos(0.0);
#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

int main()
{
#ifdef MY_DEBUG
	freopen("c.in","rt",stdin);
#endif
	int n;
	while(scanf("%d",&n)>0)
	{
		map<int,int> cnt;
		int i,j;
		for(i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			cnt[x]++;
		}
		set<PII> a;
		for(map<int,int>::iterator it=cnt.begin();it!=cnt.end();++it)
			a.insert(mp(-(it->second),it->first));
		VVI res;
		while(a.sz>=3)
		{
			PII b[3];
			for(i=0;i<3;i++)
			{
				set<PII>::iterator it=a.begin();
				b[i]=*it;
				a.erase(it);
			}
			VI cur;
			for(i=0;i<3;i++)
			{
				cur.pb(b[i].Y);
				b[i].X++;
				if(b[i].X)
					a.insert(b[i]);
			}
			res.pb(cur);
		}
		printf("%d\n",res.sz);
		for(i=0;i<res.sz;i++)
		{
			sort(all(res[i]));
			reverse(all(res[i]));
			for(j=0;j<3;j++)
				printf("%d%c",res[i][j],j<2?' ':'\n');
		}
	}
	return 0;
}