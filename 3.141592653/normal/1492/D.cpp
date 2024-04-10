#include<bits/stdc++.h>
// Basic typedefs 
typedef long long ll;
typedef double db;
typedef unsigned unt;
typedef unsigned long long ull;
// STL function usage
using std::min;
using std::max;
using std::swap;
using std::reverse;
using std::sort;
// STL container usage
using std::vector;
using std::set;
using std::multiset;
using std::map;
using std::deque;
using std::queue;
// Basic pair
struct pii
{
	int x,y;
	pii(){}
	pii(int xx,int yy){x=xx,y=yy;}
};
bool operator<(const pii x,const pii y)
{if(x.x^y.x)return x.x<y.x;return x.y<y.y;}
// Main

int n,m,k;
int a[1111111],c[1111111];
ll v[1111111];
char s[1111111],t[1111111];
pii P[1111111];
void exec()
{
	int a,b,k;
	scanf("%d%d%d",&a,&b,&k);
	register int i;
	if(!k)
	{
		puts("Yes");
		for(i=1;i<=b;i++)printf("1");
		for(i=1;i<=a;i++)printf("0");
		puts("");
		for(i=1;i<=b;i++)printf("1");
		for(i=1;i<=a;i++)printf("0");
		puts("");
		return;
	}
	if(!a){puts("No");return;}
	if(b==1){puts("No");return;}
	int d=a+b;
	if(k>d-2){puts("No");return;}
	s[1]=t[1]='1';b--;
	s[2]='1',t[2]='0';
	s[k+2]='0',t[k+2]='1';
	a--,b--;
	for(register int i=2;i<=d;i++)
	{
		if(!s[i])
		{
			if(a){a--,s[i]=t[i]='0';}
			else {b--,s[i]=t[i]='1';}
		}
	}
	puts("Yes");
	puts(s+1);
	puts(t+1);
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}