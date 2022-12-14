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
const int maxn = 1e5 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
string s[maxn];
int seg[4 * maxn][35];
bool lazy[4 * maxn][35];

void fixlazy (int id, int L, int R, int l, int r, int bit){
	lazy[id][bit] = 0;
	lazy[2 * id + 0][bit] ^= 1;
	lazy[2 * id + 1][bit] ^= 1;
	int mid = (L + R) / 2;
	seg[2 * id + 0][bit] = mid - L - seg[2 * id + 0][bit];
	seg[2 * id + 1][bit] = R - mid - seg[2 * id + 1][bit];
	return;
}

ll get (int id, int L, int R, int l, int r, int bit){
	if (L == l and R == r)
		return seg[id][bit];
	if (lazy[id][bit] == 1)
		fixlazy (id, L, R, l, r, bit);
	int mid = (L + R) / 2, ret = 0;
	if (mid > l)
		ret += get (2 * id + 0, L, mid, l, min (mid, r), bit);
	if (mid < r)
		ret += get (2 * id + 1, mid, R, max (l, mid), r, bit);
	return ret;
}

void modifiyer (int id, int L, int R, int l, int r, int bit){
	if (L == l and R == r){
		seg[id][bit] = R - L - seg[id][bit];
		lazy[id][bit] ^= 1;
		return;
	}
	if (lazy[id][bit] == 1)
		fixlazy (id, L, R, l, r, bit);
	int mid = (L + R) / 2;
	if (mid > l)
		modifiyer (2 * id + 0, L, mid, l, min (mid, r), bit);
	if (mid < r)
		modifiyer (2 * id + 1, mid, R, max (l, mid), r, bit);
	seg[id][bit] = seg[2 * id + 0][bit] + seg[2 * id + 1][bit];
}

void build (int id, int L, int R, int bit){
	if (L + 1 == R){
		seg[id][bit] = (s[L][bit] == '1');
		return;
	}
	int mid = (L + R) / 2;
	build (2 * id + 0, L, mid, bit);
	build (2 * id + 1, mid, R, bit);
	seg[id][bit] = seg[2 * id + 0][bit] + seg[2 * id + 1][bit];
	return;
}

string f (int x){
	string k;
	while (k.size() < 30){
		k += (x % 2) + '0';
		x /= 2;
	}	
	return k;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	n ++;
	for (int i = 1; i < n; i++){
		int a;
		cin >> a;
		s[i] = f (a);
	}
	for (int i = 0; i < 30; i++)
		build (1, 1, n, i);
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++){
		int type;
		cin >> type;
		if (type == 1){
			ll ans = 0;
			int l, r;
			cin >> l >> r;
			r ++;
			for (int i = 0; i < 30; i++)
				ans += (1ll << i) * get (1, 1, n, l, r, i);
			cout << ans << endl;
		}
		else {
			int l, r, x;
			cin >> l >> r >> x;
			r ++;
			string mbn = f (x);
			for (int i = 0; i < 30; i++)
				if (mbn[i] == '1')
					modifiyer (1, 1, n, l, r, i);
		}
	}
}