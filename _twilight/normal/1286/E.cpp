#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 6e5 + 5;
const int bzmax = 21;

#define pii pair<int, int>

#define ll long long
#define ull unsigned long long

const ull base = 1e18;

typedef class int128_t {
	public:
		ull h, l;

		int128_t() : h(0), l(0) {	}
		int128_t(ull x) : h(0), l(x) {	}
		int128_t(ull h, ull l) : h(h), l(l) {	}

		friend int128_t operator + (int128_t a, int128_t b) {
			ull s = a.l + b.l;
			(s >= base) && (s -= base, a.h++);
			return int128_t(a.h + b.h, s);
		}
		void print() {
			if (h) {
				printf("%llu%018llu\n", h, l);
			} else {
				printf("%llu\n", l);
			}
		} 	
} int128_t;

#define log2 Log2

int n;
int R;
char s[N];
int log2[N];

ll dans = 0;

typedef class Group {
	public:
		int fr, frv;
		vector<int> a;
		vector<pii> v;

		Group() : fr(0), frv(0) {	}

		boolean check(int l) {
			return s[R] == s[l + R];
		}
		void pop_vfront() {
			v[frv].second--;
			if (!v[frv].second)
					frv++;
		}
		void pop_vback() {
			v.back().second--;
			if (!v.back().second)
				v.pop_back();
		}
		void update(int nv) {
			while (fr < (signed) a.size() && !check(a[fr])) {
				dans -= v[frv].first;
				fr++, pop_vfront();
			}
			while (fr < (signed) a.size() && !check(a.back())) {
				dans -= v.back().first;
				a.pop_back(), pop_vback();
			}
			int cnt = 0;
			while (frv < (signed) v.size() && v.back().first >= nv) {
				cnt += v.back().second;
				dans -= 1ll * v.back().second * v.back().first;
				v.pop_back();
			}
			if (cnt) {
				v.emplace_back(nv, cnt);
				dans += 1ll * nv * cnt;
			}
		}
		int first() {
			return (fr < (signed) a.size()) ? (a[fr] + R) : (-1);
		}
		int firstv() {
			return v[frv].first;
		}
		void pop_front() {
			fr++;
			pop_vfront();
		}
		void push_back(int L, int nv) {
			a.push_back(L -= R);
			v.emplace_back(nv, 1);
		}

		void log() {
			for (int i = fr; i < (signed) a.size(); i++) {
				cerr << a[i] + R << ' ';
			}
			cerr << '\n';
		}
} Group;

Group gp[bzmax];

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d", &n);
	log2[0] = -1;
	int lastans = 0, w;
	int128_t ans = 0;
	for (R = 1; R <= n; R++) {
		log2[R] = log2[R >> 1] + 1;
		scanf("%s%d", s + R, &w);
		s[R] = (s[R] - 'a' + ans.h % 26 * (base % 26) + ans.l % 26) % 26 + 'a';
		w ^= lastans;
//		cerr << "rw: " << w << '\n';
		for (int i = 0; i < log2[R]; i++) {
			int L = gp[i].first();
			if (L != -1 && Log2[L] != i) {
				int v = gp[i].firstv();
				gp[i].pop_front();
				gp[i + 1].push_back(L, v);
			}
		}
		gp[0].push_back(1, w);
		dans += w;
		for (int i = 0; i <= log2[R]; i++) {
			gp[i].update(w);
//			gp[i].log();
		}
		ans = ans + dans;
		lastans = (ans.h * (base & ((1 << 30) - 1)) + ans.l) & ((1 << 30) - 1);
		ans.print();
//		cerr << s + 1 << '\n';
	}
	return 0;
}