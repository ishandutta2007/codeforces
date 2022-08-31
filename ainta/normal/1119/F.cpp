#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#define szz(x) ((int)x.size())
#define N_ 251000
using namespace std;
vector<long long>D1[N_], D0[N_];
vector<int>E[N_], L[N_];
long long TD1[N_], TD0[N_], BS0[N_], BS1[N_];
int n, Num[N_], pL[N_], INF = 1e9, Bef[N_], chk[N_];
typedef pair<int, int> pii;
struct MaxK {
	multiset<int>Set1, Set2;
	int K;
	long long S;
	void init(int k) {
		K = k;
		S = 0;
		Set1.clear();
		Set2.clear();
	}
	void Balance() {
		while (Set2.size() < K && !Set1.empty()) {
			auto it = Set1.end(); it--;
			S += *it;
			Set2.insert(*it);
			Set1.erase(it);
		}
		while (Set2.size() > K) {
			auto it = Set2.begin();
			S -= *it;
			Set1.insert(*it);
			Set2.erase(it);
		}
	}

	void Change(int t) {
		K = t;
		Balance();
	}
	void Put(int a) {
		if (Set2.empty() || a < *Set2.begin())Set1.insert(a);
		else {
			Set2.insert(a);
			S += a;
		}
		Balance();
	}
	void Del(int a) {
		auto it = Set1.find(a);
		if (it != Set1.end()) {
			Set1.erase(it);
		}
		else {
			Set2.erase(Set2.find(a));
			S -= a;
		}
		Balance();
	}
}PP;

long long Get1(int a, int b) {
	b = min(b, szz(D0[Num[a]]) - 1);
	return D1[Num[a]][b] + BS1[Num[a]];
}

long long Get0(int a, int b) {
	b = min(b, szz(D0[Num[a]]) - 1);
	if (chk[Num[a]] <= b) return Get1(a, b);
	return D0[Num[a]][b] + BS0[Num[a]];
}

void DP(int a, int pp) {
	int pv = -1, i, j;
	for (i = 0; i < E[a].size(); i++) {
		int x = E[a][i];
		if (x != pp) {
			pL[x] = L[a][i];
			DP(x, a);
			pv = x;
		}
	}
	if (pv == -1) {
		Num[a] = a;
		D1[a].resize(2);
		D0[a].resize(2);
		D1[a][1] = 0;
		D0[a][1] = 0;
		BS0[a] = 0, BS1[a] = 0;
		return;
	}
	int MC = 0;
	vector<pii>T;
	for (auto &x : E[a]) {
		if (x != pp) {
			int t = szz(D0[Num[x]]) - 1;
			T.push_back({ t ,x });
			BS1[Num[x]] += pL[x];
		}
	}
	int deg = E[a].size();
	PP.init(0);
	sort(T.begin(), T.end());
	reverse(T.begin(), T.end());
	long long ss = 0;
	if (T.size() > 1)MC = T[1].first;

	int MM = max(MC, deg);

	for (i = 1; i <= MM; i++) {
		for (auto &t : T) {
			if (t.first < i)break;
			int x = t.second;

			if (i != 1) {
				PP.Del(Bef[x]);
				ss -= Get0(x, i - 1);
				if (i-1 >= chk[Num[x]]) {
					ss += pL[x];
				}
			}
			long long d0 = Get0(x, i);
			if (i >= chk[Num[x]]) {
				d0 -= pL[x];
			}
			long long d1 = Get1(x, i);
			if (d0 > d1) {
				while (1) {}
			}
			ss += d0;

			Bef[x] = d1 - d0;
			PP.Put(d1 - d0);
		}
		PP.Change(i - 1);
		TD1[i] = ss + PP.S;
		PP.Change(i);
		TD0[i] = ss + PP.S;
		TD1[i] = max(TD1[i], TD0[i] - pL[a]);
	}

	if (T[0].first <= MM) {
		int x = T[0].second;
		Num[a] = Num[x];
		D0[Num[a]].resize(MM + 1);
		D1[Num[a]].resize(MM + 1);
		BS0[Num[a]] = BS1[Num[a]] = 0;
		chk[Num[a]] = 1e9;
		for (i = 1; i <= MM; i++)D0[Num[a]][i] = TD0[i], D1[Num[a]][i] = TD1[i];
		return;
	}

	int x = T[0].second;
	Num[a] = Num[x];
	ss = 0;
	for (i = 1; i < T.size(); i++) {
		ss += Get1(T[i].second, n);
	}

	chk[Num[a]] = MM + 1;
	BS1[Num[a]] += ss;
	for (i = 1; i <= MM; i++) {
		D0[Num[a]][i] = TD0[i] - BS0[Num[a]];
		D1[Num[a]][i] = TD1[i] - BS1[Num[a]];
	}

}
int main() {
	//freopen("input.txt", "r", stdin);
	int i, a, b, c;
	long long ss = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)chk[i] = 1e9;
	for (i = 1; i < n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		ss += c;
		E[a].push_back(b);
		L[a].push_back(c);
		E[b].push_back(a);
		L[b].push_back(c);
	}
	DP(1, 0);
	printf("%lld ", ss);
	for (i = 1; i < n; i++) {
		printf("%lld ", ss - Get1(1, i));
	}
}