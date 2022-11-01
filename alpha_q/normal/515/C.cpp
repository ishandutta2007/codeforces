#include <bits/stdc++.h>

using namespace std;

struct dat {
	int p2, p3, p5, p7;
};

dat A[] = {{0,0,0,0}, {0,0,0,0}, {1,0,0,0}, {1,1,0,0}, {3,1,0,0}, {3,1,1,0}, {4,2,1,0}, {4,2,1,1}, {7,2,1,1}, {7,4,1,1}};

int main() {
	int n; string s; cin >> n >> s;
	int s2, s3, s5, s7; s2 = s3 = s5 = s7 = 0;
	
	for (int i = 0; i < n; i++) {
		int c = s[i] - '0';
		s2 += A[c].p2;
		s3 += A[c].p3;
		s5 += A[c].p5;
		s7 += A[c].p7;
	}
	
	string ret = "";
	while (s7--) s2 -= 4, s3 -= 2, s5--, ret += '7';
	while (s5--) s2 -= 3, s3--, ret += '5';
	while (s3--) s2--, ret += '3';
	while (s2--) ret += '2';
	
	cout << ret << endl;
	return 0;
}