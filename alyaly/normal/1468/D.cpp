#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1010000;
long long read(void)
{
	char ch=getchar();long long sum=0;bool f=0;
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-'){f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
	if(f)sum=-sum;return sum;
}
int T;
long long A[N];
int n,m,a,b,K,lim;
bool check(long long lim)
{
	for(int i=lim;i>=1;i--)
	{
		if(A[i]+lim-i+1>b-1)return 0;
	}return 1;
}
void solve(void)
{
	n=read();m=read();a=read();b=read();
	if(a>b){a=n-a+1;b=n-b+1;}
	for(int i=1;i<=m;i++)A[i]=read();
	K=b-a-1;sort(A+1,A+m+1);
	long long L=0,R=min(m,K);
	while(L<R)
	{
		long long mid=(L+R+1)>>1;
		if(!check(mid))R=mid-1;
		else L=mid;
	}cout<<L<<endl;
	return;
}
int main()
{
	T=read();while(T--)solve();
	return 0;
}