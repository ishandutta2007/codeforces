#include<bits/stdc++.h>
using namespace std;
const int maxn=262200;
const double pi=acos((double)-1.0),eps=1e-3;
struct Complex{
	double a,b;
	Complex(double a=0.0,double b=0.0):a(a),b(b){}
	Complex operator+(const Complex &x)const{return Complex(a+x.a,b+x.b);}
	Complex operator-(const Complex &x)const{return Complex(a-x.a,b-x.b);}
	Complex operator*(const Complex &x)const{return Complex(a*x.a-b*x.b,a*x.b+b*x.a);}
	Complex &operator+=(const Complex &x){return *this=*this+x;}
}w[maxn],w_inv[maxn],A[maxn];
void FFT_init(int n){
	for(int k=0;k<n;k++){
		w[k]=Complex(cos(2*pi*k/n),sin(2*pi*k/n));
		w_inv[k]=Complex(cos(-2*pi*k/n),sin(-2*pi*k/n));
	}
}
void FFT(Complex *A,int n,int tp){
	for(int i=1,j=0,k;i<n-1;i++){
		k=n;
		do j^=(k>>=1);while(j<k);
		if(i<j)swap(A[i],A[j]);
	}
	for(int k=2;k<=n;k<<=1)for(int i=0;i<n;i+=k)for(int j=0;j<(k>>1);j++){
		Complex a=A[i+j],b=(tp>0?w:w_inv)[j*(n/k)]*A[i+j+(k>>1)];
		A[i+j]=a+b;
		A[i+j+(k>>1)]=a-b;
	}
	if(tp<0)for(int i=0;i<n;i++)A[i].a/=n;
}
int n,k,a[maxn];
int main(){
	scanf("%d%d",&n,&k);
	int N=1;
	while(N<(k<<1))N<<=1;
	FFT_init(N);
	while(n--){
		int x;
		scanf("%d",&x);
		a[x%k]=1;
	}
	a[0]=1;
	for(int t=1;t<=k;t<<=1){
		memset(A,0,sizeof(A));
		for(int i=0;i<k;i++)A[i].a=a[i];
		FFT(A,N,1);
		for(int i=0;i<N;i++)A[i]=A[i]*A[i];
		FFT(A,N,-1);
		for(int i=0;i<k;i++)a[i]|=(int)(A[i].a>eps||A[i+k].a>eps);
	}
	int cnt=0;
	for(int i=0;i<k;i++)cnt+=a[i];
	printf("%d\n",cnt);
	for(int i=0;i<k;i++){
		if(!a[i])continue;
		if(i)printf(" ");
		printf("%d",i);
	}
	return 0;
}