#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
using namespace std;
#define int long long
int MOD = 1000000007;
class SA_IS
{
private:
	using byte = unsigned char;
	byte mask[8] = { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 };
#define tget(i) !!(t[(i)>>3]&mask[(i)&7])
#define tset(i, b) t[(i)>>3]=(b) ? (mask[(i)&7]|t[(i)>>3]) : ((~mask[(i)&7])&t[(i)>>3])
#define chr(i) (cs==sizeof(int)?((int*)s)[i]:((byte *)s)[i])
#define isLMS(i) (i>0 && tget(i) && !tget(i-1))
	void getBuckets(byte *s, int *bkt, int n, int K, int cs, bool end = true) {
		fill(bkt, bkt + K + 1, 0);
		for (int i = 0; i < n; i++) {
			bkt[chr(i)]++;
		}
		for (int i = 0, tmp = 0; i < K + 1; i++) {
			tmp += bkt[i];
			bkt[i] = end ? tmp : tmp - bkt[i];
		}
	}
	void induceSAl(byte *t, byte *s, int *bkt, int n, int K, int cs) {
		getBuckets(s, bkt, n, K, cs, false);
		for (int i = 0; i < n; i++) {
			if (sa[i]>0 && !tget(sa[i] - 1)) {
				sa[bkt[chr(sa[i] - 1)]++] = sa[i] - 1;
			}
		}
	}
	void induceSAs(byte *t, byte *s, int *bkt, int n, int K, int cs) {
		getBuckets(s, bkt, n, K, cs, true);
		for (int i = n - 1; i >= 0; i--) {
			if (sa[i] > 0 && tget(sa[i] - 1)) {
				sa[--bkt[chr(sa[i] - 1)]] = sa[i] - 1;
			}
		}
	}
	void make_sa(byte *s, int n, int K = 128, int cs = 1) {
		byte t[(n >> 3) + 1];
		int bkt[K + 1], n1 = 0, name = 0;
		tset(n - 2, 0), tset(n - 1, 1);
		for (int i = n - 3; i >= 0; i--) {
			tset(i, (chr(i)<chr(i + 1) || (chr(i) == chr(i + 1) && tget(i + 1))));
		}
		getBuckets(s, bkt, n, K, cs);
		fill(sa, sa + n, -1);
		for (int i = 1; i < n; i++) {
			if (isLMS(i)) {
				sa[--bkt[chr(i)]] = i;
			}
		}
		induceSAl(t, s, bkt, n, K, cs);
		induceSAs(t, s, bkt, n, K, cs);
		for (int i = 0; i < n; i++) {
			if (isLMS(sa[i])) {
				sa[n1++] = sa[i];
			}
		}
		fill(sa + n1, sa + n, -1);
		for (int i = 0, tmp = -1; i < n1; i++) {
			int pos = sa[i], diff = false;
			for (int d = 0; d < n && !diff; d++) {
				diff = chr(pos + d) != chr(tmp + d) || tget(pos + d) != tget(tmp + d);
				if (!diff && d && (isLMS(pos + d) || isLMS(tmp + d))) break;
			}
			if (diff) {
				name++, tmp = pos;
			}
			sa[n1 + ((pos - (pos & 1)) >> 1)] = name - 1;
		}
		int* s1 = sa + n - n1;
		for (int i = n - 1, j = n - 1; i >= n1; i--) {
			if (sa[i] >= 0) {
				sa[j--] = sa[i];
			}
		}
		if (name < n1) {
			make_sa((byte*)s1, n1, name - 1, sizeof(int));
		}
		else {
			for (int i = 0; i < n1; i++) {
				sa[s1[i]] = i;
			}
		}
		getBuckets(s, bkt, n, K, cs);
		for (int i = 1, j = 0; i < n; i++) {
			if (isLMS(i)) {
				s1[j++] = i;
			}
		}
		for (int i = 0; i < n1; i++) {
			sa[i] = s1[sa[i]];
		}
		fill(sa + n1, sa + n, -1);
		for (int i = n1 - 1; i >= 0; i--) {
			int tmp = sa[i];
			sa[i] = -1, sa[--bkt[chr(tmp)]] = tmp;
		}
		induceSAl(t, s, bkt, n, K, cs);
		induceSAs(t, s, bkt, n, K, cs);
	}
	void make_lcp() {
		lcp = new int[sz + 1];
		rnk = new int[sz + 1];
		for (int i = 0; i <= sz; i++) {
			rnk[sa[i]] = i;
		}
		for (int i = 0, h = 0; i <= sz; i++) {
			if (rnk[i] < sz) {
				for (int j = sa[rnk[i] + 1]; CS[i + h] == CS[j + h]; h++);
				lcp[rnk[i]] = h;
				if (h > 0) --h;
			}
		}
	}
public:
	bool contain(const string& T) {
		int a = 0, b = sz;
		while (b - a > 1) {
			int c = (a + b) / 2;
			if (CS.compare(sa[c], T.length(), T) < 0) {
				a = c;
			}
			else {
				b = c;
			}
		}
		return CS.compare(sa[b], T.length(), T) == 0;
	}
	string CS;
	byte* S;
	int sz;
	int *sa, *lcp, *rnk;
	SA_IS(string& arg) {
		CS = arg;
		sz = (int)arg.size();
		sa = new int[sz + 1];
		S = (byte*)arg.c_str();
		make_sa(S, sz + 1);
		make_lcp();
	}
	~SA_IS() {
		delete[] sa;
		// delete[] lcp; delete[] rnk;
	}
};

// call RMQ = buildRMQ(lcp, n+1)
int *buildRMQ(int *a, int n) {
	int logn = 1;
	for (int k = 1; k < n; k *= 2) ++logn;
	int *r = new int[n * logn];
	int *b = r; copy(a, a + n, b);
	for (int k = 1; k < n; k *= 2) {
		copy(b, b + n, b + n); b += n;
		REP(i, n - k) b[i] = min(b[i], b[i + k]);
	}
	return r;
}
// inner LCP computation with RMQ: O(1)
int minimum(int x, int y, int *rmq, int n) {
	if (x > y)swap(x, y);
	y--;
	//cout << x << " " << y << endl;
	int z = y - x, k = 0, e = 1, s; // y - x >= e = 2^k  k
	s = ((z & 0xffff0000) != 0) << 4; z >>= s; e <<= s; k |= s;
	s = ((z & 0x0000ff00) != 0) << 3; z >>= s; e <<= s; k |= s;
	s = ((z & 0x000000f0) != 0) << 2; z >>= s; e <<= s; k |= s;
	s = ((z & 0x0000000c) != 0) << 1; z >>= s; e <<= s; k |= s;
	s = ((z & 0x00000002) != 0) << 0; z >>= s; e <<= s; k |= s;
	return min(rmq[x + n*k], rmq[y + n*k - e + 1]);
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string S;
	string T;
	cin >> S;
	cin >> T;
	//S = string(10, '0');
	//S += string(10, '1');
	//T = string((int)1e6, 'a');
	//T="ABCBC";
	int N = S.size();
	int M = T.size();
	SA_IS sa_is(T);
	int *RMQ = buildRMQ(sa_is.lcp, (int)T.size() + 1);
	vector<int> rev(M);
	for (int i = 1; i <= M; i++) {
		rev[sa_is.sa[i]] = i;
	}
	/*for (int i = 0; i <= M; i++) {
	cout << i << " ";
	}
	cout << endl;
	for (int i = 1; i <= M; i++) {
	cout << sa_is.lcp[i] << " ";
	}
	cout << endl;

	cout << minimum(rev[1], rev[3], RMQ, T.size() + 1) << endl;
	cout << minimum(rev[1], rev[1], RMQ, T.size() + 1) << endl;*/
	//cerr << N << " " << M << endl;
	int zero = 0;
	int one = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '0')zero++;
		else one++;
	}
	int b; int t;
	string A, B;
	int res = 0;
	for (int a = 1; a <= M; a++) {
		t = M - a*zero;
		if (t <= 0)break;
		if (t % one != 0)continue;
		b = t / one;

		int cur = 0;
		bool ok = true;
		int astart = -1;
		int bstart = -1;
		for (int i = 0; i < N; i++) {
			if (S[i] == '0') {
				if (astart == -1) {
					astart = cur;
				}
				else {
					if (minimum(rev[astart], rev[cur], RMQ, (int)T.size() + 1) < a) {
						ok = false;
						break;
					}
				}
				cur += a;
			}
			else {
				if (bstart == -1) {
					bstart = cur;
				}
				else {
					if (minimum(rev[bstart], rev[cur], RMQ, (int)T.size() + 1) < b) {
						ok = false;
						break;
					}
				}
				cur += b;
			}
		}
		if (a == b && minimum(rev[astart], rev[bstart], RMQ, (int)T.size() + 1) >= a){
		    ok = false;
		}
		if (ok) res++;

	}

	cout << res << endl;
}