#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll N=51*1000;

ll n;
pair<ll,ll> a[N];
ld now,ans;

bool cmp(pair <ll,ll> a,pair <ll,ll> b){return a.second*(100-b.second)*a.first<b.second*(100-a.second)*b.first;}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i].first>>a[i].second;
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
		ans+=((ld)a[i].second*(now+1)*a[i].first+(ld)(100-a[i].second)*a[i].first)/100,now+=1-(ld)a[i].second/100;
	cout<<fixed<<setprecision(14)<<ans<<"\n";
  	return 0;
}