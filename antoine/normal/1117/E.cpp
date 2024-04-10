#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Group {
	int n;
	vector<int> indexes;

	Group(const int n) :
			n(n) {
		indexes.resize(n);
		for (int i = 0; i < n; ++i)
			indexes[i] = i;
	}

	Group(vector<int> v) :
			n(v.size()), indexes(v) {
	}

	vector<int> getSizes() const {
		vector<int> res;

		for (int i = 0; i < 26; ++i) {
			const int sz = n / 26 + (i < n % 26);
			if (!sz)
				break;
			res.push_back(sz);
		}
		return res;
	}

	string f() const {
		const vector<int> sizes = getSizes();
		string res;
		for (int i = 0; i < (int) sizes.size(); ++i)
			res += string(sizes[i], char('a' + i));
		return res;
	}

	vector<Group> g(const string t) const {
		map<char, vector<int>> mp;
		for (const int &x : indexes)
			mp[t[x]].push_back(x);

		const vector<int> sizes = getSizes();
		vector<Group> res;
		for (int i = 0; i < (int) sizes.size(); ++i) {
			res.push_back(Group(mp['a' + i]));
		}
		return res;
	}
};

vector<int> findPerm(const int n) {
	vector<Group> groups = { Group(n) };
	for (int rep = 0; rep < 3; ++rep) {
		cout << "? ";
		for (const Group &x : groups)
			cout << x.f();
		cout << endl;
		string resp;
		cin >> resp;

		vector<Group> newGroups;
		for (const Group &x : groups) {
			const vector<Group> res = x.g(resp);
			newGroups.insert(newGroups.end(), res.begin(), res.end());
		}
		groups = move(newGroups);
	}

	assert((int)groups.size() == n);

	vector<int> res;
	for(const Group &x : groups) {
		assert(x.n == 1);
		res.push_back(x.indexes[0]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string t;
	cin >> t;

	const vector<int> prem = findPerm((int) t.size());

	string s(t.size(), '.');
	for (int i = 0; i < (int) prem.size(); ++i)
		s[i] = t[prem[i]];

	cout << "! " << s;
	return 0;
}