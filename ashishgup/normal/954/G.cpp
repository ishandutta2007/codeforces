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

const int N=1e6+5;
const int INF=2e18;

int n, r, k, sum=0;
int a[N], bit[N], store[N], storetime[N];


int check(int m)
{
	int used=0, getsum=sum;
	queue<pair<int, int> > q;
	for(int i=1;i<=n;i++)
	{
		while(!q.empty() && q.front().first<i-r)
		{
			getsum-=q.front().second;
			q.pop();
		}
		getsum+=a[i+r];		
		if(i-(r+1)>=1)
			getsum-=a[i-(r+1)];
		if(getsum<m)
		{
			int extra=m-getsum;
			getsum+=extra;
			used+=extra;
			q.push({i+r, extra});
		}
		if(used>k)
			break;
	}
	return (used<=k);
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)>>1;
		if(check(mid))
			lo=mid;
		else
			hi=mid-1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	memset(store, -1, sizeof(store));
	cin>>n>>r>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i<=r)
			sum+=a[i];
	}
	int ans=binsearch(0, 2e18);
	cout<<ans;
	return 0;
}