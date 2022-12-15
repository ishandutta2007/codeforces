#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<long double> point;

const int maxn = 2e5 + 10;

int m = 0;
vector<int> g[maxn];
int h[maxn], lef[maxn], rig[maxn];
int pre[maxn], last[2*maxn], org[maxn];;
bool mark[2*maxn];

struct Teacher{
	int L, R;
	bool w;
	Teacher(){
		L = 0, R = 1000*1000*1000;
	}
	void merge(int l, int r){
		L = max(L, l);
		R = min(R, r);
	}
	void vitex(){
		L = 0, R = 1000*1000*1000;
	}
} A, B, t[2*maxn];

void dfs(int v){
	if (h[v] & 1)
		B.merge(lef[v], rig[v]), org[v] = m+1;
	else
		A.merge(lef[v], rig[v]), org[v] = m;
	for (auto u : g[v]){
		if (h[u] == -1){
			h[u] = h[v] + 1;
			dfs(u);
		}
		else if ((h[u] & 1) == (h[v] & 1)){
			cout << "IMPOSSIBLE\n";
			exit(0);
		}
	}
}

multiset<int> S, T;

void add(Teacher a){
	S.insert(a.L);
	T.insert(a.R);
}
void del(Teacher a){
	S.erase(S.find(a.L));
	T.erase(T.find(a.R));
}
pair<int,int> get(){
	if (S.empty())
		return {-1,-1};
	int l = *S.rbegin(), r = *T.begin();
	if (l > r)
		return {-1,-1};
	return {l,r};
}

int main(){
	ios_base::sync_with_stdio(false);
	int lo, hi;
	cin >> lo >> hi;
	int n, ed;
	cin >> n >> ed;
	for (int i = 0; i < n; i++)
		cin >> lef[i] >> rig[i];
	for (int i = 0; i < ed; i++){
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	memset(h, -1, sizeof h);
	vector<int> a;
	for (int i = 0; i < n; i++){
		if (h[i] == -1){
			h[i] = 0;
			A.vitex(), B.vitex();
			dfs(i);
			a.push_back(A.L);
			a.push_back(A.R+1);
			a.push_back(B.L);
			a.push_back(B.R+1);
			t[m++] = A, t[m++] = B;
		}
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	memset(last, -1, sizeof last);
	int ub = (int)a.size();
	for (int i = 0; i < m; i++){
		int x = lower_bound(a.begin(), a.end(), t[i].L) - a.begin();
		int y = upper_bound(a.begin(), a.end(), t[i].R) - a.begin();
		ub = min(ub, y);
		pre[i] = last[x];
		last[x] = i;
	}
	for (int i = 0; i < m; i++)
		add(t[i]);
	int n1 = -1, n2 = -1;
	int cnt = 0;
	for (int i = 0; i < ub; i++){
		int nl = a[i], nr = a[i+1]-1;
		for (int j = last[i]; j != -1; j = pre[j]){
			if (!mark[j^1]){
				del(t[j]);
				cnt ++;
				mark[j] = 1;
				continue;
			}
			if (t[j].R < t[j^1].R){
				del(t[j]);
				add(t[j^1]);
			}
		}
		auto it = get();
		int l = it.first, r = it.second;
		if (l == -1 and r == -1)
			continue;
		if (cnt == m/2 and nl + l <= hi and lo <= nr + r){
			n1 = min(nr, hi - l);
			n2 = min(r, hi - n1);
		}
	}
	if (n1 == -1 and n2 == -1)
		return cout << "IMPOSSIBLE\n", 0;
	if (n1 > n2)
		swap(n1, n2);
	for (int i = 0; i < m; i += 2){
		if (t[i].R < n2 or n1 < t[i^1].L){
			t[i].w = 0, t[i^1].w = 1;
			continue;
		}
		t[i].w = 1, t[i^1].w = 0;
	}
	cout << "POSSIBLE\n";
	assert(lo <= n1 + n2 and n1 + n2 <= hi);
	cout << n1 << " " << n2 << endl;
	for (int i = 0; i < n; i++)
		cout << t[org[i]].w + 1;
	cout << endl;
}