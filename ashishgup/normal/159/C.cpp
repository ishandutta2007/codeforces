#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=26;

#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

int k;
string s;
int f[N], sz[N];
vector<int> g[N];
set<int> del[N];

int getless(ordered_set &os, int key)
{
	return os.order_of_key(key);
}

ordered_set os[26];

int binsearch(char ch, int lo, int hi, int reqd)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)>>1;
		if(mid + 1 - getless(os[ch], mid)<=reqd)
			lo=mid;
		else
			hi=mid-1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin>>k>>s;
	string str="";
	for(int i=1;i<=k;i++)
		str+=s;
	int n=str.size();
	for(int i=0;i<n;i++)
	{
		g[str[i]-'a'].push_back(i);
		sz[str[i]-'a']++;
	}
	int q;
	cin>>q;
	while(q--)
	{
		int occ;
		char ch;
		cin>>occ>>ch;
		ch-='a';
		int actual=binsearch(ch, 0, sz[ch]-1, occ);
		del[ch].insert(actual);
		os[ch].insert(actual);
	}
	vector<pair<int, char> > ans;
	for(int i=0;i<=25;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			if(del[i].find(j)==del[i].end())
			{
				char ch=(char)(i+'a');
				ans.push_back({g[i][j], ch});
			}
		}
	}
	sort(ans.begin(), ans.end());
	for(auto it:ans)
		cout<<it.second;
	return 0;
}