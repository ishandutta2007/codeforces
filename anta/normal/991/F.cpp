#include "bits/stdc++.h"
using namespace std;

int main() {
	struct Node {
		long long num;
		int len;
		const Node *l, *r;
		char op;
		string toStr() const {
			if (op == 0) return to_string(num);
			else return l->toStr() + op + r->toStr();
		}
	};
	vector<Node> nodes((size_t)(120e6 / sizeof(Node)));
	long long N;
	while (~scanf("%lld", &N)) {
		size_t nNodes = 0;
		auto newNode = [&]() {
			return &nodes[nNodes ++];
		};
		unordered_map<long long, const Node*> minRepr;
		unordered_map<long long, const Node*> toStrMap;
		int sqrtN = (int)sqrt((double)N);
		vector<const Node*> toStrMapSmall(1000001);
		auto toStr = [&](long long x) -> const Node* {
			if (x < (int)toStrMapSmall.size() && toStrMapSmall[(int)x] != nullptr) return toStrMapSmall[(int)x];
			auto it = toStrMap.emplace(x, nullptr).first;
			if (it->second == nullptr) {
				auto p = newNode();
				p->num = x;
				p->len = 1;
				for (long long t = 10; t <= x; t *= 10) ++ p->len;
				p->l = p->r = nullptr;
				p->op = 0;
				it->second = p;
			}
			return it->second;
		};
		for (int i = 0; i <= sqrtN; ++ i) toStrMapSmall[i] = toStr(i);
		auto best = toStr(N);
		auto upd = [&](Node s) {
			auto x = s.num;
			if (N < x) return false;
			if (best->len <= s.len + (x == N ? 0 : 2)) return false;
			if (toStr(x)->len <= s.len) return false;
			auto it = minRepr.emplace(x, nullptr).first;
			if (it->second == nullptr || it->second->len > s.len) {
				auto p = newNode();
				*p = s;
				if (x == N) best = p;
				it->second = p;
				return true;
			}
			return false;
		};
		auto opNode = [&](long long num, const Node *l, const Node *r, char op) {
			return Node{num, l->len + 1 + r->len, l, r, op};
		};
		auto getRepr = [&](long long x) -> const Node* {
			auto it = minRepr.find(x);
			if (it == minRepr.end()) return toStr(x);
			return it->second;
		};
		for (int x = 2; (long long)x * x <= N; ++ x) {
			long long y = (long long)x * x; int k = 2;
			while (1) {
				upd(opNode(y, toStr(x), toStr(k), '^'));
				if (y * x > N) break;
				y *= x, ++ k;
			}
		}
		vector<pair<long long, const Node*>> xs;
		for (int iter = 0; ; ++ iter) {
			for (const auto &x : minRepr) if (N % x.first == 0)
				upd(opNode(N, x.second, getRepr(N / x.first), '*'));
			if (iter == 1) break;
			xs.assign(minRepr.begin(), minRepr.end());
			sort(xs.begin(), xs.end(), [](const auto &x, const auto &y) { return x.second->len < y.second->len; });
			//cerr << "xs.size() = " << xs.size() << endl;
			bool f = false;
			if (iter == 0) {
				for (const auto &x : xs) {
					auto z = x.first * 2;
					int y = 2;
					for (; z <= N; ++ y, z += x.first) {
						auto yp = toStr(y), zp = toStr(z);
						if (x.second->len + 1 + yp->len >= zp->len) break;
						f |= upd(opNode(z, yp, x.second, '*'));
					}
				}
			}
			for (const auto &x : xs) if(x.first <= sqrtN) for (const auto &y : xs) {
				if (x.second->len + 1 + y.second->len >= best->len) break;
				if (x.first * y.first > N) continue;
				if (x.first > y.first) continue;
				f |= upd(opNode(x.first * y.first, x.second, y.second, '*'));
			}
			if (!f) break;
		}
		for (int iter = 0; ; ++ iter) {
			for (const auto &x : minRepr)
				upd(opNode(N, x.second, getRepr(N - x.first), '+'));
			if (iter == 1) break;
			xs.assign(minRepr.begin(), minRepr.end());
			sort(xs.begin(), xs.end(), [](const auto &x, const auto &y) { return x.second->len < y.second->len; });
			//cerr << "xs.size() = " << xs.size() << endl;
			bool f = false;
			for (const auto &x : xs) if(x.first <= N / 2) for (const auto &y : xs) {
				if (x.second->len + 1 + y.second->len >= best->len) break;
				if (x.first + y.first > N) continue;
				if (x.first > y.first) continue;
				f |= upd(opNode(x.first + y.first, x.second, y.second, '+'));
			}
			if (!f) break;
		}
		auto ans = best->toStr();
		puts(ans.c_str());
//		cerr << nNodes << ", " << (double)nNodes / nodes.size() << endl;
	}
}