#include<cstdio>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#define rg register
#define ll long long
#define N 100010
#define For(i,x,y) for (rg int i=(x);i<=(y);i++)
#define Dow(i,x,y) for (rg int i=(x);i>=(y);i--)
inline ll min(ll x,ll y){return x<y?x:y;}
inline ll read(){
    ll x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=-1;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
int r,c,v,n,m,x[N],y[N];
int q;
inline void work(){
	q=read();
	while (q--){
		int x1=read(),y1=read(),x2=read(),y2=read();
		if (x1==x2){
			printf("%d\n",abs(y1-y2));
			continue;
		}
		if (x1>x2) std::swap(x1,x2);
		if (y1>y2) std::swap(y1,y2);
		int a=std::lower_bound(x+1,x+n+1,y1)-x-1,b=std::upper_bound(x+1,x+n+1,y2)-x;
		int ans=1e9;
		if (a<b-1) ans=min(ans,x2-x1+y2-y1);
		else {
			if (a) ans=min(ans,x2-x1+y1-x[a]+y2-x[a]);
			if (b!=n+1) ans=min(ans,x2-x1+2*x[b]-y1-y2);
		}
		a=std::lower_bound(y+1,y+m+1,y1)-y-1,b=std::upper_bound(y+1,y+m+1,y2)-y;
		if (a<b-1) ans=min(ans,(x2-x1-1)/v+1+y2-y1);
		else {
			if (a) ans=min(ans,(x2-x1-1)/v+1+y1-y[a]+y2-y[a]);
			if (b!=m+1) ans=min(ans,(x2-x1-1)/v+1+2*y[b]-y1-y2);
		}
		printf("%d\n",ans);
	}
}
int main(){
	r=read(),c=read(),n=read(),m=read(),v=read();
	For(i,1,n) x[i]=read();
	std::sort(x+1,x+1+n);
	For(i,1,m) y[i]=read();
	std::sort(y+1,y+1+m);
	work();
}