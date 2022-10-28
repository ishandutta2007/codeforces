#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

void work(int n, vector<int> &v)
{
	v.clear();
	v.push_back(1);
	for(int L = 1, d = n; L <= n;)
	{
		int U = n / d;
		v.push_back(U + 1);
		L = U + 1, d = n / L;
	}
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
		vector<int> v;
		work(n, v);
		set<int> s;
		s.insert(0);
		for(auto &it:v)
			s.insert(n / it);
		cout << s.size() << endl;
		for(auto &it:s)
			cout << it << " ";
		cout << endl;
	}
	return 0;
}