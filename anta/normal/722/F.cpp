#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }

template<typename T>
vector<pair<T, int> > runLength(const T a[], int n) {
	vector<pair<T, int> > r;
	if(n <= 0) return r;
	int cnt = 0;
	for(int i = 0; i <= n; i ++) {
		if(i == n || (i != 0 && a[i] != a[i - 1])) {
			r.push_back(make_pair(a[i - 1], cnt));
			cnt = 0;
		}
		cnt ++;
	}
	return r;
}
struct Factor {
	int pi;
	int q;
	ll mask;
};
int main() {
	int n; int m;
	mt19937 re;
	while(~scanf("%d%d", &n, &m)) {
		const int K = 40;
		vector<vi> seqs(n);
		rep(i, n) {
			int k;
			scanf("%d", &k);
			seqs[i].resize(k);
			rep(j, k)
				scanf("%d", &seqs[i][j]);
		}
		int P = K;
		vector<vector<Factor>> factors(K + 1);
		rer(k, 1, K) {
			rep(pi, P) {
				int p = (pi + 1);
				int q = p;
				if(gcd(k, q) == 1) continue;
				ll mask = 0;
				for(int i = 0; ; ) {
					mask |= 1LL << i;
					(i += k) %= p;
					if(i == 0) break;
				}
				factors[k].push_back(Factor{ pi, q, mask });
			}
		}
		vector<vi> occurs(m + 1);
		vector<bool> vis(m + 1);
		rep(i, n) {
			for(int a : seqs[i]) if(!vis[a]) {
				vis[a] = true;
				occurs[a].push_back(i);
			}
			for(int a : seqs[i])
				vis[a] = false;
		}

		vi indices;
		vector<vector<ll>> masks(P);
		rer(a, 1, m) {
			rep(pi, P) {
				masks[pi].clear();
				masks[pi].resize(occurs[a].size());
			}
			rep(oi, occurs[a].size()) {
				int i = occurs[a][oi];
				int k = seqs[i].size();
				indices.clear();
				rep(t, k) if(seqs[i][t] == a)
					indices.push_back(t);
				assert(!indices.empty());
				rep(pi, P)
					masks[pi][oi] = (1LL << (pi + 1)) - 1;
				for(auto f : factors[k]) {
					int pi = f.pi, p = pi + 1, q = f.q;
					ll mask = f.mask;
					ll total = 0;
					for(int t : indices) {
						total |= mask << (t % q);
						if(t % q != 0)
							total |= mask >> (q - t % q);
					}
					masks[pi][oi] = total;
				}
			}
			vi pows(P);
			rep(pi, P)pows[pi] = pi + 1;
			int ans = 0;
			vector<vi> bits(P);
			rep(pi, P) bits[pi].assign(pows[pi], 0);
			vector<int> zeros(P, 0);
			for(int L = 0, R = 0; L != occurs[a].size(); ++ L) {
				for(; R != occurs[a].size() && occurs[a][R] == occurs[a][L] + (R - L); ++ R) {
					bool ok = true;
					rep(pi, P) {
						ll mask = masks[pi][R];
						if(mask == (1LL << pows[pi]) - 1) continue;
						int z = 0;
						rep(qi, pows[pi]) {
							if((mask >> qi & 1) == 0)
								z += bits[pi][qi] == 0;
						}
						if(zeros[pi] + z == pows[pi]) {
							ok = false;
							break;
						}
					}
					if(!ok) break;
					rep(pi, P) {
						ll mask = masks[pi][R];
						if(mask == (1LL << pows[pi]) - 1) continue;
						int z = 0;
						rep(qi, pows[pi]) {
							if((mask >> qi & 1) == 0)
								z += ++ bits[pi][qi] == 1;
						}
						zeros[pi] += z;
					}
				}
				//cerr << a << ": " << occurs[a][L] << ", " << occurs[a][R - 1] << endl;
				amax(ans, R - L);
				rep(pi, P) {
					ll mask = masks[pi][L];
					if(mask == (1LL << pows[pi]) - 1) continue;
					int z = 0;
					rep(qi, pows[pi]) {
						if((mask >> qi & 1) == 0)
							z += -- bits[pi][qi] == 0;
					}
					zeros[pi] -= z;
				}
			}


			printf("%d\n", ans);
		}
	}
	return 0;
}