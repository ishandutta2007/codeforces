#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int &x : a)
		cin >> x;

	multiset<int> s;

	{
		for(int i = 0; i < n; ++i){
			int x;
			cin >>x;
			s.insert(x);
		}
	}

	for(int &x : a) {
		assert(!s.empty());
		auto it = s.lower_bound(n -x);
		if(it == s.end())
			it = s.begin();
		cout << (x + *it) % n << ' ';
		s.erase(it);
	}
	return 0;
}