#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 200005;
const int MAXD = 1005;

int N, M;
bool bio[MAXN];
vector <int> v[MAXN];
int dp[MAXD], dad[MAXD];

void load() {
	scanf("%d%d", &N, &M);
	while (N--) {
		int x;
		scanf("%d", &x);
		bio[x] = true;
	}
}

pii ext_euc(int a, int b) {
	if (!b)
		return {1, 0};
	pii tmp = ext_euc(b, a % b);
	return {-tmp.second, -tmp.first - a / b * tmp.second};
}

int divide(int a, int b) {
	int g = __gcd(b, M);
	assert(!(a % g));
	a /= g;
	b /= g;
	int m = M / g;
	int inv = (ext_euc(b, m).first % m + m) % m;
	return (long long)inv * a % m;
}

void solve() {
	if (M == 1) {
		printf("1\n0\n");
		return;
	}
	
	vector <int> divs;
	for (int i = 1; i < M; i++) {
		if (!bio[i])
			v[__gcd(i, M)].push_back(i);
		if (!(M % i))
			divs.push_back(i);
	}
	
	memset(dad, -1, sizeof dad);
	
	int best = 0;
	for (int i = 0; i < divs.size(); i++) {
		for (int j = 0; j < i; j++)
			if (!(divs[i] % divs[j]) && dp[j] > dp[i]) {
				dp[i] = dp[j];
				dad[i] = j;
			}
		dp[i] += v[divs[i]].size();
		if (dp[i] > dp[best]) 
			best = i;
	}
	
	vector <int> seq;
	while (1) {
		seq.push_back(best);
		if (dad[best] == -1)
			break;
		best = dad[best];
	}
	
	reverse(seq.begin(), seq.end());
	
	vector <int> sol;
	for (auto it : seq)
		for (auto num : v[divs[it]])
			sol.push_back(num);
	
	for (int i = (int)sol.size() - 1; i > 0; i--)
		sol[i] = divide(sol[i], sol[i - 1]);
	if (!bio[0]) 
		sol.push_back(0);
	
	printf("%d\n", sol.size());
	for (auto it : sol)
		printf("%d ", it);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}