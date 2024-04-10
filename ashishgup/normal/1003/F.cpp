#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5005;

int n, idx=1, ans=0, finans=0;
string a[N], b[N];
string s, temp;
map<pair<string, int>, vector<int> > m;
map<string, int> words;
map<string, string> reduce;

int32_t main()
{
	IOS;
	cin>>n;
	cin.ignore();
	getline(cin, s);
	ans=s.size();
	finans=ans;
	stringstream ss(s);
	while(ss>>temp)
	{
		a[idx++]=temp;
		reduce[temp];
	}
	int cur=1;
	for(auto &it:reduce)
	{
		it.second=to_string(cur);
		cur++;
	}
	for(int i=1;i<=n;i++)
		b[i]=reduce[a[i]];
	for(int i=1;i<=n;i++)
	{
		string cur="";
		int len=0;
		for(int j=i;j<=n;j++)
		{
			cur+=b[j];
			cur+='#';
			len+=a[j].size() - 1;
			if(j!=i)
				len++;
			m[{cur, len}].push_back(i);
			words[cur]=j-i+1;
		}
	}
	for(auto it:m)
	{
		if(it.second.size()==1)
			continue;
		int taken=1, curi=it.second[0];
		while(lower_bound(it.second.begin(), it.second.end(), curi+words[it.first.first])!=it.second.end())
		{
			curi=*(lower_bound(it.second.begin(), it.second.end(), curi+words[it.first.first]));
			taken++;
		}
		if(taken==1)
			continue;
		int cur=ans - it.first.second * taken;
		finans=min(finans, cur);
	}
	cout<<finans;
	return 0;
}