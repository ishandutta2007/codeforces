#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
using namespace std;
const int N=1010000;
long long read(void)
{
	char ch=getchar();long long sum=0;bool f=0;
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-'){f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
	if(f)sum=-sum;return sum;
}
int T,n;long long Ans;
int GCD(int x,int y){return (y==0)?x:GCD(y,x%y);}
int ABS(int x){return x>=0?x:-x;}
struct node
{
	int x,y;
	void init(void)
	{
		if(x==0||y==0)
		{
			if(x==0)y=(y<0?-1:1);
			else x=(x<0?-1:1);return;
		}
		int d=GCD(ABS(x),ABS(y));
		x/=d,y/=d;
		return;
	}
}P[N],V[N],dir[N];
bool operator < (node aa,node bb)
{
	if(aa.x==bb.x)return aa.y<bb.y;
	return aa.x<bb.x;
}
bool operator == (node aa,node bb){return aa.x==bb.x&&aa.y==bb.y;}
node operator - (node aa,node bb)
{
	return (node){aa.x-bb.x,aa.y-bb.y};
}
node rev(node aa){return (node){-aa.x,-aa.y};}
map<node,int>S;
void solve(void)
{
	Ans=0;S.clear();
	n=read();
	for(int i=1;i<=n;i++)
	{
		P[i].x=read();P[i].y=read();
		V[i].x=read();V[i].y=read();
		dir[i]=V[i]-P[i];dir[i].init();S[dir[i]]++;
		if(S.count(rev(dir[i])))Ans+=S[rev(dir[i])];
	}cout<<Ans<<endl;
	return;
}
int main()
{
	T=read();while(T--)solve();
	return 0;
}