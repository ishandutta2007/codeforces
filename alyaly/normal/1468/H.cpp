#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int N=501000;
long long read(void)
{
	char ch=getchar();long long sum=0;bool f=0;
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-'){f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
	if(f)sum=-sum;return sum;
}
int T;
int n,m,K,S,tot,A[N],Que[N];
void PY(void)
{
	puts("YES");return;
}
void PN(void)
{
	puts("NO");return;
}
void solve(void)
{
	n=read();K=(read()-1)/2;m=read();tot=0;
	for(int i=1;i<=m;i++)A[i]=read();
	if((n-m)/K%2!=0)return PN();
	if((n-m)%K!=0)return PN();
	S=(n-m)/K;
	for(int i=1;i<=m;i++)
		if((A[i]-i)>=K&&(A[i]-i)<=n-m-K)return PY();
	return PN();
	if(tot)return PY();
	else return PN();
	int maxL=0,minR=n;
	for(int i=1;i<=tot;i++){
		if(Que[i]==S/2)return PY();
		if(Que[i]<S/2)maxL=max(maxL,Que[i]);
		else if(Que[i]>S/2)minR=min(minR,Que[i]);
	}
	if(minR-maxL<=S/2)return PY();
	else return PN();
}
int main()
{
	T=read();while(T--)solve();
	return 0;
}