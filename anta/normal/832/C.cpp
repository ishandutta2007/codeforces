#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }


struct LinearPoly {
	typedef double Coef;
	Coef a, b;
	LinearPoly() { }
	LinearPoly(Coef a_, Coef b_) : a(a_), b(b_) { }
	bool operator<(const LinearPoly &that) const {
		return a != that.a ? a < that.a : b > that.b;
	}
	Coef evaluate(Coef x) const {
		return a * x + b;
	}
	Coef ceil_crosspoint(const LinearPoly &that) const {
		assert(a != that.a);
		Coef num = that.b - b;
		Coef den = a - that.a;
		return num / den;
	}
};
typedef LinearPoly EnvelopeFunc;
typedef EnvelopeFunc::Coef EnvelopeCoef;
typedef vector<pair<EnvelopeCoef, EnvelopeFunc> > Envelope;

//lines
void makeEnvelope(const vector<EnvelopeFunc> &points, Envelope &stk) {
	stk.clear();
	for (auto p : points) {
		if (!stk.empty() && p.a == stk.back().second.a)
			continue;
		for (; !stk.empty(); stk.pop_back()) {
			auto x = stk.back().first;
			if (p.evaluate(x) <= stk.back().second.evaluate(x))
				break;
		}
		auto x = stk.empty() ? 0 : stk.back().second.ceil_crosspoint(p);
		assert(x >= 0);
		stk.emplace_back(x, p);
	}
}
struct SearchEnvelopePred {
	bool operator()(const pair<EnvelopeCoef, EnvelopeFunc> &p, const pair<EnvelopeCoef, EnvelopeFunc> &q) const {
		return p.first < q.first;
	}
};

EnvelopeCoef searchEnvelope(EnvelopeCoef x, const Envelope &envelope) {
	int l = 0, u = (int)envelope.size() - 1;
	while (u - l > 0) {
		int mid = (l + u + 1) / 2;
		if (envelope[mid].first <= x)
			l = mid;
		else
			u = mid - 1;
	}
	return envelope[l].second.evaluate(x);
}


struct Person {
	double xL, xR;
	double a, b;
	double c;
	bool operator<(const Person &that) const { return xL < that.xL; }
};

int main() {
	int n; int s;
	while (~scanf("%d%d", &n, &s)) {
		const int X = 1000000;
		//(x - m) / (v - s) + (X - x - (x - m) v / (v - s)) / (v + s)
		//((x - m) s / (v - s) + X - x) / (v + s)
		vector<Person> people[2];
		rep(i, n) {
			int x; int v; int t;
			scanf("%d%d%d", &x, &v, &t);
			if (t == 2)
				x = X - x;
			double b = x * 1. / (v + s);
			double a = s * 1. / (s - v) / (v + s);
			b -= a * x;
			double c = x * 1. / v;
			//(m - x) / (s - v) = c
			double xR = (c + x * 1. / (s - v)) * (s - v);
			people[t - 1].push_back(Person{ (double)x, xR, a, b, c });
		}
		auto solve = [X](vector<Person> people) -> vector<double> {
			sort(people.begin(), people.end());
			int logn = 1;
			for (; 1 << logn <= X; ++ logn);
			int nNodes = 1 << logn;
			vector<pair<vector<LinearPoly>,Envelope>> nodes(nNodes * 2);
			double minC = numeric_limits<double>::infinity();
			for (auto p : people) {
				amin(minC, p.c);
				int l = (int)ceil(p.xL);
				int r = (int)min(ceil(p.xR + 1e-9), (double)X + 1);
				for (l += nNodes, r += nNodes; l < r; l >>= 1, r >>= 1) {
					if (l & 1) nodes[l ++].first.emplace_back(-p.a, -p.b);
					if (r & 1) nodes[-- r].first.emplace_back(-p.a, -p.b);
				}
			}
			for (auto &v : nodes) if (!v.first.empty()) {
				sort(v.first.begin(), v.first.end());
				makeEnvelope(v.first, v.second);
			}
			vector<double> res(X + 1);
			rer(m, 0, X) {
				double minT = minC;
				for (int i = m + nNodes; i > 0; i >>= 1) if(!nodes[i].first.empty())
					amin(minT, -searchEnvelope(m, nodes[i].second));
				res[m] = minT;
			}
			return res;
		};
		vector<double> table(X + 1);
		rep(k, 2) {
			auto v = solve(people[k]);
			if (k == 1)
				reverse(v.begin(), v.end());
			rep(m, X + 1)
				amax(table[m], v[m]);
		}
		double ans = *min_element(table.begin(), table.end());
		printf("%.10f\n", ans);
	}
	return 0;
}