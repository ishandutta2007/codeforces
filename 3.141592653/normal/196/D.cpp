#include<bits/stdc++.h>
int d;
char s[1111111];
char t[1111111];
const int p1=999992023,p2=999989981;
template<int mod>
int qpow(int x,int k)
{int r=1;for(;k;k>>=1,x=x*1ll*x%mod)if(k&1)r=r*1ll*x%mod;return r;}
struct hash
{
	int x1,x2;
	hash(){}
	hash(int x){x1=(x%p1+p1)%p1,x2=(x%p2+p2)%p2;}
	hash(int a,int b){x1=a,x2=b;}
};
hash operator+(const hash&x,const hash&y)
{return hash{(x.x1+y.x1)%p1,(x.x2+y.x2)%p2};}
hash operator+(const hash&x,const int y)
{return hash{(x.x1+y)%p1,(x.x2+y)%p2};}
hash operator-(const hash&x,const hash&y)
{return hash{(x.x1+p1-y.x1)%p1,(x.x2+p2-y.x2)%p2};}
hash operator*(const hash&x,const hash&k)
{return hash{(x.x1*1ll*k.x1)%p1,(x.x2*1ll*k.x2)%p2};}
hash operator*(const hash&x,const int k)
{return hash{(x.x1*1ll*k)%p1,(x.x2*1ll*k)%p2};}
bool operator!=(const hash&x,const hash&y){return x.x1!=y.x1||x.x2!=y.x2;}
const int bas=128;
const hash ibas=hash(qpow<p1>(bas,p1-2),qpow<p2>(bas,p2-2));
hash pw[1111111],ipw[1111111];
struct PREF
{
	hash Prefix[1111111];
	int deg[1111111];
	void ins(int x,int d)
	{deg[x]+=d;hash p=deg[x];Prefix[x]=Prefix[x-1]*bas+p;}
	hash ask(int l,int r)
	{return Prefix[r]-Prefix[l-1]*pw[r-l+1];}
}T1;
const int V=5e5;
struct BIT
{
	hash T[1111111];
	int deg[1111111];
	void upd(int x,hash d){for(;x<=V;x+=x&-x)T[x]=T[x]+d;}
	void ins(int x,int d)
	{
		hash p=d;
		upd(x,pw[x-1]*p);
	}
	hash Pref(int r)
	{hash ret=0;for(;r;r-=r&-r)ret=ret+T[r];return ret;}
	hash ask(int l,int r)
	{return(Pref(r)-Pref(l-1))*ipw[l-1];}
}T2;
bool valid(int ep)
{
	if(ep<d)return 1;
	if(ep==d)return T1.ask(1,d)!=T2.ask(1,d);
	return T1.ask(ep-d,ep)!=T2.ask(ep-d,ep)&&T1.ask(ep-d+1,ep)!=T2.ask(ep-d+1,ep);
}
void tryinc(int x)
{
	if(!x)puts("Impossible"),exit(0);
	if(t[x]==122)
	{
		tryinc(x-1);
		T1.ins(x,-25),T2.ins(x,-25),t[x]=97;
		if(!valid(x))tryinc(x);
	}
	else
	{
		t[x]++,T1.ins(x,1),T2.ins(x,1);
		if(!valid(x))tryinc(x);
	}
}
bool tryins(int x,int c)
{
	T1.ins(x,c-t[x]),T2.ins(x,c-t[x]),t[x]=c;
	if(!valid(x))return tryinc(x),0;
	return 1;
}
int main()
{
	scanf("%d%s",&d,s+1);
	register int i;
	pw[0]=ipw[0]=1;
	for(i=1;i<=V;i++)pw[i]=pw[i-1]*bas,ipw[i]=ipw[i-1]*ibas;
	for(i=1;s[i];i++)
	{
		if(!tryins(i,s[i]))break;
	}
	if(!s[i])tryinc(i-1);
	else for(i++;s[i];i++)tryins(i,97);
	puts(t+1);
}