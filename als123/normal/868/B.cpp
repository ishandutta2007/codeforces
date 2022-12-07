#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int h,m,s,t1,t2;
int h1,m1,s1;// 
int H,M,S;//  120
int a[3];
int main()
{
	scanf("%d%d%d",&h,&m,&s);
	if (h==12) h=0;
	/*h*/
	H=h*30*120+m*60+s;
	/*M*/
	M=m*6*120+s*12;
	/*S*/
	S=s*6*120;
	
	a[0]=H;a[1]=M;a[2]=S;
	
	sort(a,a+3);
	scanf("%d%d",&t1,&t2);
	if (t1==12) t1=0;
	if (t2==12) t2=0;
	t1=t1*30*120;t2=t2*30*120;
	int A,B;//
	if (t1>a[0]&&t1<a[1]&&t2>a[0]&&t2<a[1]) printf("YES\n");
	else if (t1>a[1]&&t1<a[2]&&t2>a[1]&&t2<a[2]) printf("YES\n");
	else if ((t1>a[2]||t1<a[0])&&(t2>a[2]||t2<a[0])) printf("YES\n");
	else printf("NO\n");
	return 0;
}