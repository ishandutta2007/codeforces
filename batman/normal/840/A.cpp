#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)301*1000)
#define SQ ((ll)1200)

ll n,a[N],ans[N];
pair <ll,ll> b[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i].first,b[i].second=i;
	sort(a,a+n);
	sort(b,b+n);
	for(int i=0;i<n;i++)
		ans[b[i].second]=a[n-1-i];
	for(int i=0;i<n;i++)cout<<ans[i]<<" ";cout<<"\n";
	return 0;
}