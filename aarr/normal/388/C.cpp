#include <iostream>

#include <algorithm>

#include <deque>

using namespace std;

pair<int, deque<int> > v[105];
int main()
{
	int n, a = 0, b = 0, s = 0;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int x;
		cin >> x;
		for(int j = 0; j < x; j ++)
		{
			int y;
			cin >> y;
			v[i].second.push_back(y);
		}
		s += x;
		if(x % 2 == 1)
		{
			v[i].first = v[i].second[x / 2];
		}
	}
	for(int i = 0; i < s; i ++)
	{
		sort(v, v + n);
		int k = n - 1;
		while(v[k].second.size() == 0)
		{
			k --;
		}
		//cout << k << " " << v[k].first << endl;
		if(i % 2 == 0)
		{
			a += v[k].second[0];
			v[k].second.pop_front();
			
		}
		else
		{
			b += v[k].second[v[k].second.size() - 1];
			v[k].second.pop_back();
		}
		if(v[k].second.size() % 2 == 1)
		{
			v[k].first = v[k].second[v[k].second.size() / 2];
		}
		else
		{
			v[k].first = 0;
		}
	}
	cout << a << " " << b;
	return 0;
}