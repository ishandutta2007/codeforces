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
int g[6][6][4] = 
{ { {1,3,6,8}, {2,4,22,24}, {5,7,10,12}, {9,11,21,23}, {13,14,15,16}, {17,18,19,20} } , 
  { {2,4,5,7}, {6,8,9,11}, {10,12,24,22}, {21,23,1,3} ,{ 13,14,15,16 },{ 17,18,19,20 } } ,
  { {5,6,7,8}, {21,22,23,24}, {1,2,17,19}, {18,20,9,10}, {11,12,14,16}, {13,15,3,4} } ,
  { { 5,6,7,8 },{ 21,22,23,24 },{1,2,14,16}, {13,15,9,10}, {11,12,17,19}, {18,20,3,4 } } ,
  { {1,2,3,4}, {9,10,11,12}, {13,14,7,8}, {5,6,19,20}, {18,17,23,24}, {21,22,15,16} } ,
  { { 1,2,3,4 },{ 9,10,11,12 },{13,14,23,24}, {21,22,19,20}, {17,18,7,8}, {5,6,15,16} } };
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<int> A(24);
	int res = 0;
	for (int i = 0; i < 24; i++) {
		cin >> A[i];
	}
	bool f = false;
	bool f2;
	int t;
	for (int i = 0; i < 6; i++) {
		f2 = true;
		for (int j = 0; j < 6; j++) {
			t = A[g[i][j][0]-1];
			for (int k = 0; k < 4; k++) {
				if (A[g[i][j][k]-1] != t) {
					f2 = false;
					break;
				}
			}
		}
		if (f2) {
			f = true;
			break;
		}
	}
	if (f) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}