#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int K=10;
const int H=4;
const ll inv5=14757395258967641293ull;
const ll inv55=inv5*inv5*inv5*inv5*inv5;
const ll mod=1ll<<58;
int n,lim=100000;
ll ass[K];
struct num{
	ll a[H];
	num(){memset(a,0,sizeof(a));}
	ll&operator[](const int&u){return a[u];}
	friend num operator*(num&u,num&v){
		num w;
		for(int i=0;i<K;i++)ass[i]=0;
		for(int i=0;i<H;i++)for(int j=0;j<H;j++)ass[(i+j)%(H+1)]+=u[i]*v[j];
		for(int i=0;i<H;i++)ass[i]-=ass[H];
		for(int i=0;i<H;i++)w[i]=ass[i];
		return w;
	}
	friend num operator+(num u,num v){num w;for(int i=0;i<H;i++)w[i]=u[i]+v[i];return w;}
	friend num operator*(num&u,const ll&v){num w;for(int i=0;i<H;i++)w[i]=u[i]*v;return w;}
}F[100100],ome[K];
void FWT(num*a,int tp){
	static num OME[K];
	for(int i=0;i<K;i++)OME[i]=ome[i];
	if(tp==-1)for(int i=1,j=K-1;i<j;i++,j--)swap(OME[i],OME[j]);
	for(int md=1;md<lim;md*=K)for(int stp=md*K,pos=0;pos<lim;pos+=stp)for(int i=0;i<md;i++){
		num*A[K],B[K];
		for(int j=0;j<K;j++)A[j]=&a[pos+j*md+i];
		for(int j=0;j<K;j++)for(int k=K-1;k>=0;k--)B[j]=B[j]*OME[j]+*A[k];
		for(int j=0;j<K;j++)*A[j]=B[j];
	}
}
num ksm(num x,int y){num z;z[0]=1;for(;y;y>>=1,x=x*x)if(y&1)z=z*x;return z;}
int main(){
	scanf("%d",&n);
	for(int i=0,x;i<n;i++)scanf("%d",&x),F[x][0]++;
	for(int i=0;i<H;i++)ome[2*i][i]=1,ome[(2*i+H+1)%K][i]=-1;
	for(int i=0;i<H;i++)ome[2*H][i]=-1,ome[(3*H+1)%K][i]=1;
//	for(int i=0;i<K;i++){for(int j=0;j<H;j++)printf("%llu ",ome[i][j]);puts("");}
	FWT(F,1);
	for(int i=0;i<lim;i++)F[i]=ksm(F[i],n);
	FWT(F,-1);
	for(int i=0;i<lim;i++)F[i]=F[i]*inv55;
	for(int i=0;i<n;i++)printf("%lld\n",(F[i][0]>>5)%mod);
	return 0;
}