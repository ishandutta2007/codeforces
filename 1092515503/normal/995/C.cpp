#include<bits/stdc++.h>
using namespace std;
const int LIM1=1000000;
const int LIM2=1500000;
int n,fa[100100],A,B;
bool rev[100100];
struct Vector{
	int x,y;
	Vector(int X=0,int Y=0){x=X,y=Y;}
	friend Vector operator +(const Vector &u,const Vector &v){return Vector(u.x+v.x,u.y+v.y);}
	friend Vector operator -(const Vector &u,const Vector &v){return Vector(u.x-v.x,u.y-v.y);}
	friend bool operator <=(const Vector &u,const int &v){return 1ll*u.x*u.x+1ll*u.y*u.y<=1ll*v*v;}
}v[100100];
int main(){
	scanf("%d",&n);
	if(n<=1){puts("1");return 0;}
	for(int i=1;i<=n;i++)scanf("%d%d",&v[i].x,&v[i].y);
	A=1,B=2;
	for(int i=3;i<=n;i++){
		if(v[i]+v[A]<=LIM1){v[i]=v[i]+v[A],fa[A]=i,A=B,B=i;continue;}
		if(v[i]-v[A]<=LIM1){v[i]=v[i]-v[A],fa[A]=i,rev[A]^=1,A=B,B=i;continue;}
		if(v[i]+v[B]<=LIM1){v[i]=v[i]+v[B],fa[B]=i,B=i;continue;}
		if(v[i]-v[B]<=LIM1){v[i]=v[i]-v[B],fa[B]=i,rev[B]^=1,B=i;continue;}
		if(v[B]+v[A]<=LIM1){v[B]=v[B]+v[A],fa[A]=B,A=B,B=i;continue;}
		if(v[B]-v[A]<=LIM1){v[B]=v[B]-v[A],fa[A]=B,rev[A]^=1,A=B,B=i;continue;}
	}
	if(v[B]+v[A]<=LIM2)v[B]=v[B]+v[A],fa[A]=B;
	else v[B]=v[B]-v[A],fa[A]=B,rev[A]^=1;
	for(int i=n;i;i--)if(fa[i])rev[i]^=rev[fa[i]];
	for(int i=1;i<=n;i++)printf("%d ",rev[i]?-1:1);
	return 0;
}