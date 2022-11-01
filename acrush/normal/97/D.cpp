#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
 
using namespace std;
 
typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
typedef pair<int,int> ipair;
int countbit(int n) {return (n==0)?0:(1+countbit(n&(n-1)));}
int lowbit(int n) {return (n^(n-1))&n;}
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> T sqr(T x) {return x*x;}
template<class T> void checkmin(T &a,T b) {if (b<a) a=b;}
template<class T> void checkmax(T &a,T b) {if (b>a) a=b;}
#define SIZE(X) ((int)((X).size()))
#define LENGTH(X) ((int)((X).length()))
#define MP(A,B) make_pair(A,B)
typedef unsigned int uint;

const int maxk=100000+5;

int n,m,k,dstx,dsty;
uint mask[160][5],state[160][5];
uint blockL[160][5],blockR[160][5],blockU[160][5],blockD[160][5];
char g[160][160];
char cmd[maxk];

bool ck()
{
	for (int i=0;i<n;i++) 
		if (i!=dstx)
		{
			for (int j=0;j<5;j++) if (state[i][j]) return false;
		}
		else
		{
			for (int j=0;j<5;j++) if (j!=(dsty>>5) && state[i][j]) return false;
			if (state[i][dsty>>5]!=(1u<<(dsty&31))) return false;
		}
	return true;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	memset(mask,0,sizeof(mask));
	scanf("%d%d%d",&n,&m,&k);
	memset(blockL,0,sizeof(blockL));
	memset(blockR,0,sizeof(blockR));
	memset(blockU,0,sizeof(blockU));
	memset(blockD,0,sizeof(blockD));
	for (int i=0;i<n;i++)
	{
		scanf("%s",g[i]);
		for (int j=0;j<m;j++)
			if (g[i][j]!='#')
			{
				mask[i][j>>5]|=(1u<<(j&31));
				if (g[i][j]=='E') dstx=i,dsty=j;
			}
	}
	for (int x=0;x<n;x++) for (int y=0;y<m;y++) if (g[x][y]!='#')
	{
		if (g[x][y-1]=='#') blockL[x][y>>5]|=(1u<<(y&31));
		if (g[x][y+1]=='#') blockR[x][y>>5]|=(1u<<(y&31));
		if (g[x-1][y]=='#') blockU[x][y>>5]|=(1u<<(y&31));
		if (g[x+1][y]=='#') blockD[x][y>>5]|=(1u<<(y&31));
	}
	scanf("%s",cmd);
	memcpy(state,mask,sizeof(state));
	if (ck()) 
	{
		printf("0\n");
		return 0;
	}
	for (int step=0;step<k;step++)
	{
		char key=cmd[step];
		if (key=='L')
		{
			uint last=0;
			for (int x=0;x<n;x++) for (int i=4;i>=0;i--)
			{
				uint next=state[x][i]&1;
				state[x][i]=(state[x][i]&blockL[x][i])|(state[x][i]>>1);
				if (last) state[x][i]|=(1u<<31);
				last=next;
			}
		}
		else if (key=='R')
		{
			uint last=0;
			for (int x=0;x<n;x++) for (int i=0;i<5;i++)
			{
				uint next=state[x][i]>>31;
				state[x][i]=(state[x][i]&blockR[x][i])|(state[x][i]<<1)|last;
				last=next;
			}
		}
		else if (key=='U')
		{
			for (int x=0;x<n;x++) 
			{
				for (int i=0;i<5;i++) state[x][i]&=blockU[x][i];
				if (x+1<n) for (int i=0;i<5;i++) state[x][i]|=state[x+1][i];
			}
		}
		else
		{
			for (int x=n-1;x>=0;x--) 
			{
				for (int i=0;i<5;i++) state[x][i]&=blockD[x][i];
				if (x-1>=0) for (int i=0;i<5;i++) state[x][i]|=state[x-1][i];
			}
		}
		for (int x=0;x<n;x++) for (int i=0;i<5;i++) state[x][i]&=mask[x][i];
/*
		for (int x=0;x<n;x++) 
		{
			for (int y=0;y<m;y++) if (state[x][y>>5]&(1u<<(y&31)))
				printf("1");
			else
				printf("0");
			printf("\n");
		}
		printf("\n");
*/
		if (ck()) 
		{
			printf("%d\n",step+1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}