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
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
#define gc() getchar()
inline int rd()
{
	int x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')w=-1,c=gc();while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=2105;
int n,k,a[N],A[15],b[N],f[N][N];
int main()
{
	scanf("%d%d",&n,&k);
	{
		string s;
		s="1110111";
		rep(j,0,6)A[0]|=(s[j]-'0')<<j;
		s="0010010";
		rep(j,0,6)A[1]|=(s[j]-'0')<<j;
		s="1011101";
		rep(j,0,6)A[2]|=(s[j]-'0')<<j;
		s="1011011";
		rep(j,0,6)A[3]|=(s[j]-'0')<<j;
		s="0111010";
		rep(j,0,6)A[4]|=(s[j]-'0')<<j;
		s="1101011";
		rep(j,0,6)A[5]|=(s[j]-'0')<<j;
		s="1101111";
		rep(j,0,6)A[6]|=(s[j]-'0')<<j;
		s="1010010";
		rep(j,0,6)A[7]|=(s[j]-'0')<<j;
		s="1111111";
		rep(j,0,6)A[8]|=(s[j]-'0')<<j;
		s="1111011";
		rep(j,0,6)A[9]|=(s[j]-'0')<<j;
	}
	rep(i,1,n)
	{
		char s[20];scanf("%s",s);
		rep(j,0,6)a[i]|=(s[j]-'0')<<j;
	} 
	b[0]=0;
	rep(i,1,127)b[i]=b[i>>1]+(i&1);
	f[n+1][0]=1;
	per(i,n,1)
	{
		rep(j,0,k)rep(c,0,9)if((a[i]&A[c])==a[i])
		{
			int w=b[a[i]^A[c]];
			if(j>=w&&f[i+1][j-w])f[i][j]=1;
		}
	}
	if(f[1][k]==0)
	{
		puts("-1");
		return 0;
	}
	rep(i,1,n)
	{
		per(c,9,0)if((a[i]&A[c])==a[i])
		{
			int w=b[a[i]^A[c]];
			if(k>=w&&f[i+1][k-w])
			{
				k-=w;
				putchar('0'+c);
				break;
			}
		}
	}
	return 0;
}