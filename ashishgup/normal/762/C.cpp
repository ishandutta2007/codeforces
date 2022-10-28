#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
string a, b;
int pref[N], suf[N];
int l, r;

void update(int curl, int curr)
{
	int prev=l+1 + (m-r);
	int cur=(curl+1) + (m-curr);
	cur=min(cur, m);
	if(cur>prev)
		l=curl, r=curr;
}

int32_t main()
{
	IOS;
	cin>>a>>b;
	n=a.size();
	m=b.size();
	l=-1, r=m;
	int idx=0;
	for(int i=0;i<m;i++)
	{
		while(idx<n && a[idx]!=b[i])
			idx++;
		pref[i]=idx;
		idx=min(idx+1, n);
		if(pref[i]<n)
			update(i, m);
	}
	idx=n-1;
	for(int i=m-1;i>=0;i--)
	{
		while(idx>=0 && a[idx]!=b[i])
			idx--;
		suf[i]=idx;
		idx=max(-1LL, idx-1);
		if(suf[i]>=0)
			update(-1, i);
	}
	if(l==-1 && r==m)
	{
		cout<<"-";
		return 0;
	}
	int rr=0;
	for(int ll=0;ll<m;ll++)
	{
		while(rr<m && suf[rr]<=pref[ll])
			rr++;
		if(pref[ll]<n)
			update(ll, rr);
	}
	cout<<b.substr(0, l+1)<<b.substr(r);
	return 0;
}