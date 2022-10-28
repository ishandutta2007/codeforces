#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, k;
int a[N], pref[N];
vector<int> v;

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1]+a[i];
		if(a[i]>1)
			v.push_back(i);
	}
	int curmax=2e13, ans=0;
	for(int l=1;l<=n;l++)
	{
		int curprod=a[l];
		int curidx=l;
		int cursum=a[l];
		while(true)
		{
			if(curprod==k*cursum)
				ans++;
			auto it=upper_bound(v.begin(), v.end(), curidx);
			if(it==v.end())
			{
				int extra=0, have=n+1-curidx-1;
				if(curprod%k==0)
				{
					extra=curprod/k - cursum;
					if(extra>0 && extra<=have)
					{
						ans++;
					}
				}
				break;
			}
			else
			{
				int extra=0, have=*it - curidx - 1;
				if(curprod%k==0)
				{
					extra=curprod/k - cursum;
					if(extra>0 && extra<=have)
					{
						ans++;
					}
				}
				if(curprod>curmax/a[*it])
					break;
				curprod*=a[*it];
				cursum+=pref[*it] - pref[curidx];
				curidx=*it;
			}
		}
	}
	cout<<ans;
	return 0;
}