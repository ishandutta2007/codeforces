#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a,b,c,d;
int exgcd (int a,int b,int &x,int &y)
{
	if (a==0)
	{
		x=0;y=1;
		return b;
	}
	int tx,ty;
	int h=exgcd(b%a,a,tx,ty);
	y=tx;x=ty-(b/a)*tx;
	return h; 
}
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if (b<d)
	{
		swap(b,d);swap(a,c);
	}
	//b-d=k2*c-k1*a
	int l=b-d;
	int tx,ty;
	int h=exgcd(c,a,tx,ty);
	if (l%h!=0) {printf("-1");return 0;}
	int k2=(tx*(l/h)%(a/h)+(a/h))%(a/h);
	int k1=(k2*c-l)/a;
	

	
	int lalal=0;
	if (k1<0)
	{
		if ((-k1)%(c/h)==0) lalal=(-k1)/(c/h);
		else lalal=(-k1)/(c/h)+1;
	}
	if (k2<0)
	{
		if ((-k2)%(a/h)==0) lalal=(-k2)/(a/h);
		else lalal=(-k2)/(a/h)+1;
	}
	k1=k1+lalal*(c/h);
	printf("%d\n",k1*a+b);
	return 0;
}