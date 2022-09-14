#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <ctime>

#define ll long long
#define pii pair <int, int>
#define mp make_pair

using namespace std;

set <pair <int, pii> > s;

const int maxn = (int)1e5 + 10;

int x[maxn];

void change(int a, int y, int z) {
	if (a < 0) {
		cout << "GE" << endl;
		throw 1;
	}
	if (z - y != y - a) {
		cout << "HER" << endl;
		throw 1;
	}
	if (s.count(mp(a, mp(y, z)))) {
		s.erase(mp(a, mp(y, z)));
	}
	else {
		s.insert(mp(a, mp(y, z)));
	}

	x[a] ^= 1;
	x[y] ^= 1;
	x[z] ^= 1;
}

int sn;

void write() {
	for (int i = 0; i < sn; i++) {
		if (x[i] != 0) {
			cout << "G" << endl;
			throw 1;
		}
	}

	cout << "YES" << endl;

	cout << s.size() << endl;

	for (auto it = s.begin(); it != s.end(); it++) {
		printf("%d %d %d\n", (it->first) + 1, (it->second.first) + 1, (it->second.second) + 1);
	}
}

int main() {
	int n;

	cin >> n;

	sn = n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		//x[i] = rand() % 2;
	}

	while (n >= 9) {
		if (x[n - 1] == 0) {
			n--;
			continue;
		}

		if (x[n - 3] == 1 && x[n - 2] == 1) {
			change(n - 3, n - 2, n - 1);
			n -= 3;
		}
		else if (x[n - 3] == 1) {
			change(n - 5, n - 3, n - 1);
			n -= 3;
		}
		else {
			int sm = 0;
			int ps = -1;

			for (int i = 2; i <= 3; i++) {
				if (x[n - i] == 1) {
					sm++;
					ps = n - i;
				}
			}

			if (sm == 0) {
				change(n - 7, n - 4, n - 1);
				n -= 3;
			}
			else {
				if (n <= 11) {
					change(n - 3, n - 2, n - 1);
					n -= 2;
				}
				else {
					if (x[n - 6] == 0 && x[n - 5] == 0 && x[n - 4] == 0) {
						change(n - 3, n - 2, n - 1);
						change(n - 3, n - 7, n - 11);
						n -= 6;
					}
					else if (x[n - 6] == 1 && x[n - 5] == 1 && x[n - 4] == 1) {
						change(n - 6, n - 4, n - 2);
						change(n - 9, n - 5, n - 1);
						n -= 6;
					}
					else {
						sm = 0;
						ps = -1;

						for (int i = 4; i <= 6; i++) {
							if (x[n - i] == 1) {
								sm++;
								ps = n - i;
							}
						}

						if (sm == 1) {
							if (ps != n - 4) {
								change(n - 3, n - 2, n - 1);
								change(ps - (n - 3 - ps), ps, n - 3);
								n -= 6;
							}
							else {
								change(n - 6, n - 4, n - 2);
								change(n - 11, n - 6, n - 1);
								n -= 6;
							}
						}
						else {
							bool fl = true;

							for (int i = 4; i <= 6; i++) {
								if (x[n - i] == 1) {
									ps = n - i;
									if (fl) {
										fl = false;
										change(ps - (n - 1 - ps), ps, n - 1);
									}
									else {
										change(ps - (n - 2 - ps), ps, n - 2);
									}
								}
							}

							n -= 6;
						}
					}
				}
			}
		}
	}

	for (int i = n; i < sn; i++) {
		if (x[i] == 1) {
			cout << "BAD" << endl;
			throw 1;
		}
	}

	if (n < 8) {
		n = max(n, min(sn, 8));
	}

	for (int i = n - 1; i >= 2; i--) {
		if (x[i] == 1) {
			change(i - 2, i - 1, i);
		}
	}

	if (x[0] == 0 && x[1] == 0) {
		write();
	}
	else if ((x[0] == 1 && n < 7) || (x[1] == 1 && n < 8)) {
		cout << "NO" << endl;
	}
	else {
		if (x[0] == 1) {
			change(0, 1, 2);
			change(0, 2, 4);
			change(2, 3, 4);
			change(1, 3, 5);
			change(3, 4, 5);
			change(0, 3, 6);
			change(2, 4, 6);
		}

		if (x[1] == 1) {
			change(1, 2, 3);
			change(1, 3, 5);
			change(3, 4, 5);
			change(2, 4, 6);
			change(4, 5, 6);
			change(1, 4, 7);
			change(3, 5, 7);
		}

		write();
	}

	//system("pause");
}