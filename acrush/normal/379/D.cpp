#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int128)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)

int n,x,l1,l2;
int64 length[128];
int64 c0[128],c1[128],c2[128];
char first[128],last[128];
bool f[128][128][3][3];

void generate(int n,int e,int a,int b,char r[])
{
	r[0]=(char)(a+'A');
	r[n-1]=(char)(b+'A');
	if (n<=2) return;
	for (int c=0;c<3;c++)
	{
		int e2=e-(int)(a==0 && c==2);
		if (e2>=0 && f[n-1][e2][c][b])
		{
			generate(n-1,e2,c,b,r+1);
			return;
		}
	}
}
int main()
{
	memset(f,false,sizeof(f));
	for (n=1;n<128;n++) for (int e=0;e<128;e++) for (int a=0;a<3;a++) for (int b=0;b<3;b++)
		if (n<=2)
			f[n][e][a][b]=(e==(int)(n==2 && a==0 && b==2));
		else
			for (int c=0;c<3;c++)
			{
				int e2=e-(int)(a==0 && c==2);
				if (e2>=0 && f[n-1][e2][c][b]) f[n][e][a][b]=true;
			}
	scanf("%d%d%d%d",&n,&x,&l1,&l2);
	for (first[1]='A';first[1]<='C';first[1]++)
	for (last[1]='A';last[1]<='C';last[1]++)
	for (first[2]='A';first[2]<='C';first[2]++)
	for (last[2]='A';last[2]<='C';last[2]++)
	{
		length[1]=l1;
		length[2]=l2;
		if (l1==1 && first[1]!=last[1]) continue;
		if (l2==1 && first[2]!=last[2]) continue;
		c1[1]=1; c2[1]=0;
		c1[2]=0; c2[2]=1;
		c0[1]=c0[2]=0;
		for (int i=3;i<=n;i++)
		{
			length[i]=length[i-2]+length[i-1];
			c1[i]=c1[i-2]+c1[i-1];
			c2[i]=c2[i-2]+c2[i-1];
			c0[i]=c0[i-2]+c0[i-1];
			if (last[i-2]=='A' && first[i-1]=='C') c0[i]++;
			first[i]=first[i-2];
			last[i]=last[i-1];
		}
		if (c0[n]>x) continue;
		for (int x1=0;x1<128;x1++) if (f[l1][x1][first[1]-'A'][last[1]-'A'])
		for (int x2=0;x2<128;x2++) if (f[l2][x2][first[2]-'A'][last[2]-'A'])
			if (c1[n]*x1+c2[n]*x2+c0[n]==x)
			{
				char r1[128],r2[128];
				generate(l1,x1,first[1]-'A',last[1]-'A',r1);
				generate(l2,x2,first[2]-'A',last[2]-'A',r2);
				r1[l1]=r2[l2]=0;
				printf("%s\n%s\n",r1,r2);
				return 0;
			}
	}
	printf("Happy new year!\n");
	return 0;
}