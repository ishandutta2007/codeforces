#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int dp[20010][3][2];
int n;
int can(int a, int b) {
	int c = b - a;
	int x = 1;
	if(a < c) swap(a, c);
	while(2*x-1 <= a && 2*x-1 <= c) {
		x *= 2;
	}
	if(2*x-1 >= a) {
		return 1;
	}
	return false;
}
int rec(int sz, int c, int v) {
	if(sz == 1) {
		return c == v;
	}
	if(sz == 2) {
		return c != v;
	}
	if(sz == 3) {
		return 0;
	}
	int &res = dp[sz][c][v];
	if(res != -1) return res;
	res = 0;
	for(int i = 1; i + 1< sz; i++) {
		if(can(i, sz-1) && (i + c) % 2 == v) {
			res += rec(i, c, 1-v) * rec(sz-i-1, 1-v, v); 
		}
	}
	return res;
}
int main () {
	memset(dp, -1, sizeof dp);
	cin >> n; 
	vector< pair< int, pii > > D;

	set< pair< int, pii > > S;
	for(int i =1; i <= 2000; i++) {
		if(rec(i, 1, 0) == 1) {
			D.push_back(make_pair(i, make_pair(1, 0)));
		}
		if(rec(i, 1, 1) == 1) {
			D.push_back(make_pair(i, make_pair(1, 1)));
		}
		if(rec(i, 0, 0) == 1) {
			D.push_back(make_pair(i, make_pair(0, 0)));
		}
		if(rec(i, 0, 1) == 1) {
			D.push_back(make_pair(i, make_pair(0, 1)));
		}
	}
	for(int i = 0; i < D.size(); i++) {
		S.insert(D[i]);
	}
	//cout << S.size() << "\n";
	for(int it = 0; it < 100; it++){
		int F = 0;
		for(int i = 0; F == 0 && i < D.size(); i++) {
			for(int j = 0; F == 0 && j < D.size(); j++) {
				int A = D[i].f + D[j].f + 1;
				if(A > n) continue;
				int c = D[i].s.f;
				int v = 1-D[i].s.s;
				
				if(D[j].s.s != v) continue;
				
				if((D[i].f + c) % 2 != v) continue;
				int cc = 1-v;
				if(D[j].s.f != cc) continue;
				
				if(S.count(make_pair(A, make_pair(c, v)))) continue;
				if(can(D[i].f, A-1)) {
					S.insert(make_pair(A, make_pair(c, v)));
					D.push_back(make_pair(A, make_pair(c, v)));
					F = 1;
				}
			}
		}
	}
	//cout << S.size() << "\n";
	//cout << (--S.end())->f << "\n";
	cout << S.count(make_pair(n, make_pair(1, n % 2))) << "\n";

 	return 0;
}