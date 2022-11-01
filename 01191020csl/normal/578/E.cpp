#include<bits/stdc++.h>
using namespace std;
void write(int num) {
	if (num >= 10) write(num / 10);
	putchar(num % 10 + '0');
}
string s;
vector<int> l, r;
int id[100001];
vector<int> v[100001];
vector<int> ll, lr, rl, rr;
int main() {
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
		switch(s[i]) {
			case 'L': {
				if (r.size()) id[i] = *(id+*(r.end()-1)), r.pop_back();
				else id[i] = ++cnt;
				l.push_back(i);
				break;
			}
			case 'R': {
				if (l.size()) id[i] = *(id+*(l.end()-1)), l.pop_back();
				else id[i] = ++cnt;
				r.push_back(i);
				break;
			}
		}
	for (int i = 0; i < s.size(); i++) v[id[i]].push_back(i);
	for (int i = 1; i <= cnt; i++) {
		if (s[v[i][0]] == 'L' && s[*(v[i].end()-1)] == 'L') ll.push_back(i);
		if (s[v[i][0]] == 'L' && s[*(v[i].end()-1)] == 'R') lr.push_back(i);
		if (s[v[i][0]] == 'R' && s[*(v[i].end()-1)] == 'L') rl.push_back(i);
		if (s[v[i][0]] == 'R' && s[*(v[i].end()-1)] == 'R') rr.push_back(i);
	}
	write(cnt-1), putchar('\n');
	while (ll.size() && rr.size()) {
		int x = *(ll.end()-1), y = *(rr.end()-1);
		for (int i = 0; i < v[y].size(); i++) v[x].push_back(v[y][i]);
		lr.push_back(x), ll.pop_back(), rr.pop_back();
	}
	while (ll.size() && lr.size()) {
		int x = *(lr.end()-1), y = *(ll.end()-1);
		for (int i = 0; i < v[y].size(); i++) v[x].push_back(v[y][i]);
		*(ll.end()-1) = x, lr.pop_back();
	}
	while (ll.size() && rl.size()) {
		int x = *(ll.end()-1), y = *(rl.end()-1);
		for (int i = 0; i < v[y].size(); i++) v[x].push_back(v[y][i]);
		rl.pop_back();
	}
	while (rr.size() && rl.size()) {
		int x = *(rl.end()-1), y = *(rr.end()-1);
		for (int i = 0; i < v[y].size(); i++) v[x].push_back(v[y][i]);
		*(rr.end()-1) = x, rl.pop_back();
	}
	while (rr.size() && lr.size()) {
		int x = *(rr.end()-1), y = *(lr.end()-1);
		for (int i = 0; i < v[y].size(); i++) v[x].push_back(v[y][i]);
		lr.pop_back();
	}
	if (ll.size() || rr.size()) {
		int x;
		if (ll.size()) x = ll[0];
		else x = rr[0];
		for (int i = 0; i < v[x].size(); i++) write(v[x][i]+1), putchar(' ');
		putchar('\n');
		return 0;
	}
	if (lr.size()) {
		int x = lr[0];
		while (lr.size() >= 2) {
			int y = *(lr.end()-1);
			for (int i = 0; i < v[y].size(); i++) v[x].push_back(v[y][i]);
			lr.pop_back();
		}
	}
	if (rl.size()) {
		int x = rl[0];
		while (rl.size() >= 2) {
			int y = *(rl.end()-1);
			for (int i = 0; i < v[y].size(); i++) v[x].push_back(v[y][i]);
			rl.pop_back();
		}
	}
	if (!(lr.size() && rl.size())) {
		int x;
		if (lr.size()) x = lr[0];
		else x = rl[0];
		for (int i = 0; i < v[x].size(); i++) write(v[x][i]+1), putchar(' ');
		putchar('\n');
		return 0;
	}
	int x = lr[0], y = rl[0];
	if (*(v[x].end()-1) > *(v[y].end()-1)) swap(x, y);
	v[x].push_back(*(v[y].end()-1)), v[y].pop_back();
	for (int i = 0; i < v[x].size(); i++) write(v[x][i]+1), putchar(' ');
	for (int i = 0; i < v[y].size(); i++) write(v[y][i]+1), putchar(' ');
	putchar('\n');
}