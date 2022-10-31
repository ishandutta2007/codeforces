#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll N=201*1000;
const ll K=1001*1000;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)1e9);
const ll SQ=((ll)400);

int n,t,a[N],num[K];
ll now,ans[N];
pair <pair<int,int>,int> sg[N];

bool cmp(pair <pair<int,int>,int> a,pair <pair<int,int>,int> b)
{
	if(a.first.first/SQ!=b.first.first/SQ)return a.first.first<b.first.first;
	return a.first.second<b.first.second;
}

void add(int x){now+=(2*(ll)num[a[x]]+1)*a[x];num[a[x]]++;}
void remove(int x){now-=(2*(ll)num[a[x]]-1)*a[x];num[a[x]]--;}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>t;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<t;i++)
		cin>>sg[i].first.first>>sg[i].first.second,sg[i].second=i;
	sort(sg,sg+t,cmp);
	num[a[1]]=1;now+=a[1];
	for(int i=0,l=1,r=1;i<t;i++)
	{
		int l2=sg[i].first.first,r2=sg[i].first.second;
		while(l2<l)l--,add(l);
		while(r<r2)r++,add(r);
		while(l<l2)remove(l),l++;
		while(r2<r)remove(r),r--;
		ans[sg[i].second]=now;
	}
	for(int i=0;i<t;i++)cout<<ans[i]<<"\n";
	return 0;
}