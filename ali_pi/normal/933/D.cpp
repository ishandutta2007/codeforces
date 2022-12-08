#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 1000000007
#define N 1000005
ll n,m,M,a[N],b[N],c[N],i,j,k,ans;
int main()
{
	cin>>n;
	for(i=1;i<N;i++)
	{
		a[i]=(a[i-1]+i*i)%P;
		b[i]=(b[i-1]+i*i*i%P*i)%P;
		c[i]=(c[i-1]+i*i*i%P*i%P*i%P*i)%P;
	}
	for(m=1;m*m<=n;m++);
	m--;
	M=n%P;
	for(i=1,j=m;i<=m;i++)
	{
		for(;i*i+j*j>n;j--);
		k=i*i%P;
		ans=(ans+(1+M-k)*(2+M-k)%P*(M+2*k)%P*(j+1)+(4+3*M-12*k%P-6*M*k%P+6*k*k+2*P)%P*a[j]+(6*k-3*M%P-6+2*P)%P*b[j]+2*c[j])%P;
	}
	ans=ans*2%P*(P+1)/3%P;
	ans=(ans+M*(M+1)%P*(M+2)%P*(P+1)/6)%P;
	cout<<ans<<endl;
}