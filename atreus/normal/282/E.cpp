#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cmath>
#include <unordered_set>
#include <map>
#include <deque>
#include <unordered_map>
#include <fstream>
#include <set>
#include <algorithm>
#include <iomanip>
#define fin cin
#define fout cout
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;
const ll Inf = 1e18;

struct node {
	int t;
	node *child[2];
	node () {
		t = 0;
		child[0] = child[1] = NULL;
	}
};

void add (node *root, ll a) {
	for (int i = 40; i >= 0; i--) {
		if (a & (1ll << i)) {
			if (root -> child[1] == NULL)
				root -> child[1] = new node();
			root = root -> child[1];
			root -> t ++;
		}
		else {
			if (root -> child[0] == NULL)
				root -> child[0] = new node();
			root = root -> child[0];
			root -> t ++;
		}
	}
}

void del (node *root, ll a) {
	for (int i = 40; i >= 0; i--) {
		if (a & (1ll << i)) 
			root = root -> child[1];
		else
			root = root -> child[0];
		root -> t --;
	}
}

ll get (node *root, ll a) {
	ll ret = 0;
	for (int i = 40; i >= 0; i--) {
		if (a & (1ll << i)) {
			if (root -> child[0] != NULL and root -> child[0] -> t > 0) {
				root = root -> child[0];
				ret += (1ll << i);
			}
			else
				root = root -> child[1];		
		}
		else {
			if (root -> child[1] != NULL and root -> child[1] -> t > 0) {
				root = root -> child[1];
				ret += (1ll << i);
			}
			else
				root = root -> child[0];
		}
	}
	return ret;
}

ll a[maxn], x[maxn];

int main () {
	ios_base::sync_with_stdio (false);
	srand (time (NULL));
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	ll Max = 0;
	node *root = new node;
	for (int i = n; i >= 1; i--) {
		x[i] = (x[i + 1] ^ a[i]);
		add (root, x[i]);
		Max = max (Max, x[i]);
	}
	add (root, 0);

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		del (root, x[i]);
		a[i] ^= a[i - 1];
		ans = max (ans, get (root, a[i]));
	}
	ans = max (ans, Max);
	cout << ans << endl;
}