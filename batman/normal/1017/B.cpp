#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)501*1000)

ll n,cnt[2],cnt2[2],ans;
string s,t;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s>>t;
	ans=n*(n-1)/2;
	for(int i=0;i<n;i++)
	{
		cnt[0]+=(s[i]=='0');
		cnt[1]+=(s[i]=='1');
		cnt2[0]+=(s[i]=='0' && t[i]=='1');
		cnt2[1]+=(s[i]=='1' && t[i]=='1');
	}
	ans-=cnt[0]*(cnt[0]-1)/2+cnt[1]*(cnt[1]-1)/2;
	ans-=cnt2[0]*cnt2[1];
	cout<<ans<<"\n";
	return 0;
}