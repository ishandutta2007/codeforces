#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
 
template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
 
const int N=2e5+5;

int n, m, half;
int a[N];
set<int> p, q;

void run1()
{
	for(int i=1;i<(1<<half);i++)
	{
		int cur=0;
		for(int j=0;j<half;j++)
		{
			if(i&(1<<j))
			{
				cur+=a[j+1];
				cur%=m;
			}
		}
		p.insert(cur);
	}
}

void run2()
{
	half=n-half;
	for(int i=0;i<(1<<half);i++)
	{
		int cur=0;
		for(int j=0;j<half;j++)
		{
			if(i&(1<<j))
			{
				cur+=a[j+(n-half)+1];
				cur%=m;
			}
		}
		q.insert(cur);
	}
}

int32_t main()
{
    IOS;
    cin>>n>>m;
    half=n/2;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	a[i]%=m;
    	ans=max(ans, a[i]);
    }
    run1();
    run2();
    for(auto it:p)
    {
    	auto it2=q.lower_bound(m-it);
    	if(it2==q.begin())
    		continue;
    	it2--;
    	ans=max(ans, (it+*it2)%m);
    }
    cout<<ans;
    return 0;
}