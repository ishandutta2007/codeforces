#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long

const int N = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int n, k;

string query(vector<int> &a, vector<int> &b)
{
	cout << "? " << a.size() << " " << b.size() << endl;
	for(auto &it:a)
		cout << it << " ";
	cout << endl;
	for(auto &it:b)
		cout << it << " ";
	cout << endl;
	string s;
	cin >> s;
	assert(s != "WASTED");
	return s;
}

string query2(int a, int b)
{
	cout << "? " << 1 << " " << 1 << endl;
	cout << a << endl;
	cout << b << endl;
	string s;
	cin >> s;
	assert(s != "WASTED");
	return s;
}

void report(int x)
{
	cout << "! " << x << endl;
}

int getStone()
{
	vector<int> v;
	for(int i = 1; i <= n; i++)
		v.push_back(i);
	shuffle(v.begin(), v.end(), rng);
	int x = v.back();
	v.pop_back();
	int y = v.back();
	v.pop_back();
	string ans = query2(x, y);
	int store;
	if(ans == "SECOND")
		store = y;
	else
		store = x;
	for(int i = 1; i <= 13; i++)
	{
		if(!v.size())
			break;
		int y = v.back();
		v.pop_back();
		string ans = query2(store, y);
		if(ans == "SECOND")
			store = y;
	}
	return store;
}

void recurse(vector<int> &v, int sz)
{
	if(v.size() == 1)
	{
		report(v[0]);
		return;
	}
	if(v.size() <= sz)
		recurse(v, sz / 2);
	else
	{
		vector<int> l, r;
		for(int i = 0; i < sz; i++)
			l.push_back(v[i]);
		for(int i = sz; i < v.size(); i++)
			r.push_back(v[i]);
		vector<int> pet;
		for(int i = 1; i <= sz; i++)
			pet.push_back(i);
		string cur = query(pet, l);
		if(cur == "EQUAL")
			recurse(r, sz / 2);
		else
			recurse(l, sz / 2);
	}
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		int idx = getStone();
		bool printed = 0;
		if(idx != 1)
		{
			string cur = query2(idx, 1);
			if(cur == "FIRST")
			{
				report(1);
				printed = 1;
			}
			if(printed)
				continue;
			idx = 1;
		}
		vector<int> stones;
		stones.push_back(1);
		vector<int> cand;
		while(true)
		{
			int i = stones.size();
			int take = stones.size();
			cand.clear();
			while(take > 0 && i < n)
			{
				cand.push_back(++i);
				take--;
			}
			if(take > 0)
				break;
			string cur = query(stones, cand);
			if(cur == "EQUAL")
			{
				for(auto &it:cand)
					stones.push_back(it);
			}
			else
				break;
		}
		recurse(cand, stones.size() / 2);
	}
	return 0;
}