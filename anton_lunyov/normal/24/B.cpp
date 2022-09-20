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

typedef map<string,int> MSI;

#define N 55

int a[N]={0,25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

int main()
{
	//freopen("in.txt","r",stdin);
	int T,i;
	while(scanf("%d",&T)>0)
	{
		MSI sc[N];
		for(i=0;i<N;i++) sc[i].cl;
		while(T--)
		{
			int n;
			scanf("%d",&n);
			for(i=1;i<=n;i++)
			{
				char buf[N];
				scanf("%s",buf);
				string s=buf;
				sc[0][s]+=a[i];
				sc[i][s]++;
			}
		}
		string best1=sc[0].begin()->first;
		string best2=sc[0].begin()->first;
		for(MSI::iterator it=sc[0].begin();it!=sc[0].end();++it)
		{
			string s=it->first;
			for(i=0;i<N && sc[i][s]==sc[i][best1];i++)
				;
			if(i<N && sc[i][best1]<sc[i][s]) best1=s;
			for(i=1;i<N && sc[i][s]==sc[i][best2];)
			{
				if(i==1) i=0; else
					if(i==0) i=2; else i++;
			}
			if(i<N && sc[i][best2]<sc[i][s]) best2=s;
		}
		puts(best1.data());
		puts(best2.data());
	}
	return 0;
}