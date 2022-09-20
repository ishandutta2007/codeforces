#include <stdio.h>
#include <time.h>
#include <assert.h>
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

typedef __int64 LL;
typedef unsigned __int64 ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef pair<double,double> PDD;

const int inf=1000000000;
const LL INF=LL(inf)*inf;
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
	freopen("d.in","r",stdin);
#endif
	int n,m,k,i,j;
	scanf("%d%d%d",&n,&m,&k);
	{
		bool winR=0,winG=0;
		int sg[32]={0};
		for(i=0;i<n;i++)
		{
			char s[111];
			scanf("%s",s);
			int numG=0,numR=0;
			int posG=-1,posR=-1;
			for(j=0;j<m;j++)
			{
				if(s[j]=='G') numG++,posG=j;
				if(s[j]=='R') numR++,posR=j;
			}
			if(numG==0 && numR==0) continue;
			if(numG==0 && numR<m) winR=1;
			if(numR==0 && numG<m) winG=1;
			if(posR>=0 && posG>=0)
			{
				int h=0;
				for(int x=abs(posG-posR)-1;x;x/=2)
				{
					sg[h]=(sg[h]+x%2)%(k+1);
					h++;
				}
			}
		}
		if(winR && winG) puts("Draw"); else
		if(winR) puts("Second"); else
		if(winG) puts("First"); else
		{
			int s=0;
			for(i=0;i<32;i++)
				s+=sg[i];
			puts(s?"First":"Second");
		}
	}
	return 0;
}