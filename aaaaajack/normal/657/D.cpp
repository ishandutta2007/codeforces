#include<bits/stdc++.h>
#define N 200100
using namespace std;
struct prob{
	int p;
	int t;
	prob(int _p=0,int _t=0):p(_p),t(_t){}
	bool operator<(const prob &r)const{return 1LL*t*r.p<1LL*p*r.t;}
	bool operator==(const prob &r)const{return !(*this<r)&&!(r<*this);}
	bool operator!=(const prob &r)const{return !(*this==r);}
}a[N];
map<int,long long> mxt,mnt;
int main(){
	int n,ps=0;
	double c=1;
	long long T=0,tmx,tmn;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i].p);
	for(int i=0;i<n;i++) scanf("%d",&a[i].t);
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(!i||a[i]!=a[i-1]){
			tmn=T;
		}
		T+=a[i].t;
		if(i==n-1||a[i]!=a[i+1]){
			tmx=T;
			for(int j=ps;j<=i;j++){
				if(!mxt.count(a[j].p)){
					mxt[a[j].p]=tmx;
					mnt[a[j].p]=tmn+a[j].t;
				}
				else{
					mxt[a[j].p]=max(mxt[a[j].p],tmx);
					mnt[a[j].p]=min(mnt[a[j].p],tmn+a[j].t);
				}
			}
			ps=i+1;
		}
	}
	for(auto it=mxt.begin();it!=mxt.end();++it){
		auto nit=it;
		++nit;
		if(nit==mxt.end()) break;
		int p1=it->first,p2=nit->first;
		double r1=1.0*mnt[p1]/T,r2=1.0*mxt[p2]/T;
		if(p2*r2>p1*r1&&p2-p1<p2*r2-p1*r1){
			c=min(c,(p2-p1)/(p2*r2-p1*r1));
		}
	}
	printf("%.12f\n",c);
	return 0;
}