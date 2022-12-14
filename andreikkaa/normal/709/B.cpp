#include <bits/stdc++.h>
using namespace std;

int f(int x, vector<int> v)
{
	if(x < v.front())
	{
		return v.back() - x;
	}
	if(v.back() < x)
	{
		return x - v.front();
	}
	return min((x - v.front()) * 2 + v.back() - x, (v.back() - x) * 2 + x - v.front());
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, a;
	cin >> n >> a;
	if(n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << min(f(a, vector<int>(v.begin(), v.end() - 1)), f(a, vector<int>(v.begin() + 1, v.end()))) << endl;
	
	return 0;
}