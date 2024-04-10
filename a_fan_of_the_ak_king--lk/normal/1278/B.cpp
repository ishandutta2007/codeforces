#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=100005,M=998244353;
int n,m,s[66],s2[66],t,a,b;
char p[N],c[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&a,&b);
		int i,m=abs(a-b);
		for(i=0;1ll*i*(i+1)/2<m;++i);
		while((1ll*i*(i+1)/2-m)%2!=0)
			++i;
		cout<<i<<endl;
	}
}