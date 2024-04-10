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
	char a;
	cin >> a;

	int p = 1;
	int n = 0;
	int X;
	vector<char> v;
	v.push_back('+');
	while(true){
		cin >> a;
		if (a == '+') {
			p++;
			v.push_back(a);
		}
		else if(a == '-'){
			n++;
			v.push_back(a);
		}
		else {
			cin >> X;
			break;
		}
		cin >> a;
	}
	int mn = 0;
	int mx = 0;



	for (int i = 0; i < p; i++) {
		mn += 1;
		mx += X;
	}

	for (int i = 0; i < n; i++) {
		mn -= X;
		mx -= 1;
	}
	if (mn <= X && X <= mx) {
		cout << "Possible" << endl;
		int r = X + n;
		int ad = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == '+') {
				p--;
				int t = min(X, r - p);
				if (t < 1) {
					ad += 1 - t;
					r += 1 - t;
					t = 1;
				}
				r -= t;
				if (i > 0) {
					cout << " + ";
				}
				cout << t;
			}
			else {
				int t = min(X, ad + 1);
				ad -= t - 1;
				cout << " - " << t;
			}
		}
		cout << " = " << X << endl;
	}
	else {
		cout << "Impossible" << endl;
	}

}