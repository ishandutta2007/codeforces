#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define RI re int
#define ll long long
#define db double
#define lb long db
#define N 100000
#define K 500
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,m,k,a,b,cnt1,cnt2;db A[N+5],B[N+5],ToT,L1,R1,L2,R2,M1,M2;
I void C2(db M1,db M2){
	ToT=cnt1=cnt2=0;db W1,W2,W3;for(RI i=1;i<=n;i++){
		W1=A[i]-M1;W2=B[i]-M2;W3=A[i]+B[i]-A[i]*B[i]-M1-M2;
		if(W3>W1&&W3>W2) ToT+=W3,cnt1++,cnt2++;
		else if(max(W1,W2)>0) W1>W2?(cnt1++,ToT+=W1):(cnt2++,ToT+=W2);
	}
}
I void C1(db M1){L2=-eps;R2=1;while(L2+eps<R2) M2=(L2+R2)/2,C2(M1,M2),(cnt2>b?L2:R2)=M2;C2(M1,R2);}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d%d%d",&n,&a,&b);for(i=1;i<=n;i++) scanf("%lf",&A[i]);for(i=1;i<=n;i++)scanf("%lf",&B[i]);
	L1=-eps;R1=1;while(L1+eps<R1) M1=(L1+R1)/2,C1(M1),(cnt1>a?L1:R1)=M1;C1(R1);printf("%.5lf\n",ToT+a*R1+b*R2);
}