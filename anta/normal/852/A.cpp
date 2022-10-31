#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

struct SplitSum {
	vector<bool> split;
	int sum;
	const string &S;
	SplitSum(const string &S) : split(S.size() - 1, true), sum(0), S(S) {
		for (char c : S) sum += c - '0';
	}
	void unite(int i) {
		int j = i - 1;
		int a = S[i] - '0', p = 10;
		for (; j >= 0 && !split[j]; -- j) {
			a += p * (S[j] - '0');
			p *= 10;
		}
		int k = i + 1;
		int q = 10;
		for (; k != split.size() && !split[k]; ++ k)
			q *= 10;
		split[i] = false;
		sum -= a;
		sum += a * q;
	}
};

int main() {
	const int NN = 3000000;
	vector<int> minNum(NN + 1, INF);
	vector<vector<bool>> splits(NN + 1);
	if (1) {
		mt19937 re;
		rep(x, 10)
			minNum[x] = 0;
		int threes = 0;
		rer(n, 10, NN) {
			string S = to_string(n);
			int x = INF;
			if (n >= 200000) {
				int sum = 0;
				for (char c : S)
					sum += c - '0';
				splits[n] = vector<bool>(S.size()-1,true);
				amin(x, minNum[sum] + 1);
			} else {
				vi perm(S.size() - 1);
				iota(perm.begin(), perm.end(), 0);
				rep(kk, n <= 1000 ? 10 : 1) {
					SplitSum ss(S);
					shuffle(perm.begin(), perm.end(), re);
					rep(t, S.size() - 1) {
						int y = 1 + minNum[ss.sum];
						if (x > y) {
							splits[n] = ss.split;
							x = y;
						}
						ss.unite(perm[t]);
						if (n >= 1000 && x < 3) break;
					}
					if (n >= 1000 && x < 3) break;
				}
			}
			if (x >= 3) {
				if (x > 3)
					cerr << n << ": " << x << endl;
				++ threes;
			}
			minNum[n] = x;
		}
		//cerr << "threes = " << threes << endl;
	}
	int N;
	mt19937 re;
	while (~scanf("%d", &N)) {
		char buf[200001];
		scanf("%s", buf);
		string S = buf;
		vi perm(S.size() - 1);
		iota(perm.begin(), perm.end(), 0);
		bool ok = false;
		rep(kk, 100) {
			SplitSum ss(S);
			shuffle(perm.begin(), perm.end(), re);
			rep(t, S.size()) {
				if (ss.sum <= NN && minNum[ss.sum] < 3) {
					auto split = ss.split;
					rep(tt, 3) {
						string T;
						int ssum = 0, aa = 0;
						rep(i, S.size()) {
							T += S[i];
							aa = aa * 10 + (S[i] - '0');
							if (i == S.size() - 1 || split[i]) {
								ssum += aa;
								aa = 0;
							}
							if (i != S.size() - 1 && split[i])
								T += '+';
						}
						puts(T.c_str());
						split = splits[ssum];
						S = to_string(ssum);
					}
					assert(S.size() == 1);
					ok = true;
					break;
				}
				if(t!=S.size()-1)
					ss.unite(perm[t]);
			}
			if (ok) break;
		}
		if (!ok) {
			cerr << "not ok" << endl;
			abort();
		}
	}
	return 0;
}