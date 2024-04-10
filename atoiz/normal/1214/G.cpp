/*input
239 11 2
221 11 11
77 6 6
*/

// jklASDJKL;asjdkl;hADjkashdfjkladhfjklhAdJKLFHSDFJKLASHDJKLFHAJKLSDHFJKSDHsdjklaSDhaJKsDhjkASDHJKhsdkljhAsjklDHAjklsdhjklDhasjkdhjkaSDHKJSLHasjklaGFKlsdjhaDjkasdhjkhAsdkJhasdjklhklaSDHKLjHklaJsDHkjlhASDKJHaKLsDHkljASHDKJLhasdjklhaskljAsdhAsJKLdHklaJDHKJsdLDkljasdhkljasjhAsjklasdfasdfasdfasdfDHkLAJdHjklSdJhasdjklhaKLSDHKLjdjaHSDJKLgaQKAHLKfasdddddkAJDFKL;jdL;fJl;jKDAFKLJdKLJFl;jSdfl;sDFJkjdFL;fkjDLFK;Jsdl;DKjdfkl;KDFJLkJsDFL;jSdfkl;KsDFk;jSdfklJkl;fjFkl;dfjkl;asjdkl;fjaskl;dfjakl;sdjfkl;jl;skjfKL;JDFl;df;kjSD;KJZSKLFJA;LSDIJF;GJL;AKSJDGK;SD

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>
#include <tuple>

using namespace std;

#define ONE uint64_t(1)

int main() {
	int n, m, q, b;
	scanf("%d %d %d", &n, &m, &q);
	b = (m >> 6) + 1;

	vector<vector<uint64_t>> a(n, vector<uint64_t>(b, 0));
	vector<int> bits(n, 0);
	set<pair<int, int>> rows;
	for (int i = 0; i < n; ++i) rows.emplace_hint(rows.end(), 0, i);
	vector<uint64_t> bad((n >> 6) + 1, 0);

	auto calc_bad = [&](int x, int y) {
		bool flag = false;
		if (~y) {
			bool xy = false, yx = false;
			for (int i = 0; (!xy || !yx) && i < b; ++i) {
				uint64_t andSum = a[x][i] & a[y][i];
				if (a[x][i] != andSum) xy = true;
				if (a[y][i] != andSum) yx = true;
			}
			if (xy && yx) flag = true;
		}

		if (flag != ((bad[x >> 6] >> (x & 63)) & 1)) {
			bad[x >> 6] ^= ONE << (x & 63);
		}
		return flag;
	};

	auto get_bad = [&](int x, int y) {
		pair<int, int> ret(-1, -1);
		register uint64_t tmp;
		for (int i = 0; (ret.first == -1 || ret.second == -1) && i < b; ++i) {
			if (!~ret.first && (tmp = a[x][i] & (~a[y][i]))) {
				ret.first = (i << 6) | __builtin_ctzll(tmp);
			}
			if (!~ret.second && (tmp = a[y][i] & (~a[x][i]))) {
				ret.second = (i << 6) | __builtin_ctzll(tmp);
			}
		}
		assert(ret.first >= 0 && ret.first < m);
		assert(ret.second >= 0 && ret.second < m);
		return ret;
	};

	while (q--) {
		int p, l, r;
		scanf("%d %d %d", &p, &l, &r);
		--p, --l, --r;

		auto it = rows.find(make_pair(bits[p], p));
		if (it != rows.begin()) {
			calc_bad(prev(it)->second, (next(it) != rows.end()) ? next(it)->second : -1);
		}
		rows.erase(it);

		int popcount = 0;
		for (int i = 0; i < b; ++i) {
			int x = max(i << 6, l), y = min((i << 6) | 63, r);
			if (x <= y) a[p][i] ^= (ONE << (y & 63)) - (ONE << (x & 63)) + (ONE << (y & 63));
			popcount += __builtin_popcountll(a[p][i]);
		}
		bits[p] = popcount;

		it = rows.emplace(bits[p], p).first;
		if (it != rows.begin()) calc_bad(prev(it)->second, p);
		calc_bad(p, (next(it) != rows.end()) ? next(it)->second : -1);

		int x = -1;
		for (int i = 0; i <= (n >> 6); ++i) if (bad[i]) {
			x = (i << 6) | __builtin_ctzll(bad[i]);
			break;
		}

		if (x == -1) {
			puts("-1");
		} else {
			it = rows.find(make_pair(bits[x], x));
			assert(it != rows.end() && next(it) != rows.end());
			int y, z, t;
			y = next(it)->second;
			tie(z, t) = get_bad(x, y);
			if (x > y) swap(x, y);
			if (z > t) swap(z, t);

			assert(((a[x][z >> 6] >> (z & 63)) & 1) == ((a[y][t >> 6] >> (t & 63)) & 1));
			assert(((a[y][z >> 6] >> (z & 63)) & 1) == ((a[x][t >> 6] >> (t & 63)) & 1));
			assert(((a[y][z >> 6] >> (z & 63)) & 1) != ((a[y][t >> 6] >> (t & 63)) & 1));

			printf("%d %d %d %d\n", x + 1, z + 1, y + 1, t + 1);
		}
	}
}