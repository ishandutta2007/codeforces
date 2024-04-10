#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	string s;
	cin>>s;
	vector<int> a, b;
	for(int i=0;i<=2;i++)
		a.push_back(s[i]-'0');
	for(int i=3;i<=5;i++)
		b.push_back(s[i]-'0');
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int suma=0, sumb=0;
	for(auto &it:a)
		suma+=it;
	for(auto &it:b)
		sumb+=it;
	int ans=6;
	for(int sum=0;sum<=27;sum++)
	{
		int cura=suma, curb=sumb;
		int movesa=0, movesb=0;
		for(int i=0;i<a.size();i++)
		{	
			int take=max(sum-cura, 0LL);
			take=min(take, 9-a[i]);
			movesa+=(take>0);
			cura+=take;
		}	
		for(int i=0;i<b.size();i++)
		{	
			int take=max(sum-curb, 0LL);
			take=min(take, 9-b[i]);
			movesb+=(take>0);
			curb+=take;
		}	
		for(int i=2;i>=0;i--)
		{	
			int take=max(cura-sum, 0LL);
			take=min(take, a[i]);
			movesa+=(take>0);
			cura-=take;
		}	
		for(int i=2;i>=0;i--)
		{	
			int take=max(curb-sum, 0LL);
			take=min(take, b[i]);
			movesb+=(take>0);
			curb-=take;
		}		
		ans=min(ans, movesa+movesb);
	}
	cout<<ans;
	return 0;
}