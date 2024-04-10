#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,int> pii;

const int maxn = 5e5 + 10;

ll seg[4 * maxn], lazy[4 * maxn];

void propagate(int, int, int);

void change(int id, int L, int R, int l, int r, ll val){
	if (L == l and R == r){
		seg[id] += val;
		lazy[id] += val;
		return;
	}
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	if (mid > l)
		change(2 * id + 0, L, mid, l, min(mid, r), val);
	if (mid < r)
		change(2 * id + 1, mid, R, max(l, mid), r, val);
	seg[id] = min(seg[2 * id + 0], seg[2 * id + 1]);
}

void propagate(int id, int L, int R){
	if (lazy[id] == 0)
		return;
	int mid = (L + R) >> 1;
	change(2 * id + 0, L, mid, L, mid, lazy[id]);
	change(2 * id + 1, mid, R, mid, R, lazy[id]);
	lazy[id] = 0;
}

ll a[maxn], b[maxn], c[maxn], par[maxn];

int main(){
	ios_base::sync_with_stdio(false);	
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
	n ++;
	sort(a + 1, a + n + 1, greater <ll> ());
	for (int i = 1; i <= n; i++)
		b[i] = b[i - 1] + a[i];
	
	for (int i = n; i >= 1; i--)
		par[i] = par[i + 1] + a[i];

	for (int i = n; i >= 1; i--){
		int lo = i, hi = n + 1;
		while (hi - lo > 1){
			int mid = (hi + lo) >> 1;
			if (a[mid] <= i)
				hi = mid;
			else
				lo = mid;
		}
		c[i] = 1ll * i * (i - 1) + 1ll * (lo - i) * i + par[hi];
	}
	
	for (int i = 1; i <= n; i++)
		change(1, 1, n + 1, i, i + 1, c[i] - b[i]);

	vector <int> answer;
	int idx = n;
	while (a[idx] <= n - 1){
		if (seg[1] >= 0 and sum % 2 == 0)
			answer.push_back(a[idx]);

		change(1, 1, n + 1, idx, n + 1, -1);
		if (a[idx] + 1 < idx)
			change(1, 1, n + 1, a[idx] + 1, idx, +1);
		a[idx] ++;
		sum ++;

		while (idx > 1 and a[idx] > a[idx - 1]){
			change(1, 1, n + 1, idx - 1, idx, -1);
			if (a[idx] <= idx - 1)
				change(1, 1, n + 1, idx - 1, idx, -1);
			swap(a[idx], a[idx - 1]);
			idx --;
		}
	}
	if (answer.empty())
		return cout << -1 << endl, 0;
	
	for (auto it : answer)
		cout << it << " ";
	cout << endl;
}