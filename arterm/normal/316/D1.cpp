#include <iostream>

#define long long long
#define p 1000000007
#define M 100

using namespace std;

long a=0,b=0,n,d[M][M],c[M][M],f[M],r[M];

void read(void){
	cin>>n;
	for (int x,i=0; i<n; ++i){
		cin>>x;
		if (x==1)
		a++;
		else
		b++;
	}
}

void din(void){
	for (int i=0; i<M; ++i)
	c[i][0]=1;
	
	for (int i=1; i<M; ++i)
	for (int j=1; j<M; ++j)
	c[i][j]=(i*c[i-1][j-1])%p;
	
	d[0][0]=1;
	for (int j=1; j<M; ++j)
	d[0][j]=(j*d[0][j-1])%p;
	
	for (int i=1; i<M; ++i)
	for (int j=0; j<M; ++j)
	for (long k=0; k<=j; ++k){
		d[i][j]+=(c[j][k]*d[i-1][j-k]);
		
		long bon=(c[j][k]*(i-1))%p;
		bon=(bon*(k+1))%p;
		
		if (i>=2)
		d[i][j]+=(bon*d[i-2][j-k]);
			
		d[i][j]%=p;
	}
}

long bin(long x, long a){
	long y=1;
	while (a){
		if (x&1)
		y*=x,y%=p;
		x*=x,x%=p;
		a>>=1;
	}
	return y;
}

void pre(void){
	f[1]=1;
	for (int i=2; i<M; ++i)
	f[i]=(i*f[i-1])%p;
	
	r[0]=r[1]=1;
	
	for (int i=2; i<M; ++i)
	r[i]=((2*i-1)*r[i-1])%p;
	
	long ans=0;
	
	for (int x=a%2; x<=a; x+=2){
		int k=((a+x)/2);
		long bon=(r[k]*f[b])%p;
		bon=(bon*bin(b,k+1))%p;
		ans=(ans+bon)%p;
	}
	
	cout<<ans<<"\n";
	
	
	
}



int main()
{
	din();
	read();
	cout<<d[a][b]<<"\n";
	//pre();	
	return 0;
}