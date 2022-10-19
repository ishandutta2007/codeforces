#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct Vector{
	int x,y;
	Vector(){}
	Vector(int X,int Y){x=X,y=Y;}
	friend Vector operator-(const Vector&u,const Vector&v){return Vector(u.x-v.x,u.y-v.y);}
	friend ll operator &(const Vector&u,const Vector&v){return 1ll*u.x*v.y-1ll*u.y*v.x;}
	void read(){scanf("%d%d",&x,&y);}
}p[2010];
typedef Vector Point;
int ord[2010],I;
char s[2010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)p[i].read(),ord[i]=i;
	sort(ord+1,ord+n+1,[](int u,int v){return p[u].x==p[v].x?p[u].y<p[v].y:p[u].x<p[v].x;});
	scanf("%s",s+1);
	for(int i=1;i+1<n;i++){
		I=ord[i];
		sort(ord+i+1,ord+n+1,[](int u,int v){return((p[u]-p[I])&(p[v]-p[I]))>0;});
		if(s[i]=='R')swap(ord[i+1],ord[n]);
	}
	for(int i=1;i<=n;i++)printf("%d ",ord[i]);puts("");
	return 0;
}