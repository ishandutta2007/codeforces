#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 1e6+5;

int n;
double a[N];

struct P{
	db x,y,k;
	P(db _x=0,db _y=0,db _k=0){x=_x;y=_y;k=_k;}
	friend bool operator < (P a,P b){
		return a.k<b.k;
	}
	friend db operator * (P a,P b){
		return a.x*b.y-a.y*b.x;
	}
	friend P operator - (P a,P b){
		return P(a.x-b.x,a.y-b.y);
	}
}q[N];

bool jud(P a,P b,P t){
	db k=(t.y-b.y)/(t.x-b.x)*(a.x-b.x)+b.y;
	return k<a.y;
}

void work(){
	int R=0;
	q[++R]=P(0,0);
	for(int i=1;i<=1;++i)q[++R]=P(i,a[i]);
	for(int i=2;i<=n;++i){
		while(R>1&&jud(q[R],q[R-1],P(i,a[i])))R--;
		q[++R]=P(i,a[i]);
	}
	q[++R]=P(n,0);
	//q[1].x=1;
	for(int i=1;i<R;++i){
		int l=q[i].x+1,r=q[i+1].x;
		double w=a[r]-a[l-1];
		for(int j=l;j<=r;++j)printf("%.10lf\n",w/(r-l+1));
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lf",&a[i]);
	for(int i=1;i<=n;++i)a[i]+=a[i-1];
	work();
}