#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int lim=1e18;


int checksq(int k)
{
	int root=sqrt(k);
	for(int i=root-1;i<=root+1;i++)
	{
		if(i*i==k)
			return 1;
	}
	return 0;
}

set<int> s;
vector<int> v;

void preprocess()
{
	for(int i=2;i<=1e6;i++)
	{
		int cur=i*i*i;
		while(true)
		{
			if(!checksq(cur))
				s.insert(cur);
			if(cur<=lim/i)
				cur*=i;
			else
				break;
		}
	}
	for(auto it:s)
		v.push_back(it);
}

inline int self_sqrt(int k)
{
	int root=sqrt(k);
	for(int i=max(0LL, root-2);i<=root+2;i++)
	{
		if(i*i>k)
			return i-1;
	}
}

inline int range(int a, int b)
{
	return upper_bound(v.begin(), v.end(), b) - upper_bound(v.begin(), v.end(), a-1);

}

int32_t main()
{
	IOS;
	preprocess();
	int q;
	cin>>q;
	while(q--)
	{
		int l, r;
		cin>>l>>r;
		int ans=range(l, r);
		ans+=self_sqrt(r) - self_sqrt(l-1);
		cout<<ans<<endl;
	}
	return 0;
}