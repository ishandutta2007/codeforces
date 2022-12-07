//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

void setIO(string name) {
	//~ ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
}

const int N = 5e5 + 7;
int n, k[2], c;
char s[N];

long long wylicz(vector <int> v, int uj, int ed1, int ed2, bool p) {
	long long odp = 0, akt = 0;
	int tz = 0;
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	if (ed1 > ed2) {
		swap(ed1, ed2);
	}
	while (!v.empty()) {
		if (v.back() == 1) {
			++tz;
			v.pop_back();
		}
		else {
			break;
		}
	}
	while (true) {
		if (p) { // delete 1
			if (!uj) {
				break;
			}
			akt += k[1];
			--uj;
		}
		else { // delete 0
			if (!v.empty()) {
				if (uj || k[1] <= c) {
					int x = v.back();
					v.pop_back();
					akt += k[0];
					--x;
					if (x == 1) {
						++tz;
					}
					else {
						v.push_back(x);
					}
				}
				else {
					if (tz) {
						--tz;
						akt -= c;
						++uj;
					}
					else {
						int x = v.back();
						v.pop_back();
						akt += k[0];
						--x;
						if (x == 1) {
							++tz;
						}
						else {
							v.push_back(x);
						}
					}
				}
			}
			else {
				if (k[1] >= c) {
					if (uj) {
						if (ed1 > 1) {
							--ed1;
							akt += k[0];
						}
						else if (ed2 > 1) {
							--ed2;
							akt += k[0];
						}
						else if (tz) {
							--tz;
							akt -= c;
							++uj;
						}
						else if (ed1 == 1) {
							--ed1;
							akt -= c;
						}
						else if (ed2 == 1) {
							--ed2;
							akt -= c;
						}
						else {
							break;
						}
					}
					else {
						if (tz) {
							--tz;
							akt -= c;
							++uj;
						}
						else if (ed1 > 1) {
							--ed1;
							akt += k[0];
						}
						else if (ed2 > 1) {
							--ed2;
							akt += k[0];
						}
						else {
							break;
						}
					}
				}
				else {
					if (ed1 > 1) {
						--ed1;
						akt += k[0];
					}
					else if (ed2 > 1) {
						--ed2;
						akt += k[0];
					}
					else {
						break;
					}
				}
			}
		}
		odp = max(odp, akt);
		p ^= 1;
	}
	//~ printf("%lld\n", odp);
	return odp;
}

void solve() {
	scanf("%d%d%d%d", &n, &k[0], &k[1], &c);
	scanf("%s", s + 1);
	if (n == 1) {
		printf("0\n");
		return;
	}
	int lf = 1;
	while (lf <= n && s[lf] == '0') {
		++lf;
	}
	if (lf == n + 1) {
		printf("%d\n", k[0]);
		return;
	}
	int rg = n;
	while (s[rg] == '0') {
		--rg;
	}
	int ed1 = max(0, lf - 1), ed2 = max(0, n - rg);
	vector <int> v;
	int licz = 1, uj = 0;
	s[n + 1] = '2';
	for (int i = lf; i <= rg; ++i) {
		if (s[i] != s[i + 1]) {
			if (s[i] == '0') {
				v.push_back(licz);
			}
			else {
				uj += licz - 1;
			}
			licz = 0;
		}
		++licz;
	}
	printf("%lld\n", max(wylicz(v, uj, ed1, ed2, 0), wylicz(v, uj, ed1, ed2, 1)));
}

int main() {
	int q=1;
	scanf("%d", &q);
	while(q--) {
		solve();
	}
	return 0;
}