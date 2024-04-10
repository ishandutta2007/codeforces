#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long
 
const int N = 1005;
 
int n;
int store[20][N];
 
void query(int idx, vector<int> &v)
{
	if(!v.size())
		return;
	cout << v.size() << endl;
	for(auto &it:v)
		cout << it << " ";
	cout << endl;
	for(int i = 1; i <= n; i++)
		cin >> store[idx][i];
}
 
void work()
{
	for(int b = 0; b < 10; b++)
	{
		vector<int> idx;
		for(int i = 1; i <= n; i++)
			if(i >> b & 1)
				idx.push_back(i);
		query(b, idx);
	}
	for(int b = 0; b < 10; b++)
	{
		vector<int> idx;
		for(int i = 1; i <= n; i++)
			if(!(i >> b & 1))
				idx.push_back(i);
		query(b + 10, idx);
	}
}
 
void output()
{
	vector<int> ans;
	for(int i = 1; i <= n; i++)
	{
		int val = 2e9;
		for(int b = 0; b < 10; b++)
		{
			if(i >> b & 1)
				val = min(val, store[b + 10][i]);
			else
				val = min(val, store[b][i]);
		}
		ans.push_back(val);
	}
	cout << -1 << endl;
	for(auto &it:ans)
		cout << it << " ";
	cout << endl;
}
 
int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < N; j++)
			store[i][j] = 2e9;
	work();
	output();
	return 0;
}