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
typedef pair<int,int> PII;

#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) {if(a>(b)) a=(b);}
#define MAX(a,b) {if(a<(b)) a=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

map<string,int> tt;

int type(string a)
{
	int i;
	int n1=0;
	for(i=0;a[i]=='&';i++) n1++;
	string w="";
	for(;i<a.sz && a[i]!='*';i++) w+=a[i];
	int n2=0;
	for(;i<a.sz;i++) n2++;
	if(!tt.count(w) || tt[w]<0) return -1;
	int res=tt[w]+n2-n1;
	if(res<0) res=-1;
	return res;
}

void print(int t)
{
	if(t<0) puts("errtype"); else
	{
		printf("void");
		while(t--) printf("*");
		printf("\n");
	}
}

int main()
{
#ifdef XDEBUG
	freopen("b.in","r",stdin);
#endif
	int n;
	while(cin >> n)
	{
		tt.cl;
		tt["void"]=0;
		tt["errtype"]=-1;
		while(n--)
		{
			string op,A;
			cin >> op >> A;
			int a=type(A);
			if(op=="typeof")
				print(a);
			else
			{
				string w;
				cin >> w;
				tt[w]=a;
			}
		}
	}
	return 0;
}