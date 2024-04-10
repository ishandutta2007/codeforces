#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;

int N, K;
map <string, vector <int> > M;
map <string, bool> bio;
char s[MAXN];

void load() {
	scanf("%d%d", &K, &N);
	for (int i = 0; i < K; i++) {
		int x;
		scanf("%s%d", s, &x);
		M[s].push_back(x);
	}
}

int solve() {
	for (auto &it : M)
		sort((it.second).begin(), (it.second).end()); 
	
	int sol = 0, mx = 0;
	vector <int> rest;
	for (auto it : M) {
		string tmp = it.first;
                if (bio[tmp]) continue;
		reverse(tmp.begin(), tmp.end());
                bio[tmp] = bio[it.first] = true;
		if (tmp == it.first) {
			vector <int> v = it.second;
			vector <int> curr;
			for (; !v.empty() && v.back() > 0; v.pop_back())
				curr.push_back(v.back());
			if (curr.size() % 2) {
				if (!v.empty() && curr.back() + v.back() > 0) {
					sol += curr.back() + v.back();
					mx = max(mx, -v.back());
				}
				else 
					mx = max(mx, curr.back());
				curr.pop_back();
			}
			for (int x : curr)
				sol += x;
		}
		else {
			vector <int> v1 = it.second;
			vector <int> v2 = M[tmp];
			for (; !v1.empty() && !v2.empty() && v1.back() + v2.back() > 0; v1.pop_back(), v2.pop_back())
				sol += v1.back() + v2.back();
		}
	}
	
	return sol + mx;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}