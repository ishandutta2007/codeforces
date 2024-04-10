#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=2e5;
const int MAXP=1<<19;
const double Pi=acos(-1);
int n,x,s[MAXN+5],c[MAXN+5];
ll ans[MAXN+5];
struct comp{
	double x,y;//(real,imag)
	comp(){x=y=0;}
	comp(double _x,double _y){x=_x;y=_y;}
	friend comp operator +(comp lhs,comp rhs){return comp(lhs.x+rhs.x,lhs.y+rhs.y);}
	friend comp operator -(comp lhs,comp rhs){return comp(lhs.x-rhs.x,lhs.y-rhs.y);}
	friend comp operator *(comp lhs,comp rhs){return comp(lhs.x*rhs.x-lhs.y*rhs.y,lhs.x*rhs.y+lhs.y*rhs.x);}
} A[MAXP+5],B[MAXP+5],C[MAXP+5];
int LEN=1,LOG=0,rev[MAXP+5];
void FFT(comp *a,int len,int type){
	int lg=log2(len);
	for(int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=2;i<=len;i<<=1){
		comp W=comp(cos(2*Pi/i),type*sin(2*Pi/i));
		for(int j=0;j<len;j+=i){
			comp w=comp(1,0);
			for(int k=0;k<(i>>1);k++,w=w*W){
				comp X=a[j+k],Y=w*a[(i>>1)+j+k];
				a[j+k]=X+Y;a[(i>>1)+j+k]=X-Y;
			}
		}
	}
	if(type==-1) for(int i=0;i<len;i++) a[i].x=(ll)(a[i].x/len+0.5);
}
int main(){
	scanf("%d%d",&n,&x);c[0]++;
	for(int i=1;i<=n;i++){
		int v;scanf("%d",&v);
		s[i]=s[i-1]+(v<x);c[s[i]]++;
	}
//	for(int i=0;i<=n;i++) printf("%d\n",c[i]);
	while(LEN<=n+n) LEN<<=1,LOG++;
	for(int i=0;i<=n;i++) A[i].x=c[i];
	for(int i=0;i<=n;i++) B[i].x=c[n-i];
	FFT(A,LEN,1);FFT(B,LEN,1);
	for(int i=0;i<LEN;i++) C[i]=A[i]*B[i];
	FFT(C,LEN,-1);
	for(int i=1;i<=n;i++) ans[i]=C[i+n].x;
	ans[0]=1ll*n*(n+1)/2;
	for(int i=1;i<=n;i++) ans[0]-=ans[i];
	for(int i=0;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}