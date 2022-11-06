#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db double
#define ld long double
#define pii pair<int,int> 
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i) 
inline int rd()
{
	int x=0,w=1;char c=getchar();while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();while(isdigit(c))x=x*10+c-48,c=getchar();return x*w;
}
const int N=100005;
int n,m,a[N];ll s[N];
int main()
{
	n=rd();m=rd();rep(i,1,m)a[i]=rd();
	per(i,m,1)s[i]=s[i+1]+a[i];
	if(s[1]<n){puts("-1");return 0;}
	rep(i,1,m)if(i+a[i]-1>n){puts("-1");return 0;}
	rep(i,1,m)if(i+s[i+1]<=n&&i-1+s[i]>=n)
	{
		rep(j,1,i)printf("%d ",j);
		rep(j,i+1,m)printf("%lld ",n-s[j]+1);
		return 0;
	}
	while(true);return 0;
}