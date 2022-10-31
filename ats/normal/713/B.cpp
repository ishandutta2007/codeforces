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
struct Rect {
	int x1, y1, x2, y2;
};
int ask(Rect &r) {

	if (r.x1 > r.x2 || r.y1 > r.y2)return 0;

	cout << "? " << r.x1 << " " << r.y1 << " " << r.x2 << " " << r.y2 << endl;
	cout << flush;
	int a;
	cin >> a;
	return a;
}
signed main() {
	int N;
	cin >> N;
	Rect whole;
	whole.x1 = 1;
	whole.y1 = 1;
	whole.x2 = N;
	whole.y2 = N;

	int L[2];
	int R[2];
	int U[2];
	int D[2];


	Rect r = whole;

	for (int i = 0; i < 2; i++) {
		int a = N;
		int b = 0;
		while (a - b > 1) {
			int m = (a + b) / 2;
			r.x2 = m;
			int t = ask(r);
			if (t >= 2 - i) {
				a = m;
			}
			else {
				b = m;
			}
		}
		R[i] = a;
	}

	r = whole;

	for (int i = 0; i < 2; i++) {
		int a = N;
		int b = 0;
		while (a - b > 1) {
			int m = (a + b) / 2;
			r.y2 = m;
			int t = ask(r);
			if (t >= 2 - i) {
				a = m;
			}
			else {
				b = m;
			}
		}
		D[i] = a;
	}

	r = whole;

	for (int i = 0; i < 2; i++) {
		int a = 1;
		int b = N + 1;
		while (b - a > 1) {
			int m = (a + b) / 2;
			r.x1 = m;
			int t = ask(r);
			if (t >= 2 - i) {
				a = m;
			}
			else {
				b = m;
			}
		}
		L[i] = a;
	}

	r = whole;

	for (int i = 0; i < 2; i++) {
		int a = 1;
		int b = N + 1;
		while (b - a > 1) {
			int m = (a + b) / 2;
			r.y1 = m;
			int t = ask(r);
			if (t >= 2 - i) {
				a = m;
			}
			else {
				b = m;
			}
		}
		U[i] = a;
	}

	Rect ri;

	ri.x1 = 0;
	ri.x2 = 0;
	ri.y1 = 0;
	ri.y2 = 0;


	r.x1 = L[0];
	r.x2 = R[0];
	r.y1 = U[0];
	r.y2 = D[0];

	{
		r.x1 = L[1];
		int t = ask(r);
		if (t != 0) {
			ri.x1 = 1;
		}
		else {
			r.x1 = L[0];
		}
	}
	{
		r.x2 = R[1];
		int t = ask(r);
		if (t != 0) {
			ri.x2 = 1;
		}
		else {
			r.x2 = R[0];
		}
	}

	{
		r.y1 = U[1];
		int t = ask(r);
		if (t != 0) {
			ri.y1 = 1;
		}
		else {
			r.y1 = U[0];
		}
	}
	{
		r.y2 = D[1];
		int t = ask(r);
		if (t != 0) {
			ri.y2 = 1;
		}
		else {
			r.y2 = D[0];
		}
	}
	cout << "! " << r.x1 << " " << r.y1 << " " << r.x2 << " " << r.y2 << " ";
	r.x1 = L[1 - ri.x1];
	r.x2 = R[1 - ri.x2];
	r.y1 = U[1 - ri.y1];
	r.y2 = D[1 - ri.y2];
	cout << r.x1 << " " << r.y1 << " " << r.x2 << " " << r.y2 << endl;
	cout << flush;

}