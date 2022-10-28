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

const int N=2e5+5;

int n, T;
int a[N], t[N];

int check(int k)
{
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=k)
		{
			v.push_back(t[i]);
		}
	}
	if(v.size()<k)
		return false;
	sort(v.begin(), v.end());
	int reqd=0;
	for(int i=0;i<k;i++)
	{
		reqd+=v[i];
		if(reqd>T)
			return false;
	}
	if(reqd<=T)
		return true;
	return false;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)/2;
		if(check(mid))
		{
			lo=mid;
		}
		else
		{
			hi=mid-1;
		}
	}
	return lo;
}

int32_t main()
{
    IOS;
    cin>>n>>T;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i]>>t[i];
   	}
   	int ans=binsearch(0, n);
   	cout<<ans<<endl;
   	cout<<ans<<endl;
   	vector<pair<int, int> > v;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=ans)
		{
			v.push_back(make_pair(t[i], i));
		}
	}
	sort(v.begin(), v.end());
	for(int i=0;i<ans;i++)
	{
		cout<<v[i].second<<" ";
	}
	cout<<endl;
    return 0;
}