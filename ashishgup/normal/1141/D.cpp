#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 5e5 + 5;

int n;
char l[N], r[N];
map<char, vector<int> > a, b;
vector<pair<int, int> > ans;

void work(char ch1, char ch2)
{
	int sz = min(a[ch1].size(), b[ch2].size());
	while(sz > 0)
	{
		int i = a[ch1].back();
		a[ch1].pop_back();
		int j = b[ch2].back();
		b[ch2].pop_back();
		sz--;
		ans.push_back({i, j});
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
		a[l[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
		b[r[i]].push_back(i);
	}	
	for(char ch='a';ch<='z';ch++)
		work(ch, ch);
	for(char ch='a';ch<='z';ch++)
		work('?', ch);
	for(char ch='a';ch<='z';ch++)
		work(ch, '?');
	for(char ch='a';ch<='z';ch++)
		work('?', '?');
	cout<<ans.size()<<endl;
	for(auto &it:ans)
		cout<<it.first<<" "<<it.second<<endl;
	return 0;
}