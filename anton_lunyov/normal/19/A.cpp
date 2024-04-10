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

pair<PII,pair<int,string> > a[55];

int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	while(scanf("%d",&n)>0)
	{
		MSI sc,zab,prop;
		sc.cl;
		zab.cl;
		prop.cl;
		char tmp[555];
		int i,j;
		for(i=0;i<n;i++) scanf("%s",tmp);
		for(i=0;i<n*(n-1)/2;i++)
		{
			int g1,g2;
			scanf("%s %d:%d",tmp,&g1,&g2);
			string s1="",s2="";
			for(j=0;tmp[j]!='-';j++) s1+=tmp[j];
			for(j++;tmp[j];j++) s2+=tmp[j];
			zab[s1]+=g1;prop[s1]+=g2;
			zab[s2]+=g2;prop[s2]+=g1;
			if(g1>g2) sc[s1]+=3; else
			if(g1==g2) sc[s1]++,sc[s2]++; else
				sc[s2]+=3;
		}
		int k=0;
		for(MSI::iterator it=sc.begin();it!=sc.end();++it)
		{
			string s=it->first;
			a[k++]=mp(mp(sc[s],zab[s]-prop[s]),mp(zab[s],s));
		};
		sort(a,a+n);
		reverse(a,a+n);
		string b[55];
		for(i=0;i<n/2;i++)
			b[i]=a[i].second.second;
		sort(b,b+n/2);
		for(i=0;i<n/2;i++)
			printf("%s\n",b[i].data());
	}
	return 0;
}