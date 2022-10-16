// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
	return f?-x:x;
}
template<typename T>void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
	print(x),putchar(ch);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N=50005;
const double eps=1e-9;
const double PI=acos(-1);
const double ANG=0.233;
const double CANG=cos(ANG);
const double SANG=sin(ANG);

inline bool same(double x,double y){return fabs(x-y)<eps;}
inline double sqr(double x){return x*x;}

struct Point{
	double x,y;
	Point(double _x=0,double _y=0){x=_x,y=_y;}
	double len2(){return sqr(x)+sqr(y);}
	double len(){return sqrt(len2());}
	void rot(){
		double _x=x,_y=y;
		x=_x*CANG+_y*SANG;
		y=-_x*SANG+_y*CANG;
	}
}a[N];

bool operator < (Point a,Point b){
	return a.x<b.x;
}

Point operator + (Point a,Point b){
	return Point(a.x+b.x,a.y+b.y);
}
Point operator - (Point a,Point b){
	return Point(a.x-b.x,a.y-b.y);
}
Point operator * (Point a,double b){
	return Point(a.x*b,a.y*b);
}
Point operator / (Point a,double b){
	return Point(a.x/b,a.y/b);
}
double dot(Point a,Point b){
	return a.x*b.x+a.y*b.y;
}
double det(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}

double ans=1e8;
int n,l,k;
int turns;

inline void solve(vector<Point> a){
	static vector<Point> b;
	for(auto &it:a)it.rot();
	sort(a.begin(),a.end());
	b=a,shuffle(b.begin(),b.end(),rng);
	for(int i=0;i<SZ(b);i++){ //  i 
		double l=0,r=ans;
		// printf("now i=%d,b=(%.10f %.10f)\n",i,b[i].x,b[i].y);
		// for(int _=0;_<100&&fabs(r-l)>eps;_++){
		bool fir=0;
		// while(fabs(r-l)>eps){
		while((r-l)/max(1.0,l)>eps){
			double mid=(l+r)/2;
			// turns++;
			if(l<1&&r>1)mid=1;
			else if(l<1)mid=(l+r)/2;
			else mid=sqrt(l*r);
			if(!fir)mid=r,fir=1;
			// printf("     check %.3f %.3f\n",l,r);
			int pos1=lower_bound(a.begin(),a.end(),Point(b[i].x-2*mid-eps,0))-a.begin();
			int pos2=upper_bound(a.begin(),a.end(),Point(b[i].x+2*mid+eps,0))-a.begin();
			// printf("pos1=%d,pos2=%d,mid=%.3f\n",pos1,pos2,mid);
			if(pos2-pos1<k){l=mid;continue;}
			vector<pair<double,int>> range;
			int c=0;
			for(int j=pos1;j<pos2;j++){
				// turns++;
				Point p=a[j]-b[i];
				if(p.len()>2*mid)continue;
				if(p.len()<eps){c++;continue;}
				double d=p.len();
				double ang1=atan2(p.y,p.x),ang2=acos(d/2/mid);
				auto norm=[&](double x){
					while(x>2*PI)x-=2*PI;
					while(x<0)x+=2*PI;
					return x;
				};
				double L=norm(ang1-ang2),R=norm(ang1+ang2);
				if(L>R)c++;
				range.pb({L,1}),range.pb({R,-1});
			}
			bool ok=c>=k;
			sort(range.begin(),range.end());
			for(auto it:range){
				c+=it.sec;
				if(ok|=c>=k)break;
			}
			if(ok)r=ans=mid;
			else l=mid;
		}
	}
}

void solve(){
	n=read(),l=read(),k=read(),ans=1e9;
	static pii a[N];
	rep(i,1,n)a[i].fir=read(),a[i].sec=read();
	set<pii> s;
	// ll qaq=0;
	rep(i,1,n){
		// if(i%10==0)fprintf(stderr,"i=%d,qaq=%lld,tunrs=%lld,clock=%.10f\n",i,qaq,turns,clock()/1./CLOCKS_PER_SEC),qaq=0,turns=0;
		s.insert(a[i]);
		if(i>l)s.erase(a[i-l]);
		auto it=s.lower_bound(make_pair(int(a[i].fir-2*ans-1),0));
		vector<Point> ask;
		while(it!=s.end()){
			pii t=*it;
			if(t.fir-a[i].fir>2*ans)break;
			if(1.*(t.fir-a[i].fir)*(t.fir-a[i].fir)+1.*(t.sec-a[i].sec)*(t.sec-a[i].sec)<4*ans*ans+eps)ask.pb(Point(t.fir,t.sec));
			it++;
			// qaq++;
		}
		// qaq+=SZ(ask);
		solve(ask);
	}
	printf("%.15f\n",ans);
}

int main(){
	// freopen("data.in","r",stdin);
	int T=read();
	while(T--)solve();
	return 0;
}