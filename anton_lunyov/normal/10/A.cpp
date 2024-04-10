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

int main()
{
	//freopen("in.txt","r",stdin);
	int n,p1,p2,p3,t1,t2;
	while(scanf("%d%d%d%d%d%d",&n,&p1,&p2,&p3,&t1,&t2)>0)
	{
		int l[111],r[111];
		int i;
		for(i=0;i<n;i++) scanf("%d%d",&l[i],&r[i]);
		int ans=0;
		for(i=0;i<n;i++)
		{
			ans+=p1*(r[i]-l[i]);
			int dt=i>0?l[i]-r[i-1]:0;
			if(dt<=t1) ans+=p1*dt; else
			{
				ans+=p1*t1;
				dt-=t1;
				if(dt<=t2) ans+=p2*dt; else
				{
					ans+=p2*t2;
					dt-=t2;
					ans+=p3*dt;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}