#include <bits/stdc++.h>

using namespace std;

int n, sz;
vector<char> s;
string mem[100000];
vector<int> st(2000000, -1);

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		string b;
		int k;
		cin >> b >> k;
		mem[i] = b;
		for(int j = 0; j < k; j++) {
			int p;
			cin >> p;
			--p;
			if(p + b.size() > sz)
				sz = p + b.size();
			if(st[p] == -1 || b.size() > mem[st[p]].size())
				st[p] = i;
		}
	}
	int x = -1, y;
	for(int i = 0; i < sz; i++) {
		if(st[i] != -1 && (x == -1 || i - y + mem[x].size() - 1 < i + mem[st[i]].size() - 1)) {
			x = st[i]; y = 0;
		}
		if(x == -1) cout << 'a';
		else {
			cout << mem[x][y], ++y;
			if(y == mem[x].size())
				x = -1;
		}
	}
}