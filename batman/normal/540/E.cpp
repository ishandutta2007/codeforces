#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=501*1000;

ll n,fen[N],ans;
pair <ll,ll> a[N];
vector <ll> vec,vec2;
map <ll,ll> id;

void update(ll x,ll num){for(;x<N;x+=x&-x)fen[x]+=num;}
ll query(ll x){ll res=0;for(;x>0;x-=x&-x)res+=fen[x];return res;}

int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].first>>a[i].second;
		vec.push_back(a[i].first);
		vec.push_back(a[i].second);
	}
	sort(vec.begin(),vec.end());
	vec.resize(unique(vec.begin(),vec.end())-vec.begin());
	vec2.push_back(0);
	for(int i=0;i<vec.size();i++)
		id[vec[i]]=i+1,vec2.push_back(i+1);
	for(int i=0;i<n;i++)
		swap(vec2[id[a[i].first]],vec2[id[a[i].second]]);
	for(int i=(ll)vec2.size()-1;i>0;i--)
	{
		ans+=query(2*vec2[i]),update(2*vec2[i],1);
		if(i>1)ans+=(long long)query(2*i-1)*(vec[i-1]-vec[i-2]-1),update(2*i-1,vec[i-1]-vec[i-2]-1);
	}
	cout<<ans;
  	return 0;
}