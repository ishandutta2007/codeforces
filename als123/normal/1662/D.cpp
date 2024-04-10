#include<bits/stdc++.h>
#define N 1100000
#define db double
#define ll long long
#define ldb long double
#define ull unsigned long long
using namespace std;
const int pr=3,ki=149,inf=1e9+7,mo=998244353;
inline int mod(int x){return (x%mo+mo)%mo;}
inline int inc(int x,int k){x+=k;return x<mo?x:x-mo;}
inline int dec(int x,int k){x-=k;return x>=0?x:x+mo;}
inline int ksm(int x,int k)
{
	int ans=1;
	while(k){if(k&1)ans=1ll*ans*x%mo;k>>=1;x=1ll*x*x%mo;}
	return ans;
}
inline int inv(int x){return ksm(x,mo-2);}
inline int read()
{
	char ch=0;int x=0,flag=1;
	while(!isdigit(ch)){ch=getchar();if(ch=='-')flag=-1;}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0',ch=getchar();}
	return x*flag;
}
inline void write(int x)
{
	if(!x)return (void)putchar(48);
	if(x<0)putchar(45),x=-x;
	int len=0,p[20];
	while(x)p[++len]=x%10,x/=10;
	for(int i=len;i>=1;i--)putchar(p[i]+48);
}
inline void writeln(int x){write(x);putchar('\n');}
struct node
{
	int type,len;
};
int go(int type,char ch)
{
	if(type==0)
	{
		if(ch=='A')return 1;
		if(ch=='B')return 2;
	}
	if(type==1)
	{
		if(ch=='A')return 0;
		if(ch=='B')return 3;
	}
	if(type==2)
	{
		if(ch=='A')return 3;
		if(ch=='B')return 0;
	}
	if(type==3)
	{
		if(ch=='A')return 2;
		if(ch=='B')return 1;
	}
}
node GO(node o,char ch)
{
	if(o.len==0)
	{
		if(ch=='C')return {o.type,1};
		else return {go(o.type,ch),0}; 
	}
	if(o.len%2==0)
	{
		if(ch=='A')return {o.type,o.len-1};
		if(ch=='B')return {go(o.type,'B'),o.len};
		if(ch=='C')return {o.type,o.len+1};
	}
	if(o.len%2==1)
	{
		if(ch=='A')return {o.type,o.len+1};
		if(ch=='B')return {go(o.type,'B'),o.len};
		if(ch=='C')return {o.type,o.len-1};
	}
}
char sa[N],sb[N];
void work()
{
	scanf("%s",sa+1);int n=strlen(sa+1);
	scanf("%s",sb+1);int m=strlen(sb+1);
	node A={0,0};
	for(int i=1;i<=n;i++)A=GO(A,sa[i]);
	node B={0,0};
	for(int i=1;i<=m;i++)B=GO(B,sb[i]);
	if(A.type==B.type&&A.len==B.len)printf("YES\n");
	else printf("NO\n");
}
int main()
{
	int t=read();
	for(int i=1;i<=t;i++)work();
	return 0;
}