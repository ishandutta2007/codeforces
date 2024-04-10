#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <deque>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e3 + 5;
const int Maxn = 100 + 5;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;

ll n, m, a[maxn], ans = -1;

vector <int> Atc, Def;

bool mark[maxn];

void solve () {
	int idx = 0;
	for (int i = 1; i <= m and idx < Def.size(); i++) {
		if (a[i] > Def[idx]) {
			mark[i] = 1;
			idx ++;
		}
	}
	
	if (idx != Def.size())
		return;

	ll sum = 0;
	idx = 0;
	for (int i = 1; i <= m; i++) {
		if (!mark[i]) {
			sum += a[i];
			if (idx < Atc.size() and a[i] >= Atc[idx]) {
				sum -= Atc[idx];
				idx ++;
			}
		}
	}

	if (idx == (int)Atc.size())
		ans = sum;
}

void Solve () {
	ll sum = 0;
	memset (mark, 0, sizeof mark);

	for (int i = m; i >= 1; i--) {
		bool cur = 1;
		for (int j = 0; cur and j < Atc.size(); j++) {
			if (!mark[j] and a[i] >= Atc[j]) {
				mark[j] = 1;
				sum += a[i] - Atc[j];
				cur = 0;
			}
		}
	}

	ans = max (ans, sum);
}

int main () {
	ios_base::sync_with_stdio (false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string S;
		int x;
		cin >> S >> x;
		if (S == "ATK")
			Atc.PB (x);
		else
			Def.PB (x);
	}
	
	sort (Atc.begin(), Atc.end());
	sort (Def.begin(), Def.end());

	for (int i = 1; i <= m; i++)
		cin >> a[i];
	sort (a + 1, a + m + 1);

	solve ();

	Solve ();

	cout << ans << endl;
}