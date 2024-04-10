#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXV = 1 << 14; 
const int SQRT = 450;

int N, K, Q;
int a[MAXN], b[MAXN], c[MAXN];
int zeroes, good;

struct rem {
	int id;
	vector <int> arr, bucket;
	vector < vector <short> > cnt;			
	
	void init(int x) {
		id = x;
		for (int i = 1; i < arr.size(); i++)
			arr[i] ^= arr[i - 1];
		
		bucket.resize((arr.size() + SQRT - 1) / SQRT);
		cnt.resize(bucket.size());
		
		if (K < SQRT) {
			for (auto &it : cnt)
				it.resize(MAXV);
			for (int i = 0; i < arr.size(); i++) 
				cnt[i / SQRT][arr[i]]++;
		}
	}
	
	void update(int pos, int val) {
		int nxt = min(pos + (SQRT - pos % SQRT) % SQRT, (int)arr.size());
		for (int i = pos; i < nxt; i++) {
			if (K < SQRT)
				cnt[pos / SQRT][arr[i]]--;
			arr[i] ^= val;
			if (K < SQRT)
				cnt[pos / SQRT][arr[i]]++;
		}
		for (int i = nxt; i < arr.size(); i += SQRT) 
			bucket[i / SQRT] ^= val;
	}
	
	int get() {
		int res = 0;
		if (K < SQRT)
			for (int i = 0; i < bucket.size(); i++)
				res += cnt[i][bucket[i]];
		else
			for (int i = 0; i < arr.size(); i++)
				res += !(arr[i] ^ bucket[i / K]);
		return res;
	}
	
	bool ok() {
		return N % K == id || arr.back() == bucket.back();
	}
};

rem r[MAXN];

void load() {
	scanf("%d%d%d", &N, &K, &Q);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	for (int i = 0; i < N; i++) 
		scanf("%d", b + i);
}

void modify(int pos, int val) {
	zeroes -= r[pos % K].get();
	good -= r[pos % K].ok();
	r[pos % K].update(pos / K, val);
	zeroes += r[pos % K].get();
	good += r[pos % K].ok();
}

int query() {
	return good < K ? -1 : N - zeroes;
}

void solve() {
	for (int i = 0; i < N; i++)
		c[i] = a[i] ^ b[i];
		
	for (int i = N - 1; i; i--)
		c[i] ^= c[i - 1];
	
	for (int i = 0; i < N; i++)
		r[i % K].arr.push_back(c[i]);
	
	for (int i = 0; i < K; i++)
		r[i].init(i);
	
	for (int i = 0; i < K; i++) {
		zeroes += r[i].get();
		good += r[i].ok();
	}
		
	printf("%d\n", query());
	while (Q--) {
		char w;
		int p, v;
		scanf(" %c%d%d", &w, &p, &v);
		p--;
		int delta = 0;
		if (w == 'a') {
			delta = a[p] ^ v;
			a[p] = v;
		}
		else {
			delta = b[p] ^ v;
			b[p] = v;
		}
		modify(p, delta);
		if (p < N - 1) 
			modify(p + 1, delta);
		printf("%d\n", query());
	}
}

int main() {
	load();
	solve();
	return 0;
}