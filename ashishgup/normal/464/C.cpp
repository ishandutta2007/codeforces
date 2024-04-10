#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;
const int MOD=1e9+7;

int n;
int a[N];
string s; 
string b[N];
int val[N][10], pw[N][10];


int32_t main()
{
    IOS;
	cin>>s>>n;
	for(int i=1;i<=n;i++)
	{
		string cur;
		cin>>cur;
		stringstream ss(cur);
		int num;
		char ch;
		ss>>num>>ch>>ch;
		a[i]=num;
		ss>>b[i];
	}
	for(int i=0;i<=9;i++)
	{
		val[n+1][i]=i;
		pw[n+1][i]=10;
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<=9;j++)
		{
			val[i][j]=val[i+1][j];
			pw[i][j]=pw[i+1][j];
		}
		int cur=a[i];
		val[i][cur]=0;
		pw[i][cur]=1;
		for(auto it:b[i])
		{
			int next=it-'0';
			val[i][cur]=val[i][cur]*pw[i+1][next] + val[i+1][next];
			pw[i][cur]=pw[i][cur]*pw[i+1][next];
			val[i][cur]%=MOD;
			pw[i][cur]%=MOD;
		}
	}
	int ans=0;
	for(auto it:s)
	{
		int cur=it-'0';
		ans=ans*pw[1][cur] + val[1][cur];
		ans%=MOD;
	} 
	cout<<ans;
    return 0;
}