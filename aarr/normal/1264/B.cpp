#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5;

int p[N];
int main() {
	int a, b, c, d;
	int a2, b2, c2, d2;
	bool m;
	cin >> a >> b >> c >> d;
	int n = a + b + c + d;
/*	if (a > b) {
		if (a - b == 1 && c == 0 && d == 0) {
			cout << "YES" << endl;
			for (int i = 1; i <= n; i++) {
				if (i % 2) {
					cout << 0 << " ";
				}
				else {
					cout << 1 << " ";
				}
			}
		}
		else {
			cout << "NO" << endl;
		}
		return 0;
	}
	if (d > c) {
		if (d - c == 1 && a == 0 && b == 0) {
			cout << "YES" << endl;
			for (int i = 1; i <= n; i++) {
				if (i % 2) {
					cout << 3 << " ";
				}
				else {
					cout << 2 << " ";
				}
			}
		}
		else {
			cout << "NO" << endl;
		}
		return 0;
	}*/
	if (a > 0) {
		
		p[1] = 0;
		int a2 = a - 1, b2 = b, c2 = c, d2 = d;
		bool m = true;
		for (int i = 2; i <= n; i++) {
			if (p[i - 1] == 1) {
				if (a2 > 0) {
					p[i] = 0;
					a2--;
				}
				else {
					if (c2 > 0) {
						p[i] = 2;
						c2--;
					}
					else {
						m = false;
						break;
					}
				}
			}
			if (p[i - 1] == 2) {
				if (d2 > 0) {
					p[i] = 3;
					d2--;
				}
				else {
					if (b2 > 0) {
						p[i] = 1;
						b2--;
					}
					else {
						m = false;
						break;
					}
				}
			}
			if (p[i - 1] == 0) {
				if (b2 > 0) {
					p[i] = 1;
					b2--;
				}
				else {
					m = false;
					break;
				}
			}
			if (p[i - 1] == 3) {
				if (c2 > 0) {
					p[i] = 2;
					c2--;
				}
				else {
					m = false;
					break;
				}
			}		
		}
		if (m) {
			cout << "YES" << endl;
			for (int i = 1; i <= n; i++) {
				cout << p[i] << " ";
			}
			return 0;
		}
	}
	if (b > 0) {
		p[1] = 1;
		a2 = a, b2 = b - 1, c2 = c, d2 = d;
		m = true;
		for (int i = 2; i <= n; i++) {
			if (p[i - 1] == 1) {
				if (a2 > 0) {
					p[i] = 0;
					a2--;
				}
				else {
					if (c2 > 0) {
						p[i] = 2;
						c2--;
					}
					else {
						m = false;
						break;
					}
				}
			}
			if (p[i - 1] == 2) {
				if (d2 > 0) {
					p[i] = 3;
					d2--;
				}
				else {
					if (b2 > 0) {
						p[i] = 1;
						b2--;
					}
					else {
						m = false;
						break;
					}
				}
			}
			if (p[i - 1] == 0) {
				if (b2 > 0) {
					p[i] = 1;
					b2--;
				}
				else {
					m = false;
					break;
				}
			}
			if (p[i - 1] == 3) {
				if (c2 > 0) {
					p[i] = 2;
					c2--;
				}
				else {
					m = false;
					break;
				}
			}		
		}
		if (m) {
			cout << "YES" << endl;
			for (int i = 1; i <= n; i++) {
				cout << p[i] << " ";
			}
			return 0;
		}
	}
	if (c > 0) {
		p[1] = 2;
		a2 = a, b2 = b, c2 = c - 1, d2 = d;
		m = true;
		for (int i = 2; i <= n; i++) {
			if (p[i - 1] == 1) {
				if (a2 > 0) {
					p[i] = 0;
					a2--;
				}
				else {
					if (c2 > 0) {
						p[i] = 2;
						c2--;
					}
					else {
						m = false;
						break;
					}
				}
			}
			if (p[i - 1] == 2) {
				if (d2 > 0) {
					p[i] = 3;
					d2--;
				}
				else {
					if (b2 > 0) {
						p[i] = 1;
						b2--;
					}
					else {
						m = false;
						break;
					}
				}
			}
			if (p[i - 1] == 0) {
				if (b2 > 0) {
					p[i] = 1;
					b2--;
				}
				else {
					m = false;
					break;
				}
			}
			if (p[i - 1] == 3) {
				if (c2 > 0) {
					p[i] = 2;
					c2--;
				}
				else {
					m = false;
					break;
				}
			}		
		}
		if (m) {
			cout << "YES" << endl;
			for (int i = 1; i <= n; i++) {
				cout << p[i] << " ";
			}
			return 0;
		}
	}
	if (d > 0) {
		p[1] = 3;
		a2 = a, b2 = b, c2 = c, d2 = d - 1;
		m = true;
		for (int i = 2; i <= n; i++) {
			if (p[i - 1] == 1) {
				if (a2 > 0) {
					p[i] = 0;
					a2--;
				}
				else {
					if (c2 > 0) {
						p[i] = 2;
						c2--;
					}
					else {
						m = false;
						break;
					}
				}
			}
			if (p[i - 1] == 2) {
				if (d2 > 0) {
					p[i] = 3;
					d2--;
				}
				else {
					if (b2 > 0) {
						p[i] = 1;
						b2--;
					}
					else {
						m = false;
						break;
					}
				}
			}
			if (p[i - 1] == 0) {
				if (b2 > 0) {
					p[i] = 1;
					b2--;
				}
				else {
					m = false;
					break;
				}
			}
			if (p[i - 1] == 3) {
				if (c2 > 0) {
					p[i] = 2;
					c2--;
				}
				else {
					m = false;
					break;
				}
			}		
		}
		if (m) {
			cout << "YES" << endl;
			for (int i = 1; i <= n; i++) {
				cout << p[i] << " ";
			}
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}