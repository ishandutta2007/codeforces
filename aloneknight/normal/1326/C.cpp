#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define db double
#define ld long double
#define pii pair<int,int> 
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define fore(i,a) for(int i=0;i<a.size();++i) 
const int N=200005,P=998244353;
int n,m,k,ans,p[N],v[N];ll mx;
int main()
{
	scanf("%d%d",&n,&k);mx=0;ans=1;
	for(int i=1;i<=k;i++)mx+=n-i+1;
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)if(p[i]>n-k)v[++m]=i;
	for(int i=1;i<k;i++)ans=1ll*ans*(v[i+1]-v[i])%P;
	printf("%lld %d\n",mx,ans);
	return 0;
}