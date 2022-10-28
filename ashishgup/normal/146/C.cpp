#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
string a, b;
map<char, int> m;

int32_t main()
{
	IOS;
	cin>>a>>b;
	n=a.size();
	for(int i=0;i<n;i++)
	{
		if(a[i]==b[i])
			continue;
		m[a[i]]++;
	}
	int p=m['4'], q=m['7'];
	int ans=min(p, q);
	p-=ans;
	q-=ans;
	ans+=p+q;
	cout<<ans;
	return 0;
}