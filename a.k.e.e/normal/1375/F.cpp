#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}

ll a[4];
pair<ll,int> pr[4];

int main()
{
	#ifndef ONLINE_JUDGE
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	for(int i=1;i<=3;++i)readint(a[i]);
	printf("First\n");fflush(stdout);
	loop:
	for(int i=1;i<=3;++i)pr[i]=mp(a[i],i);
	sort(pr+1,pr+4);
	ll v=2*pr[3].x-pr[2].x-pr[1].x;
	int s;
	printf("%lld\n",v);fflush(stdout);
	readint(s);
	if(!s)return 0;
	a[s]+=v;
	for(int i=1;i<=3;++i)
		if(pr[i].y==s)
		{
			pr[i].x+=v;
			if(i==1)printf("%lld\n",pr[3].x-pr[2].x);
			else if(i==2)printf("%lld\n",pr[3].x-pr[1].x);
			else goto loop;
			fflush(stdout);
			readint(s);
			assert(!s);
			return 0;
		}
	return 0;
}