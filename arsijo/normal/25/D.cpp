/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
//#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

struct f {

	int ar[1000 + 1];

	f() {
		for (int i = 0; i <= 1000; i++)
			ar[i] = -1;
	}

	int find(int a) {
		if (ar[a] == a)
			return a;
		if (ar[a] == -1)
			return -1;
		return ar[a] = find(ar[a]);
	}

	void add(int a, int b) {
		//cout << "adding " << a << "(" << find(a) << ") to " << b << "("
		//		<< find(b) << ")" << endl;
		if (ar[b] == -1)
			ar[b] = b;
		ar[a] = b;
	}

	set<int> count() {
		set<int> s;
		for (int i = 0; i <= 1000; i++)
			if (find(i) != -1)
				s.insert(s.begin(), find(ar[i]));
		return s;
	}

};

int main() {

	int n;
	cin >> n;

	f f;

	vector<pair<int, int> > v;

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		//cout << a << " " << b << " " << f.find(a) << " " << f.find(b) << endl;
		if (f.find(a) == f.find(b) && f.find(b) != -1) {
			//cout << "+" << endl;
			v.push_back(make_pair(a, b));
		} else {
			if (f.find(a) != -1 && f.find(b) != -1)
				f.add(f.find(a), f.find(b));
			else if (f.find(a) == -1 || f.find(a) == a)
				f.add(a, b);
			else
				f.add(b, a);
		}
	}

	for (int i = 1; i <= n; i++)
		if (f.find(i) == -1)
			f.add(i, i);

//	for (int i = 1; i <= n; i++)
//		cout << f.find(i) << " ";

	//cout << endl;

	cout << v.size() << endl;
	set<int> s = f.count();
	int g = *s.begin(), i = 0;
	for (set<int>::iterator it = ++s.begin(); it != s.end() && i < v.size();
			it++, i++) {
		cout << v[i].first << " " << v[i].second << " " << g << " " << *it
				<< endl;
	}

}