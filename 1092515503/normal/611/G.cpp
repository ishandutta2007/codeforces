#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod=1e9+7;
int n,res;
struct MV{//moduloed vector
	int x,y;
	MV(){x=y=0;}
	MV(int X,int Y){x=(X+mod)%mod,y=(Y+mod)%mod;}
	friend MV operator +(const MV &u,const MV &v){return MV((u.x+v.x)%mod,(u.y+v.y)%mod);}
	friend MV operator -(const MV &u,const MV &v){return MV((u.x+mod-v.x)%mod,(u.y+mod-v.y)%mod);}
	friend MV operator *(const MV &u,const int &v){return MV(1ll*u.x*v%mod,1ll*u.y*v%mod);}
	friend int operator &(const MV &u,const MV &v){return (1ll*u.x*v.y%mod-1ll*u.y*v.x%mod+mod)%mod;}//cross times
	friend int operator |(const MV &u,const MV &v){return (1ll*u.x*v.x%mod+1ll*u.y*v.y%mod)%mod;}//point times
	void operator +=(const MV &v){(x+=v.x)%=mod,(y+=v.y)%=mod;}
	void operator -=(const MV &v){(x+=mod-v.x)%=mod,(y+=mod-v.y)%=mod;}
	void read(){scanf("%d%d",&x,&y),(x+=mod)%=mod,(y+=mod)%=mod;}
	void print(){printf("(%d,%d)",x,y);}
}q[500100];
struct OV{//ordinary vector
	int x,y;
	OV(){}
	OV(int X,int Y){x=X,y=Y;}
	friend OV operator +(const OV &u,const OV &v){return OV(u.x+v.x,u.y+v.y);}
	friend OV operator -(const OV &u,const OV &v){return OV(u.x-v.x,u.y-v.y);}
	friend ll operator &(const OV &u,const OV &v){return 1ll*u.x*v.y-1ll*u.y*v.x;}//cross times
	friend ll operator |(const OV &u,const OV &v){return 1ll*u.x*v.x+1ll*u.y*v.y;}//point times
	void read(){scanf("%d%d",&x,&y);}
	void print(){printf("(%d,%d)",x,y);}
}p[500100];
ull area;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)p[n-i].read(),q[n-i]=MV(p[n-i].x,p[n-i].y);
	for(int i=0;i<n;i++)area+=p[i]&p[(i+1)%n];
	ull nowarea=0;
	int sumarea=0;
	MV v;
	for(int i=0,j=0;i<n;i++){
		while(((nowarea+((p[j]-p[i])&(p[(j+1)%n]-p[i])))<<1)<=area){
			v+=q[(j+1)%n];
			nowarea+=(p[j]-p[i])&(p[(j+1)%n]-p[i]);
			(sumarea+=nowarea%mod)%=mod;
			(++j)%=n;
		}
		(res+=(area%mod*((j-i+n-1)%n)%mod-2*sumarea%mod+mod)%mod)%=mod;
		nowarea-=(p[(i+1)%n]-p[i])&(p[j]-p[i]),v-=q[(i+1)%n];
		(sumarea+=mod-((q[(i+1)%n]-q[i])&(v-q[i]*((j-i+n-1)%n)))%mod)%=mod;
	}
	printf("%d\n",res);
	return 0;
}
/*
5
2 4
2 7
5 7
5 4
3 -2

8
-10 0
-6 6
0 10
6 6
10 0
6 -6
0 -10
-6 -6
*/