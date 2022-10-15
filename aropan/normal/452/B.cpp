#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

#define sqr(x) ((x)*(x))

int main()
{
	int n, m;
	cin >> n >> m;

	vector < pair <int, int> > v;
	set < pair <int, int> > mp;
	mp.insert(make_pair(0, 0));
	if (n) mp.insert(make_pair(1, 0));
	if (m) mp.insert(make_pair(0, 1));

	mp.insert(make_pair(n, 0));
	if (n) mp.insert(make_pair(n - 1, 0));
	if (m) mp.insert(make_pair(n, 1));

	mp.insert(make_pair(0, m));
	if (n) mp.insert(make_pair(1, m));
	if (m) mp.insert(make_pair(0, m - 1));

	mp.insert(make_pair(n, m));
	if (n) mp.insert(make_pair(n - 1, m));
	if (m) mp.insert(make_pair(n, m - 1));
	
	vector < pair <int, int > > a(mp.begin(), mp.end());
	vector < int > p(a.size(), 0);
	for (int i = 0; i < 4; ++i) {
		p[p.size() - 1 - i] = 1;
	}
	double ans = -1;
	vector < pair <int, int> > answer;
	do
	{
		vector < pair <int, int> > v;
		for (size_t i = 0; i < a.size(); ++i) {
			if (p[i]) {
				v.push_back(a[i]);
			}
		}
		
		do
		{
			double s = 0;
			for (int i = 0; i < 3; ++i) {
				s += sqrt(sqr(v[i].first - v[i + 1].first) + sqr(v[i].second - v[i + 1].second));
			}
			if (s > ans) {
				ans = s;
				answer = v;
			}
		} while (next_permutation(v.begin(), v.end()));
	} while (next_permutation(p.begin(), p.end()));
	
	for (int i = 0; i < 4; ++i) {
		cout << answer[i].first << " " << answer[i].second << endl;
	}
	
	cerr << ans << endl;
	return 0;
}