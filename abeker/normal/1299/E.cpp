#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 8e2 + 5;

int N;
vector <pii> pos;
int perm[MAXN], inv[MAXN];
vector <int> subset[12][12];
int num[3][5][7][8];

int query(const vector <int> &v) {
	if (v.size() == 1)
		return 1;
	printf("? %d", v.size());
	for (auto it : v)
		printf(" %d", it);
	puts("");
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	return ans;
}

void find_ends(int iter) {
	vector <int> curr;
	for (int i = 1; i <= N; i++)
		curr.push_back(i);
		
	for (int i = 0; i < iter; i++) {
		vector <int> ends;
		for (auto it1 : curr) {
			vector <int> tmp;
			for (auto it2 : curr)
				if (it2 != it1)
					tmp.push_back(it2);
			if (query(tmp))
				ends.push_back(it1);
		}
		assert(ends.size() == 2);
		pos.push_back({ends[0], ends[1]});
		vector <int> nxt;
		for (auto it : curr)
			if (it != ends[0] && it != ends[1])
				nxt.push_back(it);
		curr = nxt;
	}
	
	for (int i = 1; i < iter; i++)
		if (query({pos[0].first, pos[i].first}) == i % 2)
			swap(pos[i].first, pos[i].second);
	
	for (int i = 0; i < iter; i++) {
		perm[pos[i].first] = i + 1;
		perm[pos[i].second] = N - i;
		inv[i + 1] = pos[i].first;
		inv[N - i] = pos[i].second;
	}
}

void output() {
	bool flip = perm[1] > N / 2;
	printf("!");
	for (int i = 1; i <= N; i++)
		printf(" %d", flip ? N + 1 - perm[i] : perm[i]);
	puts("");
	fflush(stdout);
	exit(0);
}

int main() {
	scanf("%d", &N);
	assert(N % 2 == 0);
	
	if (N < 10) {
		find_ends(N / 2);
		output();
	}
	
	find_ends(5);
	
	vector <int> en;
	for (int i = 1; i <= N; i++)
		if (inv[i])
			en.push_back(i);
	assert(en.size() == 10);
	
	for (int i = 0; i < 1 << 10; i++) {
		int sum = 0;
		vector <int> tmp;
		for (int j = 0; j < 10; j++)
			if (i >> j & 1) {
				tmp.push_back(inv[en[j]]);
				sum += en[j];
			}
		subset[tmp.size() + 1][sum % (tmp.size() + 1)] = tmp;
	}
	
	for (int i = 0; i < 840; i++)
		num[i % 3][i % 5][i % 7][i % 8] = i;
		
	for (int i = 1; i <= N; i++) {
		if (perm[i])
			continue;
		vector <int> rems;
		for (int mod : {3, 5, 7, 8}) {
			int val = 0;
			for (int j = 1; j < mod; j++) {
				vector <int> tmp = subset[mod][mod - j];
				assert(tmp.size() == mod - 1);
				tmp.push_back(i);
				if (query(tmp)) {
					val = j;
					break;
				}
			}
			rems.push_back(val);
		}
		perm[i] = num[rems[0]][rems[1]][rems[2]][rems[3]];
	}
	
	output();

	return 0;
}