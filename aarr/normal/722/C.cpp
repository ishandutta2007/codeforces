#include <iostream>

#include <set>

using namespace std;

int a[100005];
long long ps[100005];
pair<long long, long long> pii;
set<pair< long long, long long> > s;
set<pair< long long, long long> > ss;
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		ps[i] = ps[i - 1] + a[i];
	}
	s.insert({0, 0});
	ss.insert({0, 0});
	s.insert({n + 1, ps[n]});
	ss.insert({ps[n], n + 1});
	for(int i = 0; i < n; i ++)
	{
		int x;
		cin >> x;
		set<pair < long long, long long > > :: iterator it;
		set<pair < long long, long long > > :: iterator itt;
		it = s.upper_bound({x, 0});
		pii = *it;
		it --;
		long long y = pii.first, z = pii.second;
		pii = *it;
		s.erase({y, z});
		ss.erase({z, y});
		long long q = ps[x] - ps[pii.first];
		s.insert({y, z - q});
		s.insert({x, ps[x - 1] - ps[pii.first]});
		ss.insert({z - q, y});
		ss.insert({ps[x - 1] - ps[pii.first], x});
		itt = ss.end();
		itt --;
		//cout << x << " " << y << " " << pii.second << " " << z << " " << (*itt).first << " " << (*itt).second << endl;
		cout << (*itt).first << endl;
	}
	return 0;
}