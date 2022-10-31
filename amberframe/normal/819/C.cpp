#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <set>

using namespace std;
typedef long long LL;
const int maxn = 105;

int n1,n2,n3;LL n;int n_[maxn];
int m1,m2,m3;LL m;int m_[maxn];
int s1,s2,s3;LL s;int s_[maxn];
LL ans;

void divide(int n,int *o)
{
	for (int i=2;i*i<=n;i++)
	if (n%i==0) {
		while (n%i==0)
			o[++o[0]]=i,n/=i;
	}
	if (n>1) o[++o[0]]=n;
}
void takeaway(int *o)
{
	sort(o+1,o+o[0]+1);
	o[0]=unique(o+1,o+o[0]+1)-o-1;
}
LL stk[maxn];int top;
LL count(LL n,LL k) {
	LL res=0;
	while (n%k==0)
		n/=k,++res;
	return res;
}
LL power(LL n,LL k) {
	LL res=1ll;
	while (k--) res*=n;
	return res;
}

void work(int stp,LL num,int sig)
{
	if (!num) return ;
	if (stp>top) {ans+=sig*num;return ;}
	work(stp+1,num,sig);
	work(stp+1,num/stk[stp],sig*-1);
}
LL lim[maxn];
void work2(int stp,LL num)
{
	if (!num) return ;
	if (stp>s_[0]) {ans++;return ;}
	for (int i=0;i<=lim[stp]&&num;i++,num/=s_[stp])
		work2(stp+1,num);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("field.in","r",stdin);
		//freopen("field.out","w",stdout);
	#endif
	int T;for (scanf("%d",&T);T--;) {
		scanf("%d %d %d",&n1,&n2,&n3);n_[0]=0;
		scanf("%d %d %d",&m1,&m2,&m3);m_[0]=0;
		scanf("%d %d %d",&s1,&s2,&s3);s_[0]=0;s1*=2;
		divide(n1,n_);divide(n2,n_);divide(n3,n_);n=(LL)n1*n2*n3;
		divide(m1,m_);divide(m2,m_);divide(m3,m_);m=(LL)m1*m2*m3;
		divide(s1,s_);divide(s2,s_);divide(s3,s_);s=(LL)s1*s2*s3;
		
		takeaway(n_);takeaway(m_);takeaway(s_);top=0;
		for (int i=1;i<=n_[0];i++)
		{
			LL cn=count(n,n_[i]);
			LL cs=count(s,n_[i]);
			if (cn>cs) stk[++top]=power(n_[i],cs+1);
		}
		ans=0;work(1,m,1);
		
		for (int i=1;i<=s_[0];i++)
			lim[i]=count(s,s_[i]);
		work2(1,n);printf("%lld\n",ans);
	}
	return 0;
}