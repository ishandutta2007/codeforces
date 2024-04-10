#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int pref[N], leftidx[N], bestend[N];
string s;
map<char, char> opp;
stack<pair<char, int> > st;

int range(int l, int r)
{
	if(l>=1)
		return pref[r] - pref[l-1];
	return pref[r];
}

int32_t main()
{
	IOS;
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(i>=1)
			pref[i]=pref[i-1] + (s[i]=='[');
		else
			pref[i]=(s[i]=='[');
	}
	int ans=0, idx=0, len=0;
	opp[')']='(';
	opp[']']='[';
	for(int i=0;i<n;i++)
	{
		if(s[i]=='('||s[i]=='[')
		{
			st.push({s[i], i});
		}
		else
		{
			if(!st.size())
				continue;
			if(st.top().first!=opp[s[i]])
			{
				while(st.size())
					st.pop();
			}
			else
			{
				pair<char, int> p=st.top();
				st.pop();
				int store=0;
				if(p.second>=1)
					store=bestend[p.second-1];
				if(store + range(p.second, i)>ans)
				{
					ans=store + range(p.second, i);
					idx=p.second;
					if(store>0)
						idx=leftidx[p.second-1];
					len=i-idx+1;
				}
				bestend[i]=store + range(p.second, i);
				leftidx[i]=p.second;
				if(store>0)
						leftidx[i]=leftidx[p.second-1];
			}
		}
	}
	cout<<ans<<endl;
	cout<<s.substr(idx, len);
	return 0;
}