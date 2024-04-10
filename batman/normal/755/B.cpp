#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)1001*1000)
#define K ((ll)20)

ll n,m,num;
map <string,bool> mp;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		mp[s]=1;
	}
	for(int i=0;i<m;i++)
	{
		string s;
		cin>>s;
		if(mp[s])num++;
	}
	if(n>m)return cout<<"YES",0;
	if(n<m)return cout<<"NO",0;
	cout<<((num%2)?"YES":"NO");
	return 0;
}