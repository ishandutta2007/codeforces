#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;string s;
	cin >> n >> s;

	string t;
	for(char c : s)
		if(t.size()%2 == 0 || c != t.back())
			t += c;
	if(t.size()&1)
		t.pop_back();
	cout << s.size() - t.size() << endl << t;

	return 0;
}