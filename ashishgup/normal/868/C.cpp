#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e5+5;
int n,k;
int store[N][10];
int cache[N][3][2][2][2][2];


int dp(int i, int taken, int a, int b, int c, int d)
{
	if(taken==1)
	{
		if(a==1 && b==1 && c==1 && d==1)
		{
			return 1;
		}
	}
	if(taken==2)
	{
		if(a==1 && b==1 && c==1 && d==1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(i>n)
	{
		return 0;
	}
	if(cache[i][taken][a][b][c][d]!=-1)
	{
		return cache[i][taken][a][b][c][d];
	}
	cache[i][taken][a][b][c][d]=dp(i+1, taken, a, b, c, d);
	int temp[5]={0, a, b, c, d};
	for(int j=1;j<=k;j++)
	{
		if(store[i][j]==0)
		{
			temp[j]=1;
		}
	}
	cache[i][taken][a][b][c][d]|=dp(i+1, taken+1, temp[1], temp[2], temp[3], temp[4]);
	return cache[i][taken][a][b][c][d];
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	memset(cache, -1, sizeof(cache));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cin>>store[i][j];
		}
	}
	int temp[5]={1, 1, 1, 1, 1};
	for(int i=1;i<=k;i++)
	{
		temp[i]=0;
	}
	int ans=dp(1, 0, temp[1], temp[2], temp[3], temp[4]);
	if(ans)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}