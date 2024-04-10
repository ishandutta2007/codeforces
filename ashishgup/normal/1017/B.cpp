#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=0;
string a, b;
int f[5], store[2][2][N];

int32_t main()
{
	IOS;
	cin>>n;
	cin>>a>>b;
	for(auto &it:a)
		f[it-'0']++;
	for(int i=0;i<n;i++)
		store[a[i]-'0'][b[i]-'0'][i]++;
	for(int i=n-1;i>=0;i--)
	{
		store[0][1][i]+=store[0][1][i+1];
		store[0][0][i]+=store[0][0][i+1];
		store[1][1][i]+=store[1][1][i+1];
		store[1][0][i]+=store[1][0][i+1];
	}
	for(int i=0;i<n;i++)
	{
		int cur=a[i]-'0';
		cur^=1;
		if(b[i]=='0')
			ans+=store[cur][0][i+1] + store[cur][1][i+1];
		else
			ans+=store[cur][0][i+1];
	}
	cout<<ans;
	return 0;
}