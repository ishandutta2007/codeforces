#include <iostream>
using namespace std;

const int N = 200 * 1000 + 5, LG = 30;
int cnt = 1;


int nxt[N * LG][2];
int sm[N * LG];

int get(int x, int y) {
	return x >> y & 1;
}

void add(int x, int c) {
	int v = 1;
	for (int i = LG; i >= 0; i--) {
		sm[v] += c;
		int b = get(x, i);
		if (!nxt[v][b]) {
			cnt++;
			nxt[v][b] = cnt;
		}
		v = nxt[v][b];
	}
	sm[v] += c;
}
int get(int x) {
	int ans = 0, v = 1;
	for (int i = LG; i >= 0; i--) {
		int b = !get(x, i);
		ans += 1 << i;
		if (!nxt[v][b]) {
			cnt++;
			nxt[v][b] = cnt;
		}
		if (!sm[nxt[v][b]]) {
			ans -= 1 << i;
			b ^= 1;
		}
		v = nxt[v][b];
	}
	return ans;
}
int main() {
	int q;
	cin >> q;
	add(0, 1);
	for (int i = 0; i < q; i++) {
		char qt;
		cin >> qt;
		int x;
		cin >> x;
		if (qt == '+') {
			add(x, 1);
		}
		if (qt == '-') {
			add(x, -1);
		}
		if (qt == '?') {
			cout << get(x) << endl;
		}
	//	cout << "73 " << sm[1] << endl;
	}
	return 0;
}