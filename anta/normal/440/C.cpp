#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

long long N;
long long p10[20];
const int MaxK = 50;

int memo[20][3][MaxK+1][MaxK+1][MaxK*2+1];
int rec(int i, int j, int addk, int subk, int sum) {
	int &r = memo[i][j][addk][subk][sum+MaxK*2];
	if(r != -1) return r;
	if(i == 19) return r = 0;
	int d = N / p10[i] % 10;
	r = 99999999;
	if(j == 2) {
		int mod10 = (sum % 10 + 10) % 10;
		if(mod10 == d) {
			int carry_borrow = (sum - mod10) / 10;
			r = min(r, rec(i+1, 0, addk, subk, carry_borrow));
		}
	}else if(j == 0) {
		for(int a = 0; a <= addk; a ++) {
			r = min(r, a + rec(i, 1, a, subk, sum + a));
		}
	}else if(j == 1) {
		for(int b = 0; b <= subk; b ++) {
			r = min(r, b + rec(i, 2, addk, b, sum - b));
		}
	}
	return r;
}

int main() {
	while(cin >> N) {
	p10[0] = 1;
	for(int i = 1; i < 20; i ++) p10[i] = p10[i-1] * 10;
	memset(memo, -1, sizeof memo);
	int r = 99999999;
	for(int a = 0; a <= MaxK; a ++) for(int b = 0; b <= MaxK; b ++) {
		int t = rec(0, 0, a, b, 0);
		if(t < r)
			r = t;
	}
	cout << r << endl;
	}
	return 0;
}