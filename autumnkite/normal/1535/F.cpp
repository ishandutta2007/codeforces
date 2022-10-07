#include <bits/stdc++.h>

class Trie {
	static const int C = 26, BASE = 1145141;

	struct node {
		node *son[C];
		std::map<unsigned long long, int> cnt;
		std::vector<unsigned long long> Q;

		node() : son{} {}
	};

	node *rt;

	void merge(std::map<unsigned long long, int> &A, 
	           std::map<unsigned long long, int> &B) {
		if (A.size() < B.size()) {
			A.swap(B);
		}
		for (const auto &p : B) {
			A[p.first] += p.second;
		}
		B.clear();
	}

	long long dfs(node *u) {
		long long ans = 0;
		for (int i = 0; i < C; ++i) {
			if (u->son[i]) {
				ans += dfs(u->son[i]);
				merge(u->cnt, u->son[i]->cnt);
			}
		}
		for (auto x : u->Q) {
			ans += u->cnt[x];
		}
		return ans;
	}

public:
	Trie() {
		rt = new node();
	}

	int insert(const std::string &s) {
		std::vector<unsigned long long> pre(s.size() + 1);
		for (int i = 0; i < (int)s.size(); ++i) {
			pre[i + 1] = pre[i] * BASE + s[i];
		}
		node *u = rt;
		++u->cnt[pre[s.size()]];
		for (int i = (int)s.size() - 1; i >= 0; --i) {
			node *&v = u->son[s[i] - 'a'];
			if (v == NULL) {
				v = new node();
			}
			u = v;
			++u->cnt[pre[i]];
		}
		u = rt;
		int r = s.size();
		int cnt = 0;
		while (r > 0) {
			++cnt;
			int l = r - 1;
			while (l > 0 && s[l] >= s[l - 1]) {
				--l;
			}
			u->Q.push_back(pre[l]);
			while (r > l) {
				u = u->son[s[--r] - 'a'];
			}
		}
		return cnt;
	}

	long long get_ans() {
		return dfs(rt);
	}
};

long long solve(const std::vector<std::string> &a) {
	Trie T;
	std::map<std::string, std::pair<int, int>> mp;
	for (const auto &p : a) {
		int t = T.insert(p);
		if (mp.count(p)) {
			++mp[p].first;
		} else {
			mp[p] = std::make_pair(1, t);
		}
	}
	long long ans = T.get_ans();
	long long cnt = 1ll * a.size() * a.size();
	for (const auto &p : mp) {
		ans -= 1ll * p.second.first * p.second.first * p.second.second;
		cnt -= 1ll * p.second.first * p.second.first;
	}
	cnt -= 2 * ans;
	return ans + cnt;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::map<std::string, std::vector<std::string>> mp;
	for (int i = 0; i < n; ++i) {
		std::string a;
		std::cin >> a;
		std::string b(a);
		std::sort(a.begin(), a.end());
		mp[a].push_back(b);
	}

	long long ans = 1ll * n * n;
	for (const auto &p : mp) {
		ans -= 1ll * p.second.size() * p.second.size();
	}
	ans /= 2;
	ans *= 1337;
	for (const auto &p : mp) {
		ans += solve(p.second);
	}
	std::cout << ans << "\n";
}