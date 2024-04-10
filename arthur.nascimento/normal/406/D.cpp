#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define inf (999999999)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 1001000

using namespace std;

struct point {
	long long x,y;
	point(long long x=0,long long y=0): x(x), y(y) {}
	point operator-(point p){
		return point(x-p.x,y-p.y);}
	long long operator%(point p){
		return x*p.y - y*p.x;
	}
}

v[maxn];

long long ccw(point a,point b,point c){
	return (b-a)%(c-a);
}

int st[maxn];
int prof[maxn];
int dp[20][maxn];

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			scanf("%I64d%I64d",&v[i].x,&v[i].y);

		int sz = 1;
		st[0] = n-1;

		for(int i=n-2;i>=0;i--){

			while(sz >= 2){
				if(ccw(v[st[sz-2]],v[st[sz-1]],v[i]) < 0)
					sz--;
				else
					break;
			}

			st[sz++] = i;
			dp[0][i] = st[sz-2];
			prof[i] = 1 + prof[st[sz-2]];

			for(int j=1;j<20;j++)
				dp[j][i] = dp[j-1][dp[j-1][i]];

		}

		int q;
		scanf("%d",&q);

		while(q--){

			int a,b;
			scanf("%d%d",&a,&b), a--, b--;

			if(prof[a] < prof[b]) swap(a,b);
			int dh = prof[a] - prof[b];

			for(int i=0;i<20;i++)
				if(dh & (1<<i))
					a = dp[i][a];

			for(int i=19;i>=0;i--)
				if(dp[i][a] != dp[i][b])
					a = dp[i][a], b = dp[i][b];

			if(a != b)
				a = dp[0][a];

			printf("%d\n",a+1);

		}

}