//CF 993E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1<<20;
const DB pi = 3.14159265358979;
struct complex{
	DB x,y;
	complex(DB xx=0.0,DB yy=0.0){
		x=xx,y=yy;
	}
}A[N],B[N];
complex operator+(complex a,complex b){
	return complex(a.x+b.x,a.y+b.y);
}
complex operator-(complex a,complex b){
	return complex(a.x-b.x,a.y-b.y);
}
complex operator*(complex a,complex b){
	return complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}
complex operator/(complex a,DB d){
	return complex(a.x/d,a.y/d);
}
void DFT(complex C[],int n,int fl){
	int i,j,k,l;
	complex u,v,w,cur;
	i=n>>1;
	for(j=1;j<n;j=j+1){
		if(i<j)
			swap(C[i],C[j]);
		for(k=n>>1;i&k;k>>=1)
			i^=k;
		i^=k;
	}
	for(l=2;l<=n;l<<=1){
		w=complex(cos(2.0*pi/l),sin(2.0*pi*fl/l));
		for(i=0;i<n;i=i+l){
			cur=complex(1.0,0.0);
			for(j=i;j<i+(l>>1);j=j+1){
				u=C[j],v=C[j+(l>>1)]*cur;
				C[j]=u+v,C[j+(l>>1)]=u-v;
				cur=cur*w;
			}
		}
	}
}
int n,a[N],b[N];
LL c[N];
void FFT(){
	int i,l;
	for(l=1;l<n+n;l<<=1);
	for(i=0;i<n;i=i+1)
		A[i]=complex(a[i],0.0);
	for(i=0;i<n;i=i+1)
		B[i]=complex(b[i],0.0);
	DFT(A,l,1);
	DFT(B,l,1);
	for(i=0;i<l;i=i+1)
		A[i]=A[i]*B[i];
	DFT(A,l,-1);
	for(i=0;i<l;i=i+1)
		A[i]=A[i]/l,c[i]=A[i].x+0.5;
}
int main()
{
	int i,x,y,s=0;
	LL z=0;
	scanf("%d%d",&n,&x);
	a[s]++;
	for(i=1;i<=n;i=i+1){
		scanf("%d",&y);
		if(y<x)
			s++;
		a[s]++;
	}
	for(i=0;i<=n;i=i+1)
		z+=(LL)a[i]*(a[i]-1);
	cout<<z/2<<' ';
	for(i=0;i<=n;i=i+1)
		b[i]=a[n-i];
	n+=10;
	FFT();
	n-=10;
	for(i=n+1;i<=n+n;i=i+1)
		cout<<c[i]<<' ';
	return 0;
}