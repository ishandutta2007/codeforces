#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2005;
const int MAXP = 100005;

int N;
int p[MAXN];
int left[MAXN], right[MAXN];
vector <pii> V[MAXP];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", p + i);
}

int solve() {
	for (int i = 0; i < N; i++)
		p[i] = abs(p[i]);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++)
			left[i] += p[j] < p[i];
		for (int j = i + 1; j < N; j++)
			right[i] += p[j] < p[i];
		V[p[i]].push_back({left[i], right[i]});
	}
	
	int sol = 0;
	for (int i = 1; i < MAXP; i++) {
		int sum = 0;
		vector <int> tmp;
		for (int j = 0; j < V[i].size(); j++) {
			V[i][j].first += j;
			sum += V[i][j].second;
			tmp.push_back(V[i][j].first - V[i][j].second);
		}
		sort(tmp.begin(), tmp.end());
		int mini = 0, pref = 0;
		for (int j = 0; j < tmp.size(); j++) {
			pref += tmp[j] - j;
			mini = min(mini, pref);
		}
		sol += sum + mini;	
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}