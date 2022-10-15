#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define x first
#define y second
#define mod % 1000000007
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef map<int, int>::iterator mit;
const int MAX = 2e5 + 1;
const ld E = 1e-11;

int ar[MAX + 1], o, n;

struct event{
	int time, type, val;
};

event makeAdd(int val){
	event e;
	e.time = 1;
	e.type = 1;
	e.val = val;
	return e;
}

event makeRemove(int val, int time){
	event e;
	e.time = time + 1;
	e.val = val;
	e.type = 2;
	return e;
}

vector<event> v;

ll t[MAX * 4];

void build(int v, int l, int r){
	if(l > r)
		return;
	if(l == r){
		t[v] = l;
		return;
	}
	int x = (l + r) / 2;
	build(v * 2, l, x);
	build(v * 2 + 1, x + 1, r);
	t[v] = (ar[t[v * 2]] < ar[t[v * 2 + 1]] ? t[v * 2] : t[v * 2 + 1]);
}

int getMin(int v, int tl, int tr, int l, int r){
	if(l > r)
		return n;
	if(tl == l && tr == r)
		return t[v];
	int x = (tl + tr) / 2;
	int a = getMin(v * 2, tl, x, l, min(r, x)), b = getMin(v * 2 + 1, x + 1, tr, max(l, x + 1), r);
	return (ar[a] < ar[b] ? a : b);
}

void solve(int l, int r){
	if(l > r)
		return;
	if(l == r){
		v.push_back(makeAdd(ar[l]));
		v.push_back(makeRemove(ar[l], 1));
		return;
	}
	int m = getMin(1, 0, n - 1, l, r);
	v.push_back(makeAdd(ar[m]));
	v.push_back(makeRemove(ar[m], r - l + 1));
	solve(l, m - 1);
	solve(m + 1, r);
}

bool check(event a, event b){
	return a.time < b.time;
}

void solveLong(){
	for(int i = 1; i <= n; i++){
		int ans = 0;
		for(int j = 0; j < n - i + 1; j++){
			int res = INT_MAX;
			for(int z = j; z < j + i; z++)
				res = min(res, ar[z]);
			ans = max(ans, res);
		}
		cout << ans << " ";
	}
	cout << endl;
}

int main() {

	sync;


	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> ar[i];
	ar[n] = INT_MAX;
	build(1, 0, n - 1);
	solve(0, n - 1);
	sort(v.begin(), v.end(), check);

	int pos = 0;

	map<int, int> m;
	for(int i = 1; i <= n; i++){
		while(v[pos].time == i){
			if(v[pos].type == 1){
				m[-v[pos].val]++;
			}else{
				m[-v[pos].val]--;
				if(m[-v[pos].val] == 0)
					m.erase(-v[pos].val);
			}
			pos++;
		}
		cout << -m.begin()->first << " ";

	}


}