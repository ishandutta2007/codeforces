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
const int MAXN=1.25e5;
const int MAXP=1<<19;
const int AS=6;
const double Pi=acos(-1);
int n,m;char s[MAXN+5],t[MAXN+5];
struct comp{
	double x,y;
	comp(){x=y=0;}
	comp(double _x,double _y){x=_x;y=_y;}
	friend comp operator +(comp lhs,comp rhs){return comp(lhs.x+rhs.x,lhs.y+rhs.y);}
	friend comp operator -(comp lhs,comp rhs){return comp(lhs.x-rhs.x,lhs.y-rhs.y);}
	friend comp operator *(comp lhs,comp rhs){return comp(lhs.x*rhs.x-lhs.y*rhs.y,lhs.x*rhs.y+lhs.y*rhs.x);}
} A[AS+1][MAXP+5],B[AS+1][MAXP+5],C[MAXP+5];
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
				comp X=a[j+k],Y=a[(i>>1)+j+k]*w;
				a[j+k]=X+Y;a[(i>>1)+j+k]=X-Y;
			}
		}
	}
	if(type==-1) for(int i=0;i<len;i++) a[i].x=(int)(a[i].x/len+0.5);
}
bool hav[MAXN+5][AS+1][AS+1];
void solve(char c1,char c2){
	for(int i=0;i<LEN;i++) C[i]=comp(0,0);
	for(int i=0;i<LEN;i++) C[i]=A[c1-'a'][i]*B[c2-'a'][i];
	FFT(C,LEN,-1);
	for(int i=1;i<=n-m+1;i++) if(C[m+i-1].x) hav[i][c1-'a'][c2-'a']=1;
}
int f[AS+1];
int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
int main(){
	scanf("%s%s",s+1,t+1);n=strlen(s+1);m=strlen(t+1);
	while(LEN<=n+m) LEN<<=1,LOG++;
    for(int c='a';c<='f';c++){
        for(int i=1;i<=n;i++) A[c-'a'][i].x=(s[i]==c);
        FFT(A[c-'a'],LEN,1);
    }
    for(int c='a';c<='f';c++){
        for(int i=0;i<m;i++) B[c-'a'][i].x=(t[m-i]==c);
        FFT(B[c-'a'],LEN,1);
    }
	for(char c1='a';c1<='f';c1++) for(char c2='a';c2<='f';c2++) if(c1!=c2) solve(c1,c2);
	for(int i=1;i<=n-m+1;i++){
		for(int j=0;j<AS;j++) f[j]=j;
		int sum=0;
		for(int j=0;j<AS;j++) for(int k=0;k<AS;k++) if(j!=k&&hav[i][j][k]){
			int fj=find(j),fk=find(k);if(fj!=fk) sum++,f[fj]=fk;
		}
		printf("%d ",sum);
	}
	return 0;
}