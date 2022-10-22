#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=n;i--)
#define ll long long
const int N=2e6;
int n,m,k;
ll jc[N],jc2[N],jl[N];
const int mo=1e9+7;
int fsp(int x,int y)
{
	if (y==0) return 1;
	if (y==1) return x;
	ll ans=fsp(x,y/2);
	ans=ans*ans%mo;
	if (y%2==1) ans=ans*x%mo;
	return ans; 
}
ll C(int x,int y)
{
	if (x<y) return 0;
	return jc[x]*jc2[y]%mo*jc2[x-y]%mo;
}
int main()
{
	int T;
	cin>>T;
	int inv2=fsp(2,mo-2); 
	jc[0]=jc2[0]=1;
	rep(i,1,1e6) jc[i]=jc[i-1]*i%mo;
	jc2[1000000]=fsp(jc[1000000],mo-2)%mo;
	dep(i,1e6-1,1) jc2[i]=jc2[i+1]*(i+1)%mo;
	rep(i,0,1e6) jl[i]=fsp(fsp(2,i),mo-2)%mo;
	while (T--)
    {
    	cin>>n>>m>>k;
    	ll ans=0;
    	rep(t,1,n)
    	{
    		ans+=(t+1)*C(n-t,m-t)%mo*jl[n-t+1]%mo;
    		ans%=mo;
    	}
    	ans=(ans*k)%mo;
    	cout<<ans<<endl;
	} 
	//(t+1)/2 x^t *C(n-t,m-t)/2^(n-t) //(x+1)/2^(n-t)
	return 0; 
}
/*
0 0
1 0 k
2 0 k/2 4k/2
3 0 k/4 5k/4 12k/4 
4 0 k/8 6k/8 17k/8 32k/8
5 0 k/16 7k/16 23k/16 50k/16 80k/16
6 0 k/32 8k/32 30k/32 73k/32 130k/32 192k/32
g=((x+1)/2 f+(n+1)/2 x^n)

(t+1)/2 x^t *C(n-t,m-t)/2^(n-t) //(x+1)/2^(n-t)

k/2^{n-1}
nk/2^{n-1}
n^2/2+3n/2+3
3 12
4 17
5 23

9a+3b+c=12;
16a+4b+c=17;
25a+5b+c=23;

7a+b=5;
9a+b=6'
2a=1;
a=1/2; b=3/2; c=3;
*/