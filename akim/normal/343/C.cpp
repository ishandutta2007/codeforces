#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define LL long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))
typedef pair<int, int> pii;
const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);
long long n,m,x[100100],y[100100];
long long vich(long long i,long long p,long long lg)
{
	long long otv=200000000000000ll;
	if(x[i]>=y[lg]){otv=min(otv,abs(x[i]-y[p]));}
	if(x[i]<=y[p]){otv=min(otv,abs(x[i]-y[lg]));}
	otv=min(otv,min(abs(x[i]-y[lg])+abs(y[lg]-y[p]),abs(x[i]-y[p])+abs(y[lg]-y[p])));
	return(otv);
}
bool doit(long long mid)
{
	long long i,lg;
	for(i=0,lg=0;i<n&&lg<m;i++)
	{
		long long p=lg;
		while(lg<m&&mid>=vich(i,p,lg)){lg++;}
	}
	if(lg==m){return(1);}else{return(0);}
}
int main()
{
//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	scanf("%I64d%I64d",&n,&m);
	long long i;
	for(i=0;i<n;i++){scanf("%I64d",&x[i]);}
	for(i=0;i<m;i++){scanf("%I64d",&y[i]);}
	long long l=2000020000000ll,r=-1,mid;
	while(l-1>r)
	{
		mid=(l+r)/2;
		if(doit(mid))
		{
			l=mid;
		}else
		{
			r=mid;
		}
	}
	printf("%I64d",l);
	return 0;
}