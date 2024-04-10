#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e5+5;

vector<int> g[N];

int n, check=1;

void dfs(int k)
{
	if(!g[k].size())
		return;
	int count=0;
	for(auto it:g[k])
	{
		if(!g[it].size())
			count++;
	}
	if(count<3)
		check=0;
	for(auto it:g[k])
		dfs(it);
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
    	int u=i;
    	int v;
    	cin>>v;
    	g[v].push_back(u);
    }
    dfs(1);
    if(check)
    	cout<<"Yes";
    else
    	cout<<"No";
    return 0;
}