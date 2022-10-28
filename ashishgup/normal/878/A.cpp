#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e6+5;
const int MOD=1e9+7;

int num;
int ans[10];

void applyxor(int i)
{
	if(ans[i]==0)
		ans[i]=1;
	else if(ans[i]==1)
		ans[i]=0;
	else if(ans[i]==2)
		ans[i]=3;
	else
		ans[i]=2;
}

int32_t main()
{
	IOS;
	for(int i=0;i<10;i++)
	{
		ans[i]=3;
	}
	cin>>num;
	for(int i=1;i<=num;i++)
	{
		char ch;
		int n;
		cin>>ch>>n;
		for(int j=0;j<10;j++)
		{
			if(n&(1<<j))
			{
				if(ch=='|')
				{
					ans[j]=1;
				}
				else if(ch=='^')
				{
					applyxor(j);
				}
			}
			else
			{
				if(ch=='&')
				{
					ans[j]=0;
				}
			}
		}
	}
	int storeand=0;
	for(int i=0;i<10;i++)
	{
		if(!(ans[i]==0))
		{	
			storeand+=(1<<i);
		}
	}	
	cout<<3<<endl;
	cout<<"& "<<storeand<<endl;
	int storeor=0;
	for(int i=0;i<10;i++)
	{
		if(ans[i]==1)
		{
			storeor+=(1<<i);
		}
	}
	cout<<"| "<<storeor<<endl;
	int storexor=0;
	for(int i=0;i<10;i++)
	{
		if(ans[i]==2)
		{
			storexor+=(1<<i);
		}
	}
	cout<<"^ "<<storexor<<endl;
}