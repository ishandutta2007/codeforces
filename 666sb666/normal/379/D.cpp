#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=55;
struct Str
{
	LL s1,s2,s12,s21,s11,s22,h,t;
}s[N];
int k,x,n,m;
inline Str merge(Str a,Str b)
{
	return (Str){a.s1+b.s1,a.s2+b.s2,a.s12+b.s12+(a.t==1&&b.h==2),a.s21+b.s21+(a.t==2&&b.h==1),a.s11+b.s11+(a.t==1&&b.h==1),a.s22+b.s22+(a.t==2&&b.h==2),a.h,b.t};
}
inline void printA(int x){for(int i=1;i<=x;i++)printf("A");}
inline void printB(int x){for(int i=1;i<=x;i++)printf("B");}
inline void printC(int x){for(int i=1;i<=x;i++)printf("C");}
inline void printAC(int x){for(int i=1;i<=x;i++)printf("AC");}
inline void work1(int x,int y)
{
	printAC(x);printA(n-2*x);puts("");
	printAC(y);printA(m-2*y);puts("");
	exit(0);
}
inline void work2(int x,int y)
{
	printAC(x);printA(n-2*x);puts("");
	printC(1);printA(m-2*y-1);printAC(y);puts("");
	exit(0);
}
inline void work3(int x,int y)
{
	printC(1);printA(n-2*x-1);printAC(x);puts("");
	printAC(y);printA(m-2*y);puts("");
	exit(0);
}
inline void work4(int x,int y)
{
	printC(1);printAC(x);printA(n-2*x-1);puts("");
	printC(1);printAC(y);printA(m-2*y-1);puts("");
	exit(0);
}
inline void work5(int x,int y)
{
	printAC(x);printA(n-2*x);puts("");
	printC(1);printAC(y);printA(m-2*y-1);puts("");
	exit(0);
}
inline void work6(int x,int y)
{
	printAC(x);printB(n-2*x);puts("");
	printC(1);printAC(y);printA(m-2*y-1);puts("");
	exit(0);
}
inline void work7(int x,int y)
{
	printC(1);printAC(x);printC(n-2*x-1);puts("");
	printC(1);printAC(y);printA(m-2*y-1);puts("");
	exit(0);
}
int main()
{
	scanf("%d%d%d%d",&k,&x,&n,&m);
	s[1]=(Str){1,0,0,0,0,0,1,1};
	s[2]=(Str){0,1,0,0,0,0,2,2};
	for(int i=3;i<=k;i++)s[i]=merge(s[i-2],s[i-1]);
	for(int i=0;i<=n/2;i++)
		for(int j=0;j<=m/2;j++)
		{
			if(s[k].s1*i+s[k].s2*j==x)work1(i,j);
			if((j||(!j&&2*j+1==m))&&2*i+1<=n&&2*j+1<=m&&s[k].s1*i+s[k].s2*j+s[k].s12==x)work2(i,j);
			if(2*i+1<=n&&2*j+1<=m&&s[k].s1*i+s[k].s2*j+s[k].s21==x)work3(i,j);
			if(2*i+2<=n&&2*j+2<=m&&s[k].s1*i+s[k].s2*j+s[k].s12+s[k].s21+s[k].s22==x)work4(i,j);
			if(2*i+1<=n&&2*j+2<=m&&s[k].s1*i+s[k].s2*j+s[k].s12+s[k].s22==x)work5(i,j);
			if(2*i<=n&&2*j+2<=m&&s[k].s1*i+s[k].s2*j+s[k].s22==x)work6(i,j);
			if(2*i+1<=n&&2*j+2<=m&&s[k].s1*i+s[k].s2*j+s[k].s21+s[k].s22==x)work7(i,j);
		}
	puts("Happy new year!");
	return 0;
}