#include <bits/stdc++.h>
using namespace std;
int n,a[333333];
map <int,int> mp;
vector <int> v;

int main()
{
	cin>>n;
	for(int i=0;i<n*n;i++)cin>>a[i],mp[a[i]]++;
	sort(a,a+n*n);
	for(int i=n*n-1;i>=0;i--)
		if(mp[a[i]]>0)
		{
			cout<<a[i]<<" ";
			for(int j=0;j<v.size();j++)mp[__gcd(a[i],v[j])]-=2;
			v.push_back(a[i]),mp[a[i]]--;
		}
		
    return 0;
}