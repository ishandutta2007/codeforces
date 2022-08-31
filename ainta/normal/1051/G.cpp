#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#define N_ 201000
#define FI first
#define SE second
#define pii pair<int,int>
using namespace std;
int n, INF = 1e9, cur;
vector<int>U[N_];
map<int, int>Map[N_];
struct point {
	int b, e, num;
	bool operator <(const point &p)const {
		return b != p.b ? b < p.b : e != p.e ? e < p.e : num < p.num;
	}
};
struct PPP {
	int ck, num, x;
};
vector<PPP>V[N_];
set<point>Set;
void Move(int a, int b) {
	for (auto &x : U[a]) {
		U[b].push_back(x);
		V[cur].push_back({ 2,b, x });
	}
	V[cur].push_back({ 3,a,0 });
}
void Put(int a, int b, int num) {
	cur = num;
	Set.insert({ a,a,num });
	V[cur].push_back({ 1,num,a });
	V[cur].push_back({ 2,num,b });
	U[num].push_back(b);
	auto it = Set.find({ a,a,num });
	while (it != Set.begin()) {
		auto it2 = it;
		it2--;
		if (it2->e + 1 >= it->b) {
			int sz2 = it2->e - it2->b + 1;
			int sz = it->e - it->b + 1;
			int num1 = it->num;
			int num2 = it2->num;
			if (sz > sz2)swap(num2, num1);
			Move(num1, num2);
			point tp = {it2->b, it2->b + (sz2 + sz) - 1, num2};
			V[cur].push_back({ 1,num2, it2->b });
			Set.erase(it);
			Set.erase(it2);
			Set.insert(tp);
			it = Set.find(tp);
		}
		else break;
	}
	while (1) {
		auto it2 = it;
		it2++;
		if (it2 == Set.end())break;
		if (it->e + 1 >= it2->b) {
			int sz2 = it2->e - it2->b + 1;
			int sz = it->e - it->b + 1;
			int num1 = it->num;
			int num2 = it2->num;
			if (sz > sz2)swap(num2, num1);
			Move(num1, num2);
			point tp = { it->b, it->b + (sz2 + sz) - 1, num2 };
			V[cur].push_back({ 1,num2, it->b });
			Set.erase(it);
			Set.erase(it2);
			Set.insert(tp);
			it = Set.find(tp);
		}
		else break;
	}
}

long long BB[N_*60], Res;
int BB2[N_ * 60];
int SZ[N_], bb[N_];
long long *BIT[N_];
long long SS[N_], RR[N_], CCC[N_];
int *BIT2[N_];

struct AA {
	int a, b;
}w[N_];

void Add(int pv, int x, long long b) {
	while (x <= SZ[pv]) {
		BIT[pv][x] += b;
		x += (x&-x);
	}
}
long long Sum(int pv, int x) {
	long long r = 0;
	while (x) {
		r += BIT[pv][x];
		x -= (x&-x);
	}
	return r;
}

void Add2(int pv, int x, int b) {
	while (x <= SZ[pv]) {
		BIT2[pv][x] += b;
		x += (x&-x);
	}
}
int Sum2(int pv, int x) {
	int r = 0;
	while (x) {
		r += BIT2[pv][x];
		x -= (x&-x);
	}
	return r;
}
int main() {
	int i, a, b;
	Set.insert({ -10,-10 });
	Set.insert({ INF,INF });
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &a, &b);
		Put(a, b, i);
		w[i] = { a,b };
	}

	int s = 0;
	for (i = 1; i <= n; i++) {
		if (!U[i].empty()) {
			sort(U[i].begin(), U[i].end());
			for (int j = 0; j < U[i].size(); j++)Map[i][U[i][j]] = j + 1;
		}
		BIT[i] = BB + s;
		BIT2[i] = BB2 + s;
		SZ[i] = U[i].size();
		s += SZ[i] + 1;
	}
	for (i = 1; i <= n; i++) {
		Res -= 1ll * w[i].a*w[i].b;
		for (auto &t : V[i]) {
			Res -= RR[t.num];
			if (t.ck == 1) {
				RR[t.num] -= SS[t.num] * bb[t.num];
				bb[t.num] = t.x;
				RR[t.num] += SS[t.num] * bb[t.num];
			}
			if (t.ck == 2) {
				RR[t.num] -= SS[t.num] * bb[t.num];
				int xx = Map[t.num][t.x];
				RR[t.num] += Sum(t.num, xx);
				Add(t.num, xx, t.x);
				RR[t.num] += 1ll * t.x * (CCC[t.num] - Sum2(t.num, xx));
				Add2(t.num, xx, 1);
				SS[t.num] += t.x;
				RR[t.num] += SS[t.num] * bb[t.num];
				CCC[t.num]++;
			}
			if (t.ck == 3)RR[t.num] = 0;
			Res += RR[t.num];
		}
		printf("%lld\n", Res);
	}
}