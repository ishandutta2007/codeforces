#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
struct Vector{
	int x,y;
	Vector(){}
	Vector(int X,int Y){x=X,y=Y;}
	friend Vector operator+(const Vector&u,const Vector&v){return Vector(u.x+v.x,u.y+v.y);}
	friend Vector operator-(const Vector&u,const Vector&v){return Vector(u.x-v.x,u.y-v.y);}
	friend ll operator&(const Vector&u,const Vector&v){return 1ll*u.x*v.y-1ll*u.y*v.x;}
	friend ll operator|(const Vector&u,const Vector&v){return 1ll*u.x*v.x+1ll*u.y*v.y;}
	double operator!()const{return atan2(y,x);}
	ll operator~()const{return 1ll*x*x+1ll*y*y;}
	void read(){scanf("%d%d",&x,&y);}
	void print(){printf("(%d,%d)",x,y);}
}p[10],q[1010];
typedef Vector Point;
int res,ord[10],vis[1010],tim,pos;
vector<int>v[10][1010];
bool kill(int x){
	if(vis[x]==tim)return true;
	if(++pos>n)return false;
	int X=ord[pos];
	for(auto y:v[X][x])if(!kill(y))return false;
	vis[x]=tim;return true;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)p[i].read();
	for(int i=1;i<=m;i++)q[i].read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int k=1;k<=m;k++)
		if(((q[j]-p[i])&(q[k]-p[i]))==0&&((q[j]-p[i])|(q[k]-q[j]))>0)
			v[i][k].push_back(j);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)ord[j]=j;
		do{
			pos=0,++tim;
			if(kill(i)){res++;break;}
		}while(next_permutation(ord+1,ord+n+1));
	}
	printf("%d\n",res);
	return 0;
}