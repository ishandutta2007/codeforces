#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;

int N;
int p[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", p + i);
}

bool cmp(const pii &lhs, const pii &rhs) {
	if (lhs.first != rhs.first)
		return lhs.first > rhs.first;
	return lhs.second < rhs.second;
}

int solve() {
	vector <int> rec;
	rec.push_back(0);
	vector <int> rest;
	for (int i = 1; i <= N; i++)
		if (p[i] > p[rec.back()]) 
			rec.push_back(i);
		else
			rest.push_back(i);
	rec.push_back(N + 1);
	
	int sz = rec.size();
	vector <pii> cand;
	for (auto it : rest)
		cand.push_back({sz - 2, p[it]});
		
	for (int i = 1; i < sz - 1; i++) {
		int mx = p[rec[i - 1]], cnt = 0;
		for (int j = rec[i] + 1; j < rec[i + 1]; j++)
			if (p[j] > mx) {
				mx = p[j];
				cnt++;
			}
		cand.push_back({sz - 3 + cnt, p[rec[i]]});
	}
	
	sort(cand.begin(), cand.end(), cmp);
	
	return cand[0].second;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}