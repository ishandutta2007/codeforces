#include <bits/stdc++.h>
using namespace std;
#define N (111)
#define INF ((ll)1e9)
typedef long long ll;
ll n,b,ans;
vector <ll> a;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>b,a.push_back(b);
	sort(a.begin(),a.end());	
	while(a.size())
	{
		ll p=0;
		vector <ll> a2;
		for(int i=0;i<a.size();i++)
		{
			if(a[i]>=p)
				p++;
			else
				a2.push_back(a[i]);	
		}
		ans++;
		a=a2;
	}
	cout<<ans;	
    return 0;
}