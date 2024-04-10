#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N (1111)
ll n,k,sum;
bool mark[N];
pair <ll,ll> b[N];
pair <pair<ll,ll>,ll> a[N];
vector <pair <ll,ll> > ans;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i].first.second>>a[i].first.first,a[i].second=i+1;
    sort(a,a+n);
    cin>>k;
    for(int i=0;i<k;i++)cin>>b[i].first,b[i].second=i+1;
    sort(b,b+k);
    for(int i=n-1;i>=0;i--)
    {
    	for(int j=0;j<k;j++)
    		if(b[j].first>=a[i].first.second && !mark[j])
    		{
    			sum+=a[i].first.first,ans.push_back({a[i].second,b[j].second}),mark[j]=1;
    			break;
			}
	}
	cout<<ans.size()<<" "<<sum<<"\n";
	for(int i=0;i<ans.size();i++)cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	return 0;
}