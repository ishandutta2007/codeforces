#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define eps 1e-8
#define PB push_back
#define MP make_pair
using namespace std;
double pi=asin(1.0)*2;

struct point{
	double x,y;
	point(){}
	point(double _x,double _y){x=_x;y=_y;}
	inline void read(){scanf("%lf%lf",&x,&y);}
	inline void show(){printf("%lf %lf\n",x,y);}
	inline double dis(){return x*x+y*y;}
	inline double dist(){ return sqrt(x*x+y*y);}
};

inline point operator +(const point &a,const point &b){ return point(a.x+b.x,a.y+b.y); }
inline point operator -(const point &a,const point &b){ return point(a.x-b.x,a.y-b.y); }
inline point operator *(const point &a,const double &b){ return point(a.x*b,a.y*b); }
inline point operator /(const point &a,const double &b){ return point(a.x/b,a.y/b); }
inline double det(const point &a,const point &b){ return a.x*b.y-a.y*b.x; }
inline double dot(const point &a,const point &b){ return a.x*b.x+a.y*b.y; }

int p[100000],np;
bool f[110000];
int num[110000];

int getans(int n){
	int ans=0;
	int a=n;
	if (n<100){
		ans+=num[n%10*10];
		return ans;
	}
	if (n<1000){
		for (int z=lower_bound(p,p+np,n%100/10*100)-p;z<np&&p[z]<n%100/10*100+100;z++){
			ans+=num[n%10*100+p[z]%10*10];
		}
		return ans;
	}
	if (n<10000){
		int lz=n%1000/100*1000,rz=lz+1000;
		for (int z=lower_bound(p,p+np,lz)-p;z<np&&p[z]<rz;z++){
			int b=p[z];
			int lq=n%100/10*1000+b%100/10*100,rq=lq+100;
			for (int q=lower_bound(p,p+np,lq)-p;q<np&&p[q]<rq;q++){
				int c=p[q];
				ans+=num[n%10*1000+b%10*100+c%10*10];
			}
		}
		return ans;
	}
	int cnt=0;
	if (n<100000){
		int lz=n%10000/1000*10000,rz=lz+10000;
		for (int z=lower_bound(p,p+np,lz)-p;z<np&&p[z]<rz;z++){
			int b=p[z];
			int lq=n%1000/100*10000+b%1000/100*1000,rq=lq+1000;
			for (int q=lower_bound(p,p+np,lq)-p;q<np&&p[q]<rq;q++){
				int c=p[q];
				int lw=n%100/10*10000+b%100/10*1000+c%100/10*100,rw=lw+100;
				for (int w=lower_bound(p,p+np,lw)-p;w<np&&p[w]<rw;w++){
					ans+=num[n%10*10000+b%10*1000+c%10*100+p[w]%10*10];
				}
			}
		}
		return ans;
	}
}

int main(){
	np=0;
	f[0]=f[1]=true;
	memset(f,false,sizeof(f));
	for (int i=2;i<110000;i++) if (!f[i]){
		p[np++]=i;
		for (int j=i+i;j<110000;j+=i) f[j]=true;
	}
	for (int i=0;i<100000;i++)if (i%10==0)
	for (int j=0;j<10;j++) num[i]+=(!f[i+j]);
	//for (int i=np-1;;i--) cout<<p[i]<<' '<<getans(p[i])<<endl;
	int t;
	for (scanf("%d",&t);t--;){
		int n;
		scanf("%d",&n);
		cout<<getans(n)<<endl;
	}
	return 0;
}