#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<bitset>
#define pii pair<int,int>
const int MX = 33333333;
using namespace std;
int n, cnt, p[2100000], pc, v[51];
bitset<MX>Prime;
map<long long, int>Map;
vector<long long>d[51];
int R[51][101000];
long long Pow(long long a, long long b, long long Mod) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r * a%Mod;
		a = a * a%Mod; b >>= 1;
	}
	return r;
}
bool OK(long long a, long long b, long long n) {
	long long inv = Pow(b, a-2, a);
	long long t = (n % a)*inv%a;
	if (n >= b * t)return true;
	return false;
}
priority_queue<pii>PQ;
void Dijk(int *a, vector<long long>&D) {
	int Mod = D[0];
	int i;
	for (i = 0; i < Mod; i++) a[i] = 1e9;
	a[0] = 0;
	PQ.push({ 0,0 });
	while (!PQ.empty()) {
		auto tp = PQ.top();
		PQ.pop();
		if (a[tp.second] != -tp.first)continue;
		int x = tp.second;
		for (auto &t : D) {
			int aa = (x + t) % Mod;
			long long dd = (x + t) / Mod;
			if (a[aa] > a[x] + dd) {
				a[aa] = a[x] + dd;
				PQ.push({ -a[aa],aa });
			}
		}
	}
}
bool Pos(long long n, vector<long long>&D, int num) {
	if (D.empty())return false;
	if (D.size() == 1) {
		if (n%D[0] == 0)return true;
		return false;
	}
	if (OK(D[0], D[1], n))return true;
	if (D.size() == 2)return false;
	if (!v[num]) {
		v[num] = 1;
		Dijk(R[num], D);
	}
	if (R[num][n%D[0]] <= n / D[0])return true;
	return false;
}
int main() {
	long long m, n;
	int i, j;
	for (i = 2; i < MX; i++) {
		if (Prime[i] == 1) continue;
		p[pc++] = i;
		for (j = i + i; j < MX; j += i)Prime[j] = 1;
	}
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		scanf("%lld%lld", &m, &n);
		if (!Map.count(n)) {
			Map[n] = ++cnt;
			long long t = n;
			for (i = 0; (long long)p[i] * p[i] <= t; i++) {
				if (t%p[i] == 0) {
					while (t%p[i] == 0)t /= p[i];
					d[cnt].push_back(p[i]);
				}
			}
			if (t != 1)d[cnt].push_back(t);
		}
		if (Pos(m, d[Map[n]], Map[n]))puts("YES");
		else puts("NO");
	}
	return 0;
}