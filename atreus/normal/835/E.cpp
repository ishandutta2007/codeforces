#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 3e4 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
int A[20], B[20], ans[20];

int main(){
	ios_base::sync_with_stdio(false);
	int n, x, y;
	cin >> n >> x >> y;
	for (int i = 0; i <= 9; i++){
		cout << "? ";
		int cnt = 0;
		for (int j = 0; j < n; j++)
			if (((j >> i) & 1) == 0)
				cnt ++;
		cout << cnt << " ";
		for (int j = 0; j < n; j++)
			if (((j >> i) & 1) == 0)
				cout << j + 1 << " ";
		cout << endl;
		int xo;
		cin >> xo;
		ans[i] = (xo == y or xo == (y ^ x));
	}
	int mybit = -1;
	for (int i = 0; i <= 9; i++)
		if (ans[i] == 1)
			mybit = i;
	A[mybit] = 1;
	for (int i = 0; i <= 9; i++){
		if (i == mybit)
			continue;
		cout << "? ";
		int cnt = 0;
		for (int j = 0; j < n; j++)
			if (((j >> i) & 1) == 0 and ((j >> mybit) & 1) == 0)
				cnt ++;
		cout << cnt << " ";
		for (int j = 0; j < n; j++)
			if (((j >> i) & 1) == 0 and ((j >> mybit) & 1) == 0)
				cout << j + 1 << " ";
		cout << endl;
		int xo;
		cin >> xo;
		bool tmp = (xo == y or xo == (y ^ x));
		if (ans[i] == 1){
			if (tmp == 1)
				A[i] = 1;
			else
				B[i] = 1;
		}
		else {
			if (tmp == 1){
				A[i] = 1;
				B[i] = 1;
			}
		}
	}
	ll idx1 = 1024, idx2 = 1024, tmp = 1;
	for (int i = 0; i <= 9; i++){
		idx1 -= A[i] * tmp;
		idx2 -= B[i] * tmp;
		tmp *= 2;
	}
	if (idx1 > idx2)
		swap (idx1, idx2);
	cout << "! " << idx1 << " " << idx2 << endl;
}