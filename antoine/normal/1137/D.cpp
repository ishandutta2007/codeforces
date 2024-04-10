#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Interactor {
	int pos[10];
	int numComps = 1;

	Interactor() {
		memset(pos, 0, sizeof pos);
	}

	void play(const vector<int> v) {
		cout << "next";
		for (int x : v)
			cout << ' ' << x;
		cout << endl;

		string s;
		cin >> s;
		if (s == "stop")
			exit(0);

		int k = stoi(s);
		for (numComps = 0; k--; ++numComps) {
			cin >> s;
			for (char c : s)
				pos[c - '0'] = numComps;
		}
	}

	vector<int> getComp(set<int> s) {
		vector<int> res;
		for (int i = 0; i < 10; ++i) {
			for (int x : s)
				if (pos[x] == pos[i]) {
					res.push_back(i);
					break;
				}
		}
		return res;
	}

	bool same(int x, int y) {
		return pos[x] == pos[y];
	}

	~Interactor() {
		cout << "done" << endl;
	}
} inter;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int steps1 = 0;
	do {
		inter.play( { 0, 1 });
		inter.play( { 1 });
		++steps1;
	} while (!inter.same(0, 1));

	while (inter.numComps != 1)
		inter.play(inter.getComp( { 0, 1, 2, 3, 9 }));
	return 0;
}