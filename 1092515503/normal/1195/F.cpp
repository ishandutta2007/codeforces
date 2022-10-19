#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
const double eps=1e-13;
int cmp(double x){
	if(x>eps)return 1;
	if(x<-eps)return -1;
	return 0;
}
struct Vector{
	int x,y;
	Vector(){}
	Vector(int X,int Y){x=X,y=Y;}
	friend Vector operator +(const Vector &u,const Vector &v){return Vector(u.x+v.x,u.y+v.y);}
	friend Vector operator -(const Vector &u,const Vector &v){return Vector(u.x-v.x,u.y-v.y);}
	friend ll operator &(const Vector &u,const Vector &v){return 1ll*u.x*v.y-1ll*u.y*v.x;}//cross times
	double operator!()const{return atan2(y,x);}
	friend bool operator <(const Vector &u,const Vector &v){
		int tmp=cmp(!u-!v);
		if(tmp)return tmp==-1;
		return (u&v)<0;
	}
	void print(){printf("(%d,%d)",x,y);}
};
typedef Vector Point;
Vector read(){int x,y;scanf("%d%d",&x,&y);return Vector(x,y);}
vector<Point>u[100100];
vector<Vector>v[100100];
vector<int>w[100100];
vector<pair<int,int> >r[100100];
map<Vector,int>mp;
int res[100100],sum[100100];
int t[100100];
void ADD(int x){x++;while(x<=n)t[x]++,x+=x&-x;}
int SUM(int x){int ret=0;while(x)ret+=t[x],x-=x&-x;return ret;}
int main(){
	scanf("%d",&n);
	for(int i=1,m;i<=n;i++){
		scanf("%d",&m),sum[i]=sum[i-1]+m;
		for(int j=0;j<m;j++)u[i].push_back(read());
		for(int j=0;j<m;j++)v[i].push_back(u[i][j]-u[i][(j+1)%m]);
	}
	for(int i=1;i<=n;i++)for(auto j:v[i])w[i].push_back(mp[j]),mp[j]=i;
	scanf("%d",&m);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),r[y].push_back(make_pair(x,i));
	for(int i=1;i<=n;i++){
		for(auto j:w[i])ADD(j);
		for(auto j:r[i])res[j.second]=SUM(j.first)-sum[j.first-1];
	}
	for(int i=1;i<=m;i++)printf("%d\n",res[i]);
	return 0;
}