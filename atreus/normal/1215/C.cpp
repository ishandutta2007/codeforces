#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

int a[maxn];

int main(){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	s = " " + s;
	t = " " + t;
	vector<pair<int,int> > ops;
	vector<int> ab, ba;
	for (int i = 1; i <= n; i++){
		if (s[i] == 'a' and t[i] == 'b')
			ab.push_back(i);
		if (s[i] == 'b' and t[i] == 'a')
			ba.push_back(i);
	}
	while (ab.size() >= 2){
		int fi = ab.back();
		ab.pop_back();
		int se = ab.back();
		ab.pop_back();
		ops.push_back({fi, se});
	}
	while (ba.size() >= 2){
		int fi = ba.back();
		ba.pop_back();
		int se = ba.back();
		ba.pop_back();
		ops.push_back({fi, se});
	}
	if (((int)ab.size() ^ (int)ba.size()) == 1)
		return cout << -1 << endl, 0;
	if (ab.size() == 1){
		int fi = ab[0];
		int se = ba[0];
		ops.push_back({fi, fi});
		ops.push_back({fi, se});
	}
	cout << ops.size() << endl;
	for (auto it : ops)
		cout << it.first << " " << it.second << endl;
}