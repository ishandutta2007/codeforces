#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
	x=0;char o,f=1;
	while(o=getchar(),o<48)if(o==45)f=-f;
	do x=(x<<3)+(x<<1)+(o^48);
	while(o=getchar(),o>47);
	x*=f;
}
template<class T>inline void print(T x,int op=1){
	static int top,stk[105];
	if(x<0)x=-x,putchar('-');
	if(x==0)putchar('0');
	while(x)stk[++top]=x%10,x/=10;
	while(top)putchar(stk[top--]+'0');
	if(~op)putchar(" \n"[op]);
}
const double eps=1e-10;
const double PI=acos(-1);
inline int sgn(double x){return fabs(x)<eps?0:(x<0?-1:1);}
struct point{
	double x,y;
	point(double a=0,double b=0):x(a),y(b){}
	point operator +(const point &A)const{
		return point(x+A.x,y+A.y);
	}
	point operator -(const point &A)const{
		return point(x-A.x,y-A.y);
	}
	point operator *(const double v)const{
		return point(x*v,y*v);
	}
	point operator /(const double v)const{
		return point(x/v,y/v);
	}
	bool operator ==(const point &A)const{
		return sgn(x-A.x)==0&&sgn(y-A.y)==0;
	}
	double norm(){
		return sqrt(x*x+y*y);
	}
    double norm2(){
		return x*x+y*y;
	}
};
double angle(point p){
	return atan2(p.y,p.x);
}
inline double mysqrt(double x){return sqrt(max(0.0,x));}
vector<point>circle_cross_line(point a,point b,point o,double r){
	double dx=b.x-a.x,dy=b.y-a.y;
	double A=dx*dx+dy*dy;
	double B=2*dx*(a.x-o.x)+2*dy*(a.y-o.y);
	double C=(a.x-o.x)*(a.x-o.x)+(a.y-o.y)*(a.y-o.y)-r*r;
	double delta=B*B-4*A*C;
	vector<point>vi;
	if(sgn(delta)>=0){
		double t1=(-B+mysqrt(delta))/(2*A);
		double t2=(-B-mysqrt(delta))/(2*A);
		vi.push_back(point(a.x+t1*dx,a.y+t1*dy));
		if(sgn(delta)>0)vi.push_back(point(a.x+t2*dx,a.y+t2*dy));
	}
	return vi;
}

const int M=1e5+5;
int n,k,X[M],Y[M];
bool check(double mid){
	int cnt=0;
	vector<pair<double,int>>Q;
	for(int i=1;i<=n;i++){
		if(X[i]==0&&Y[i]==0)cnt++;
		else{
			point p=point(X[i],Y[i]);
			vector<point>vi=circle_cross_line(p/2,p/2+point(-Y[i],X[i]),point(0,0),mid);
			if(vi.size()==0)continue;
			else if(vi.size()==1){
				double ang=angle(vi[0]);
				Q.push_back(make_pair(ang,1));
				Q.push_back(make_pair(ang+eps,-1));
			}
			else if(vi.size()==2){
				double ang1=angle(vi[0]);
				double ang2=angle(vi[1]);
				if(ang1>ang2)swap(ang1,ang2);
				if(ang2-ang1<=PI){
					Q.push_back(make_pair(ang1,1));
					Q.push_back(make_pair(ang2,-1));
				}
				else{
					Q.push_back(make_pair(ang2,1));
					Q.push_back(make_pair(ang1,-1));
					cnt++;
				}
			}
		}
	}
	sort(Q.begin(),Q.end());
	for(auto it:Q){
		if(cnt>=k)return 1;
		cnt+=it.second;
	}
	return cnt>=k;
}
signed main(){
#ifndef ONLINE_JUDGE
	freopen("jiedai.in","r",stdin);
#endif
	rd(n),rd(k);
	for(int i=1;i<=n;i++)rd(X[i]),rd(Y[i]);
	double l=0,r=2e5;
	for(int i=1;i<=100;i++){
		double mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%.10lf\n",l);
	return (0-0);
}