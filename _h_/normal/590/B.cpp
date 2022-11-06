#include <cstdio>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
typedef long long ll;

double search(ll x, ll y, double t0, double t1, ll vx, ll vy, ll v){
	while(t1 - t0 > 1e-8){
		double m = (t0+t1)/2;
		double xm = x + vx*m,
			   ym = y + vy*m;
		if(xm*xm + ym*ym > v*v*m*m)
			t0 = m;
		else
			t1 = m;
	}
	return t0;
}

int main(){
	ll x,y,x0,y0,v,t,vx,vy,wx,wy;
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld",&x,&y,&x0,&y0,&v,&t,&vx,&vy,&wx,&wy);
	x -= x0;
	y -= y0;
	ll xt = x + t*vx;
	ll yt = y + t*vy;
	if(xt*xt + yt*yt <= v*v*t*t)
		printf("%lf\n",search(x,y,0,t,vx,vy,v));
	else
		printf("%.10lf\n",search(xt-t*wx,yt-t*wy,t,1e100,wx,wy,v));
}