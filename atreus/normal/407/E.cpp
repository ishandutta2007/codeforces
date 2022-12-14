#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 10;
const ll inf = 2e12 + 10;

int n, k, d;
ll seg[4 * maxn], lazy[4 * maxn];

stack<ll> mx, mn;

inline pair<int, int> pairmax(pair<int, int> fi, pair<int, int> se){
	if (fi.second - fi.first >= se.second - se.first)
		return fi;
	return se;
}

void propagate(int, int, int);

int get(int id, int L, int R, int l, int r, ll val){
	if (seg[id] > val)
		return n + 1;
	if (L + 1 == R)
		return L;
	propagate(id, L, R);
	int mid = (L + R) >> 1, ret = n + 1;
	if (l < mid)
		ret = get(2 * id + 0, L, mid, l, min(mid, r), val);
	if (ret != n + 1)
		return ret;
	return get(2 * id + 1, mid, R, max(l, mid), r, val);
}

void add(int id, int L, int R, int l, int r, ll val = 1){
//	if (id == 1)
//		cout << "added : " << l << " " << r << " -> " << val << endl;
	if (L == l and R == r){
		seg[id] += val;
		lazy[id] += val;
		return;
	}
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	if (l < mid)
		add(2 * id + 0, L, mid, l, min(mid, r), val);
	if (mid < r)
		add(2 * id + 1, mid, R, max(l, mid), r, val);
	seg[id] = min(seg[2 * id + 0], seg[2 * id + 1]);	
}

void propagate(int id, int L, int R){
	if (lazy[id] == 0)
		return;
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, L, mid, lazy[id]);
	add(2 * id + 1, mid, R, mid, R, lazy[id]);
	lazy[id] = 0;
}

ll a[maxn], b[maxn];
map<ll, int> last;

void relax_max(int idx){
	add(1, 1, n + 1, idx, idx + 1, a[idx]);
	while (a[mx.top()] < a[idx]){
		int k = a[mx.top()];
		int now = mx.top();
		mx.pop();
		int pre = mx.top();
		add(1, 1, n + 1, pre + 1, now + 1, a[idx] - k);
	}
	mx.push(idx);
}

void relax_min(int idx){
	add(1, 1, n + 1, idx, idx + 1, -b[idx]);
	while (b[mn.top()] > b[idx]){
		int k = b[mn.top()];
		int now = mn.top();
		mn.pop();
		int pre = mn.top();
		add(1, 1, n + 1, pre + 1, now + 1, -b[idx] + k);
	}
	mn.push(idx);
}

pair<int, int> solve(int L, int R){
	for (int i = L; i <= R; i++){
		if (a[i] < 0){
			a[i] = -a[i];
			a[i] = (a[i] - 1) / d + 1;
			a[i] = -a[i];
		}
		else{
			a[i] /= d;
		}
		b[i] = a[i];
		add(1, 1, n + 1, i, i + 1, i);
	}
	while (!mx.empty())
		mx.pop();
	while (!mn.empty())
		mn.pop();

	a[L - 1] = inf;
	mx.push(L - 1);
	b[L - 1] = -inf;
	mn.push(L - 1);

	last.clear();
	int pre = L - 1;
	pair<int, int> ret{1, 1};
	for (int i = L; i <= R; i++){
		relax_max(i);
		relax_min(i);
		if (last.count(a[i]))
			pre = max(pre, last[a[i]]);
		last[a[i]] = i;
		int l = get(1, 1, n + 1, pre + 1, i + 1, k + i);
		ret = pairmax(ret, {l, i});
	}
	return ret;
}

int d0[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k >> d;
	if (d == 0){
		pair<int, int> answer = {1, 1};
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			d0[i] = 1;
			if (a[i] == a[i - 1])
				d0[i] = d0[i - 1] + 1;
			answer = pairmax(answer, {i - d0[i] + 1, i});
		}
		cout << answer.first << " " << answer.second << endl;
		return 0;
	}
	int last = 1;
	pair<int, int> answer = {1, 1};
	for (int i = 1; i <= n + 1; i++){
		if (i != n + 1)
			cin >> a[i];
		if (i == n + 1 or (i > 1 and ((a[i] % d) + d) % d != ((a[i - 1] % d) + d) % d)){
			answer = pairmax(answer, solve(last, i - 1));
			last = i;
		}
	}
	cout << answer.first << " " << answer.second << endl;
}