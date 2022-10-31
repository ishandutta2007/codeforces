#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	string S;
	cin >> S;
	
	int c = 0;
	int mn = 0;
	int mnp = 0;
	for (int i = 0; i < N; i++) {
		if (mn > c) {
			mn = c;
			mnp = i;
		}
		if (S[i] == '(') {
			c++;
		}
		else {
			c--;
		}
	}
	if (c != 0) {
		cout << 0 << endl;
		cout << "1 1" << endl;
		return 0;
	}
	{
		string T;
		for (int i = 0; i < N; i++) {
			T.push_back(S[(mnp + i) % N]);
		}
		S = T;
	}
	cerr << S << endl;

	c = 0;
	int mx = 0;
	int mxa = 0;
	int mxb = 0;
	int a, b;
	int cnt = 0;
	int res = 0; 
	for (int i = 0; i < N; i++) {
		if (S[i] == '(') {
			c++;
		}
		else {
			c--;

		}
		if (c == 0) {
			res++;
		}
	}
	mx = res;
	for (int i = 0; i < N; i++) {
		if (c == 0) {
			a = i;
		}
		if (S[i] == '(') {
			c++;
		}
		else {
			c--;
			if (c == 1) {
				cnt++;
			}
		}
		if (c == 0) {
			if (mx < cnt + 1) {
				mx = cnt + 1;
				mxa = a;
				mxb = i;
			}
			cnt = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		
		if (S[i] == '(') {
			if (c == 1) {
				a = i;
			}
			c++;
		}
		else {
			c--;
			if (c == 2) {
				cnt++;
			}
			if (c == 1) {
				if (mx < res + cnt + 1) {
					mx = res + cnt + 1;
					mxa = a;
					mxb = i;
				}
				cnt = 0;
			}
		}
		
	}
	mxa = (mxa + mnp + N) % N;
	mxb = (mxb + mnp + N) % N;
	cout << mx << endl;
	cout << mxa + 1 << " " << mxb + 1 << endl;
}