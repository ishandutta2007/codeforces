#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
const int MOD=998244353;
const int INF=0x3f3f3f3f;
const ll INFll=0x3f3f3f3f3f3f3f3fll;
const ld EPS=1e-10;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=(c=='-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=-x;
	}
	template<typename T> void recursive_print(T x){
		if(!x) return;
		recursive_print(x/10);putc(x%10+'0');
	}
	template<typename T> void print(T x){
		if(!x) putc('0');if(x<0) putc('-'),x=-x;
		recursive_print(x);
	}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
template<typename Tv,int limN,int limM> struct link_list{
	int hd[limN+5],nxt[limM+5],item_n=0;Tv val[limM+5];
	void clear(){memset(hd,0,sizeof(hd));item_n=0;}//be aware of the TC of memset
	void ins(int x,Tv y){val[++item_n]=y;nxt[item_n]=hd[x];hd[x]=item_n;}
};
const int MAXN=1e5;
const int LOG_T=36;
int sgn(ld x){return (x<-EPS)?-1:((x<EPS)?0:1);} 
struct mat{
	ld a[4][4];
	mat(){for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) a[i][j]=0;}
	mat operator *(const mat &rhs){
		mat res;
		for(int i=1;i<=3;i++) for(int j=1;j<=3;j++)
			for(int k=1;k<=3;k++) res.a[i][k]+=a[i][j]*rhs.a[j][k];
		return res;
	}
} cur,pw[LOG_T+2];
int n,a[MAXN+5],b[MAXN+5];
ll t;ld p[MAXN+5],X=0;
struct point{
	ld x,y;int id;
	point(ld _x=0,ld _y=0,int _id=0):x(_x),y(_y),id(_id){}
	bool operator <(const point &rhs) const{
		if(sgn(x-rhs.x)) return sgn(x-rhs.x)<0;
		return sgn(y-rhs.y)<0;
	}
} P[MAXN+5];
int stk[MAXN+5],tp=0;
void calc_hull(){
	sort(P+1,P+n+1);
	for(int i=1,j;i<=n;i=j+1){
		j=i;while(!sgn(P[i].x-P[j].x)) j++;j--;
		while(tp>1&&(P[stk[tp]].y-P[stk[tp-1]].y)*(P[j].x-P[stk[tp]].x)<
				    (P[stk[tp]].x-P[stk[tp-1]].x)*(P[j].y-P[stk[tp]].y)) --tp;
		stk[++tp]=j;
	}
}
ld calc(point p,ld x){return p.x*x+p.y;}
int main(){
	scanf("%d%lld",&n,&t);
	for(int i=1;i<=n;i++){
		scanf("%d%d%Lf",&a[i],&b[i],&p[i]);
		P[i]=point(p[i],a[i]*p[i],i);chkmax(X,b[i]*p[i]);
	}
	calc_hull();
	ll curp=0;cur.a[1][3]=1;
//	for(int i=1;i<=tp;i++) printf("(%.10Lf %.10Lf)\n",P[stk[i]].x,P[stk[i]].y);
	for(int i=1;;){
		ld curS=X*curp-cur.a[1][1];
//		printf("%lld %.10Lf\n",curp,curS);
		while(i<tp&&(P[stk[i+1]].y-P[stk[i]].y)>=-curS*(P[stk[i+1]].x-P[stk[i]].x)) i++;
		int id=P[stk[i]].id;
		pw[0].a[1][1]=1-p[id];pw[0].a[1][2]=0;pw[0].a[1][3]=0;
		pw[0].a[2][1]=p[id]*X;pw[0].a[2][2]=1;pw[0].a[2][3]=0;
		pw[0].a[3][1]=p[id]*a[id];pw[0].a[3][2]=1;pw[0].a[3][3]=1;
		for(int j=1;j<=LOG_T;j++) pw[j]=pw[j-1]*pw[j-1];
		for(int j=LOG_T;~j;j--) if(curp+(1ll<<j)<t){
			mat nw_mat=cur*pw[j];
			ld nw=X*nw_mat.a[1][2]-nw_mat.a[1][1];
			if((i==tp)||calc(P[stk[i]],nw)>calc(P[stk[i+1]],nw))
				curp+=(1ll<<j),cur=cur*pw[j];
		} cur=cur*pw[0];curp++;if(curp==t) break;
	} printf("%.10Lf\n",cur.a[1][1]);
	return 0;
}
/*
Let dp[i] be the maximum profit if we have i seconds left
We can obtain:
dp[i]=max{(1-p[j])*dp[i-1]+p[j]*X*(i-1)+p[j]*a[j]}
Where X=max{b[i]*p[i]}
Let S[i] be X(i-1)-dp[i-1]
S[i+1]-S[i]=(iX-dp[i])-(X(i-1)-dp[i-1])=X-(dp[i]-dp[i-1])>=0
Our formula can be written as:
dp[i]=max{dp[i-1]+p[j]*S[i]+a[j]*p[j]}
The formula can be considered as the maximum y-coordinate
among n intersection between y axis and n lines with slope S[j] which goes through (p[j],a[j]p[j])
Let's work out the convex hull of the n points
As S[i] is non-decreasing, the optimal point must be on the convex hull with x-coordinate decreasing
Use binary search, for each point, find the maximum right position i such that the optimal point of i is current point
dp[i] can be solved by matrix qpow
			  [1-p[j]    0 0]
[dp[i] i 1] * [p[j]*X    1 0] = [dp[i+1] i+1 1]
			  [p[j]*a[j] 1 1]
*/
/*
2 1000000000
99900000 100000000 0.000000009
2 100002 0.000000044
*/