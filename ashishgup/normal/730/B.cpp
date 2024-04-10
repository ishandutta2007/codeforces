#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long

const int N = 1e5 + 5;

char query(int x, int y)
{
	cout << "? " << x << " " << y << endl;
	char ch;
	cin >> ch;
	return ch;
}

int work1(vector<int> &v)
{
	while(v.size() > 1)
	{
		vector<int> nv;
		for(int i = 0; i < v.size(); i += 2)
		{
			if(i + 1 >= v.size())
				nv.push_back(v[i]);
			else
			{
				int x = v[i];
				int y = v[i + 1];
				char cur = query(x, y);
				if(cur == '>' || cur == '=')
					nv.push_back(v[i + 1]);
				else
					nv.push_back(v[i]);
			}
		}
		v = nv;
	}
	return v[0];
}


int work2(vector<int> &v)
{
	while(v.size() > 1)
	{
		vector<int> nv;
		for(int i = 0; i < v.size(); i += 2)
		{
			if(i + 1 >= v.size())
				nv.push_back(v[i]);
			else
			{
				int x = v[i];
				int y = v[i + 1];
				char cur = query(x, y);
				if(cur == '<' || cur == '=')
					nv.push_back(v[i + 1]);
				else
					nv.push_back(v[i]);
			}
		}
		v = nv;
	}
	return v[0];
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> mx, mn, v;
		for(int i = 1; i <= n; i++)
			v.push_back(i);
		for(int i = 0; i < v.size(); i += 2)
		{
			if(i + 1 >= v.size())
			{
				mx.push_back(v[i]);
				mn.push_back(v[i]);
			}
			else
			{
				int x = v[i];
				int y = v[i + 1];
				char cur = query(x, y);
				if(cur == '>')
					mx.push_back(v[i]), mn.push_back(v[i + 1]);
				else if(cur == '=')
					mx.push_back(v[i]), mn.push_back(v[i]);
				else
					mx.push_back(v[i + 1]), mn.push_back(v[i]);
			}
		}
		int bestMin = work1(mn);
		int bestMax = work2(mx);
		cout << "! " << bestMin << " " << bestMax << endl;
	}
	return 0;
}