#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m, q;
string s, t;
int pref[N];

vector<int> prefix_function(string &s) 
{
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i < n; i++) 
	{
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

int32_t main()
{
	IOS;
	cin>>n>>m>>q;
	cin>>s>>t;	
	t+='#';
	t+=s;
	vector<int> lps=prefix_function(t);
	for(int i=m+1;i<=n+m;i++)
	{
		if(lps[i]==m)
			pref[i-2*m]=1;
	}
	for(int i=0;i<=m+n;i++)
	{
		pref[i]+=pref[i-1];
	}
	for(int i=1;i<=q;i++)
	{
		int l, r;
		cin>>l>>r;
		r-=m;
		l-=1;
		if(r<l)
		{
			cout<<"0"<<endl;
			continue;
		}
		int ans=0;
		if(r>=l && r>=0)
			ans=pref[r];
		if(l>=1)
			ans-=pref[l-1];
		cout<<ans<<endl;
	}
	return 0;
}