#include<cstdio>
#include<set>
using namespace std;
int n;
set<long long> s;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void solve(int x)
{
	int tmp=gcd(x,n);
	tmp=n/tmp;
	long long s1=(long long)tmp*(tmp-1)/2*(n/tmp)+tmp;
	s.insert(s1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;1ll*i*i<=n;i++)
	if(n%i==0)
	solve(i),solve(n/i);
	for(set<long long>::iterator it=s.begin();it!=s.end();it++)
	printf("%lld ",*it);
}