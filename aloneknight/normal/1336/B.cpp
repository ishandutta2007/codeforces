#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db long double
#define pii pair<ll,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define per(i,b,a) for(register int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(register int i=(a);i<(b);++i)
#define fore(i,a) for(register int i=0;i<a.size();++i)
#define gc() getchar()
inline int rd()
{
	int x=0;char c=gc();while(!isdigit(c))c=gc();
	while(isdigit(c))x=x*10+c-48,c=gc();return x;
}
const int N=300005;
int n[3],a[3][N],x[N],y[N],z[N],p1[N],p2[N];
inline ll s2(int x){return 1ll*x*x;}
inline ll calc(int o0,int o1,int o2)
{
	int n0=n[o0],n1=n[o1],n2=n[o2];
	rep(i,1,n0)x[i]=a[o0][i];
	rep(i,1,n1)y[i]=a[o1][i];
	rep(i,1,n2)z[i]=a[o2][i];
	for(int i=1,j=0;i<=n1;i++)
	{
		while(j<n0&&x[j+1]<=y[i])j++;
		p1[i]=j;
	}
	for(int i=n1,j=n2+1;i>=1;i--)
	{
		while(j>1&&z[j-1]>=y[i])j--;
		p2[i]=j;
	}
	ll ans=5000000000000000000ll;
	rep(i,1,n1)if(p1[i]&&p2[i]<=n2)
	{
		int a=x[p1[i]],b=y[i],c=z[p2[i]];
		ans=min(ans,s2(a-b)+s2(a-c)+s2(b-c));
	}
	return ans;
}
void sol()
{
	n[0]=rd();n[1]=rd();n[2]=rd();
	rep(i,1,n[0])a[0][i]=rd();
	rep(i,1,n[1])a[1][i]=rd();
	rep(i,1,n[2])a[2][i]=rd();
	sort(a[0]+1,a[0]+n[0]+1);
	sort(a[1]+1,a[1]+n[1]+1);
	sort(a[2]+1,a[2]+n[2]+1);
	ll ans=calc(0,1,2);
	ans=min(ans,calc(0,2,1));
	ans=min(ans,calc(1,0,2));
	ans=min(ans,calc(1,2,0));
	ans=min(ans,calc(2,0,1));
	ans=min(ans,calc(2,1,0));
	printf("%lld\n",ans);
}
int main()
{
	int T=rd();
	while(T--)sol();
	return 0;
}