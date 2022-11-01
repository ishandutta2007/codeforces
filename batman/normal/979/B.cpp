#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)

ll n,m,cnt[1000];
pair <ll,string> a[3];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<3;i++)
	{
		string s;cin>>s;m=s.size();
		memset(cnt,0,sizeof cnt);
		for(int j=0;j<s.size();j++)
			cnt[(int)s[j]]++,
			a[i].first=max(a[i].first,cnt[(int)s[j]]);
	}
	a[0].second="Kuro";
	a[1].second="Shiro";
	a[2].second="Katie";
	for(int i=0;i<3;i++)
	{
		if(a[i].first==m && n==1)a[i].first=m-1;
		else a[i].first=min(m,a[i].first+n);
	}
	sort(a,a+3);
	if(a[2].first==a[1].first)return cout<<"Draw\n",0;
	cout<<a[2].second<<"\n";
	return 0;
}