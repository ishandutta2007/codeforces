#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define In insert
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7, maxn = 1e5 + 100;
int b[maxn], a[maxn];
vector <int> litl, litr, bigl, bigr;

int main(){
	int n;
	string st, s;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> st;
	s = '0' + st;
	for (int i = 5; i <= n; i++){
		if (s[i] == '1'){
			if (s[i - 1] == '0' and s[i - 2] == '0' and s[i - 3] == '0' and s[i - 4] == '0'){
				int mxx = -1000 * 1000 * 1000;
				for (int j = i; j >= i - 4; j--)
					mxx = max (mxx, a[j]);
				litl.PB(mxx);
			}
//			else if (s[i - 1] == '1' and s[i - 2] == '1' and s[i - 3] == '1' and s[i - 4] == '1')
//				litr.PB(min (a[i], (min (a[i - 1], a[i - 2]), min(a[i - 3], a[i - 4]))));
		}
		else {
			if (s[i - 1] == '1' and s[i - 2] == '1' and s[i - 3] == '1' and s[i - 4] == '1'){
				int mnn = 1000 * 1000 * 1000;
				for (int j = i; j >= i - 4; j--)
					mnn = min (mnn, a[j]);
				bigr.PB(mnn);
			}

//			else if (s[i - 1] == '0' and s[i - 2] == '0' and s[i - 3] == '0' and s[i - 4] == '0')
//				bigl.PB(max (a[i], (max (a[i - 1], a[i - 2]), max (a[i - 3], a[i - 4]))));
		}
	}
	sort (litl.begin(), litl.end());
	if (litl.empty())
		cout << -1000 * 1000 * 1000 << " ";
	else
		cout << litl.back() + 1 << " ";
	sort (bigr.begin(), bigr.end());
	if (bigr.empty())
		cout << 1000 * 1000 * 1000 << " ";
	else
		cout << bigr[0] - 1 << endl;
}