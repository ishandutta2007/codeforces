#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 5;


int a[N];
int c[N];
multiset <int> s;



int main() {
	ios :: sync_with_stdio(false);
	int n, q;
	cin >> n;
	for (int i = 1; i < N * 2; i++) {
		s.insert(0);
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s.erase(s.find(c[a[i]]));
		c[a[i]]++;
		s.insert(c[a[i]]);
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		char qt;
		int x;
		cin >> qt >> x;
		if (qt == '+') {
			s.erase(s.find(c[x]));
			c[x]++;
			s.insert(c[x]);			
		}
		else {
			s.erase(s.find(c[x]));
			c[x]--;
			s.insert(c[x]);					
		}
		set <int> :: iterator it = s.end();
		it--;
		int a = *it, b, c;
		it--;
		b = *it;
		it--;
		c = *it;
	//	cout << "73 " << a << " " << b << " " << c << endl;
		if (a >= 8 || a >= 6 && b >= 2 || a >= 4 && b >= 2 && c >= 2 || a >= 4 && b >= 4) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}