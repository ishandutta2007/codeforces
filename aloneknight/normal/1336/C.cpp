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
const int N=3005,P=998244353;
int n,m,ans,f[N][N];char S[N],T[N];
int main()
{
	scanf("%s",S+1);n=strlen(S+1);
	scanf("%s",T+1);m=strlen(T+1);
	rep(i,1,n)
	{
		rep(j,1,n-i+1)
		{
			if(i==1)
			{
				f[i][j]=j<=m?(S[1]==T[j]):1;
				f[i][j]*=2;
				continue;
			}
			if(j+i-1<=m)
			{
				if(S[i]==T[j+i-1])f[i][j]=(f[i][j]+f[i-1][j])%P;
			}
			else f[i][j]=(f[i][j]+f[i-1][j])%P;
			if(j<=m)
			{
				if(S[i]==T[j])f[i][j]=(f[i][j]+f[i-1][j+1])%P;
			}
			else f[i][j]=(f[i][j]+f[i-1][j+1])%P;
		}
		if(i>=m)ans=(ans+f[i][1])%P;
	}
	printf("%d\n",ans);
	return 0;
}