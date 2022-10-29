#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ull unsigned long long

const int N = 2e5 + 5;

template <typename T>
T smax(T a) {
	return a;
}
template <typename T, typename ...K>
T smax(T a, K ...args) {
	return max(a, smax(args...));
}
template <typename T>
T smin(T a) {
	return a;
}
template <typename T, typename ...K>
T smin(T a, K ...args) {
	return min(a, smin(args...));
}

int n, m;
ull f[8];
ull A, B, C;
boolean vis[N];
vector<int> G[N];
vector<int> P, idx;

ull C2(ull x) {
	return (x & 1) ? (x * ((x - 1) >> 1)) : ((x >> 1) * (x - 1));
}

void work(int a, int b, int c) {
	int mx = smax(a, b, c);
	int mi = smin(a, b, c);
	int sec = a + b + c - mi - mx;
	f[7] += mi * A + sec * B + mx * C;
}

int main() {
	scanf("%d%d", &n, &m);
	scanf("%llu%llu%llu", &A, &B, &C);
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
		if (u > v)
			swap(u, v);
		f[1] += (A * u + B * v) * (n - 1 - v) + C * (C2(n) - C2(v + 1));
		f[2] += (A * u + C * v) * (v - u - 1) + B * (C2(v) - C2(u + 1));
		f[4] += (B * u + C * v) * u + A * C2(u);
	}
	for (int i = 0; i < n; i++) {
		if (i < n - 2)
			f[0] += A * i * C2(n - i - 1);
		if (i > 0 && i < n - 1)
			f[0] += B * i * i * (n - i - 1);
		if (i > 1)
			f[0] += C * i * C2(i);
	}
	for (int i = 0; i < n; i++) 
		sort(G[i].begin(), G[i].end(), greater<int>());
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		ull sum = 0;
		for (auto p : G[i]) {
			if (p < i) break;
			f[3] += (A * i + B * p) * cnt + sum * C;
			cnt++, sum += p;
		}
	}
	for (int i = 0; i < n; i++)
		reverse(G[i].begin(), G[i].end());
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		ull sum = 0;
		for (auto p : G[i]) {
			if (p > i) break;
			f[6] += (B * p + C * i) * cnt + sum * A;
			cnt++, sum += p;
		}
	}
	for (int i = 0; i < n; i++) {
		int cntl = 0, cntr = 0;
		ull suml = 0, sumr = 0;
		for (auto p : G[i]) {
			if (p < i) {
				cntl++;
				suml += p;
			} else {
				cntr++;
				sumr += p;
			}
		}
		f[5] += 1ull * i * B * cntl * cntr + suml * A * cntr + sumr * C * cntl;
	}
	P.resize(n);
	for (int i = 0; i < n; i++)
		P[i] = i;
	idx.resize(n);
	sort(P.begin(), P.end(), [&] (const int a, const int b) {	return G[a].size() < G[b].size();	});
	for (int i = 0; i < n; i++)
		idx[P[i]] = i;
	for (int i = 0; i < n; i++)
		sort(G[i].begin(), G[i].end(), [&] (const int a, const int b) {	return idx[a] > idx[b];	});
	for (auto x : P) {
		for (auto y : G[x]) {
			if (idx[x] < idx[y])
				continue;
			for (auto z : G[y]) {	
				if (idx[z] < idx[y])
					break;
				if (vis[z]) {
					work(x, y, z);
//					cerr << x << " " << y << " " << z << '\n';
				}
			}
			vis[y] = true;
		}
		for (auto y : G[x]) {
			vis[y] = false;
		}
	}
//	for (int i = 0; i < 8; i++)
//		cerr << f[i] << " ";
//	cerr << '\n';
	ull ans = f[0] - f[1] - f[2] + f[3] - f[4] + f[5] + f[6] - f[7];
	printf("%llu\n", ans);
	return 0;
}