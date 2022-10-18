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
const int MAXN=1.5e6;
const int MAXP=1<<21;
const int WIDTH=100;
const double LOG310=log(10)/log(3);
const double Pi=acos(-1);
int n,LEN=1,LOG=0;
struct comp{
	double x,y;//(real,imag)
	comp(){x=y=0;}
	comp(double _x,double _y){x=_x;y=_y;}
	comp operator +(const comp &rhs){return comp(x+rhs.x,y+rhs.y);}
	comp operator -(const comp &rhs){return comp(x-rhs.x,y-rhs.y);}
	comp operator *(const comp &rhs){return comp(x*rhs.x-y*rhs.y,x*rhs.y+y*rhs.x);}
} A[MAXP+5],B[MAXP+5];
char s[MAXN+5];vector<int> x;
int rev[MAXP+5];
vector<int> pp;int lv;
void FFT(comp *a,int len,int type){
	int lg=log2(len);
	for(int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=2;i<=len;i<<=1){
		comp W=comp(cos(2*Pi/i),type*sin(2*Pi/i));
		for(int j=0;j<len;j+=i){
			comp w=comp(1,0);
			for(int k=0;k<(i>>1);k++,w=w*W){
				comp X=a[j+k],Y=a[(i>>1)+j+k]*w;
				a[j+k]=X+Y;a[(i>>1)+j+k]=X-Y;
			}
		}
	}
	if(type==-1) for(int i=0;i<len;i++) a[i].x=(int)(a[i].x/len+0.5);
}
vector<int> polymul(vector<int> a,vector<int> b){
	int len=1;
	while(len<=a.size()+b.size()) len<<=1;
	for(int i=0;i<len;i++) A[i]=B[i]=comp(0,0);
	for(int i=0;i<a.size();i++) A[i]=comp(a[i],0);
	for(int i=0;i<b.size();i++) B[i]=comp(b[i],0);
	FFT(A,len,1);FFT(B,len,1);
	for(int i=0;i<len;i++) A[i]=A[i]*B[i];
	FFT(A,len,-1);
	vector<int> c(a.size()+b.size());
	for(int i=0;i<c.size();i++){
		c[i]+=(int)A[i].x;
		if(c[i]>=WIDTH) c[i+1]+=c[i]/WIDTH,c[i]%=WIDTH;
	} if(c.back()==0) c.pop_back();
	return c;
}
vector<int> ksm3(int k){
	vector<int> a,b;a.pb(1);b.pb(3);
	for(;k;k>>=1){
		if(k&1) a=polymul(a,b);
		int len=1;
		while(len<=b.size()*2) len<<=1;
    	if(len>MAXP) break;
		for(int i=0;i<len;i++) A[i]=comp(0,0);
		for(int i=0;i<b.size();i++) A[i]=comp(b[i],0);
		FFT(A,len,1);
		for(int i=0;i<len;i++) A[i]=A[i]*A[i];
		FFT(A,len,-1);
		vector<int> c(b.size()*2,0);
		for(int i=0;i<c.size();i++){
			c[i]+=(int)A[i].x;
			if(c[i]>=WIDTH) c[i+1]+=c[i]/WIDTH,c[i]%=WIDTH;
		} if(c.back()==0) c.pop_back();b=c;
	}
//	for(int i=LEN;~i;i--) printf("%d",a[i]);printf("\n");
	return a;
}
vector<int> mul(vector<int> a,int t){
	for(int i=0;i<a.size();i++) a[i]*=t;
	for(int i=0;i<(int)(a.size()-1);i++) if(a[i]>=WIDTH) a[i+1]+=a[i]/WIDTH,a[i]%=WIDTH;
	if(a[a.size()-1]>=WIDTH) a.pb(a[a.size()-1]/WIDTH),a[a.size()-2]%=WIDTH;
	return a;
}
bool check(int mid){
	if(mid==0) return 0;
	if(mid==1){return (n==1&&s[1]=='1');}
	int m2=0;
	if(mid%3==1) m2=2,mid-=4;
	if(mid%3==2) m2=1,mid-=2;
	vector<int> a=pp;
	for(int i=1;i<=mid/3-lv;i++) a=mul(a,3);
	for(int i=1;i<=m2;i++) a=mul(a,2);
	vector<int> b;
	for(int i=0;i<a.size();i++){b.pb(a[i]%10);b.pb(a[i]/10);}
	if(b.back()==0) b.pop_back();
//	for(int i=(int)(a.size()-1);~i;i--) printf("%d",a[i]);printf("\n");
	if(b.size()<x.size()) return 0;
	if(b.size()>x.size()) return 1;
	for(int i=(int)(b.size()-1);~i;i--){
		if(b[i]<x[i]) return 0;
		if(b[i]>x[i]) return 1;
	} return 1;
}
int main(){
//	freopen("in.txt","r",stdin); 
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=n;i;i--) x.pb(s[i]^48);
	int mn=(int)(3.0*LOG310*(n-1));
	lv=max(mn/3-2,0);pp=ksm3(lv);
//	printf("%d\n",mn);
	for(int i=mn;;i++) if(check(i)){printf("%d\n",i);return 0;}
	return 0;
}