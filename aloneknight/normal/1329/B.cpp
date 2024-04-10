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
const int N=35;
int n,m,a[N];
int main()
{
	int T;T=rd();
	rep(i,1,30)a[i]=1<<i-1;
	while(T--)
	{
		int n=rd(),m=rd(),s=1;
		rep(i,1,30)
		{
			int t=min(n,a[i]);
			s=1ll*s*(t+1)%m;n-=t;
		}
		printf("%d\n",(s+m-1)%m);
	}
	return 0;
}