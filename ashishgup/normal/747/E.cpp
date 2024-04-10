#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;

int maxlvl=1;
map<int, vector<string>> m;

void dfs(stringstream &ss, string cur, int lvl)
{
	maxlvl=max(maxlvl, lvl);
	m[lvl].push_back(cur);
	string num;
	getline(ss, num, ',');
	int no=stoi(num);
	for(int i=1;i<=no;i++)
	{
		string nxt;
		getline(ss, nxt, ',');
		dfs(ss, nxt, lvl+1);
	}
}

int32_t main()
{
	IOS;
	string s;
	cin>>s;
	stringstream ss(s);
	string cur;
	while(getline(ss, cur, ','))
	{
		dfs(ss, cur, 1);
	}
	cout<<maxlvl<<endl;
	for(auto it:m)
	{
		for(auto j:it.second)
			cout<<j<<" ";
		cout<<endl;
	}
}