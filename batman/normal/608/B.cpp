#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF ((ll)1e14)
#define N (201*1000)

ll num[2][N],ans;
string a,b;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a>>b;
	for(ll i=0;i<a.size();i++)
		num[0][i]=((i)?num[0][i-1]:0)+(a[i]=='0'),num[1][i]=((i)?num[1][i-1]:0)+(a[i]=='1');	
	for(ll i=0;i<b.size();i++)
	{
		bool p=!(b[i]-'0');
		ll r=min(i,(ll)a.size()-1),l=max((ll)a.size()-(ll)b.size()+i,0ll);
		//cout<<l<<" "<<r<<"\n";
		ans+=num[p][r]-((l)?num[p][l-1]:0);
		//cout<<ans<<endl;
	}	
	cout<<ans;
	return 0;
}