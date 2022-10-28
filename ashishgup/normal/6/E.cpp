#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k;
int a[N];

int check(int x)
{
	multiset<int> s;
	for(int i=1;i<=x;i++)
		s.insert(a[i]);
	if(*(--s.end()) - *(s.begin()) <= k)
		return 1;
	for(int i=x+1;i<=n;i++)
	{
		s.insert(a[i]);
		s.erase(s.find(a[i-x]));
		if(*(--s.end()) - *(s.begin()) <= k)
			return 1;
	}
	return 0;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)>>1;
		if(check(mid))
			lo=mid;
		else
			hi=mid-1;
	}
	return lo;
}

vector<int> getans(int x)
{
	vector<int> v;
	multiset<int> s;
	for(int i=1;i<=x;i++)
		s.insert(a[i]);
	if(*(--s.end()) - *(s.begin()) <= k)
		v.push_back(1);
	for(int i=x+1;i<=n;i++)
	{
		s.insert(a[i]);
		s.erase(s.find(a[i-x]));
		if(*(--s.end()) - *(s.begin()) <= k)
			v.push_back(i-x+1);
	}
	return v;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans1=binsearch(1, n);
	vector<int> v=getans(ans1);
	cout<<ans1<<" "<<v.size()<<endl;
	for(auto it:v)
		cout<<it<<" "<<it+ans1-1<<endl;
}