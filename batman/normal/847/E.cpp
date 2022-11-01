#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)

ll n;
string s;
vector <ll> p,q;

bool check(ll x)
{
	ll lst=-1;
	for(int i=0,j=0;i<q.size();i++)
	{
	//	cout<<lst<<"\n";
		if(q[i]<=lst)continue;
		bool flg=0;
		while(j<p.size())
		{
	//		cout<<"hir";
			if(abs(q[i]-p[j])>x)
			{
				j++;
				continue;
			}
			flg=1;
			if(p[j]<q[i])lst=p[j]+x;
			else lst=max(p[j]+(x-(p[j]-q[i]))/2,p[j]+(x-(p[j]-q[i])*2));
			j++;
			break;
		}
		if(!flg)return 0;
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='P')p.push_back(i);
		if(s[i]=='*')q.push_back(i);
	}
	//cout<<check(10)<<"\n";
	
	ll l=0,r=N;
	while(l<r-1)
	{
		ll mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	cout<<r<<"\n";
	return 0;
}