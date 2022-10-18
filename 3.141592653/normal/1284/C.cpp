#include<cstdio>
#include<iostream>
#include<cmath>
#define PI (acos(-1))
#include<queue>
#include<algorithm>
using std::priority_queue;
#include<map>
using std::map;
#define ll long long
#include<set>
using std::set;
typedef double db;
#include<cstring>
#include<cstdlib>
#define int ll
#include<ctime>
struct pii
{int x,y;};
inline bool operator<(const pii x,const pii y)
{return x.x<y.x;}
const int ntt=998244353;
const int rq=1e9+7;
using std::cin;
using std::cout;
using std::endl;
#define errlog(...) fprintf(stderr,__VA_ARGS__)
#define In(R) (cin>>R)
#define Out(R) (cout<<R)
#define Ln(R) (cout<<R<<endl)
#define IN In
#define OUT Out
#define OUt Out
#define OuT Out
#define LN Ln
#define iN In
#define oUt Out
#define oUT Out
#define lN Ln
#define Lin Ln 
char str[1111111];
int a[1111111];
bool valid(int l,int r)
{
	register int i,L=1e9,R=0;
	for(i=l;i<=r;i++)
	{
		if(a[i]<L)L=a[i];
		if(a[i]>R)R=a[i];
	}return(L+r==l+R);
}
int cnt[111111];
void brute(int n)
{
	register int i,ii;
	int ans=0;
	for(i=1;i<=n;i++)a[i]=i;
	do
	{
		int t=0;
		for(ii=1;ii<=n;ii++)
			for(i=1;i<=ii;i++)
				t+=valid(i,ii);
			//Ln(t);
		cnt[t]++;
			ans+=t;
	}while(std::next_permutation(a+1,a+n+1));
	for(i=1;i<=100;i++)Out(cnt[i]),Out(' ');
	Ln(ans);
}
int s[1111111],t[1111111];
int fac[1111111]; 
void exec()
{
	int n,p;
	In(n),In(p);
//	brute(n);
	register int i;
	fac[0]=1;
	for(i=1;i<=n;i++)fac[i]=(fac[i-1]*i)%p;
	int ans=0;
	for(i=1;i<=n;i++)ans+=((fac[i]*fac[n-i+1])%p*i)%p;
	ans%=p;
	Ln(ans);
}

signed main()
{
	std::ios::sync_with_stdio(0);
	int T=1;
	
	//In(T);
	
	while(T--)exec();
}