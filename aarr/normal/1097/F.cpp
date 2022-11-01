#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int N = 100 * 1000 + 5, M = 7005;

bitset <M> b[N], c[M];
bitset <M> e;
vector <int> vec[M], d[M];
bool mark[M];
string s;

int main() {
	ios :: sync_with_stdio(false);
	for (int i = 1; i < M; i++) {
		for (int j = i; j < M; j += i) {
			d[j].push_back(i);
			if (i != 1 && (j / i) % i == 0) {
				mark[j] = true;
			}
		}
	}
	for (int i = 1; i < M; i++) {
		for (auto x : d[i]) {
			if (!mark[i / x]) {
			//	cout << "72 " << x << " " << i << endl;
				vec[x].push_back(i);
				c[x][i] = true;
			}
		}
	}
//	cout << "75 " << vec[1].size() << endl; 
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		int qt, x, y, z, v;
		cin >> qt >> x;
		if (qt == 1) {
			cin >> v;
			b[x] = 0;
			for (auto k : d[v]) {
				b[x][k] = true;
			}
		}
		if (qt == 2) {
			cin >> y >> z;
			
			e = b[y] ^ b[z];
			b[x] = e;
		}
		if (qt == 3) {
			cin >> y >> z;
			
			e = b[y] & b[z];
			b[x] = e;	
		}
		if (qt == 4) {
			int v, ans = 0;
			cin >> v;
			e = c[v] & b[x];
			ans = e.count() % 2;
			s += '0' + ans;
		}
	}
	cout << s;
	return 0;
}