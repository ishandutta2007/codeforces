#include <bits/stdc++.h>

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;
const int Sq = 333;
const int Inf = 1e9;

int n, q, a[N], ans[N];
int cnt[N], cnt2[N];

vector< pair<pii, int> > V;

int mk[N];
vector<int> T, Tp, T2;

void Add(int x, int del){
	cnt2[cnt[x]] --;
	cnt[x] += del;
	cnt2[cnt[x]] ++;
	if(!mk[cnt[x]]){ T.pb(cnt[x]), mk[cnt[x]] = 1; }
}

int C[N];
int A[N], B[N], pA = 0, pB = 0;

int Huffman(){
	int res = 0;
	int idx, d;
	for(auto &x : T){
		d = cnt2[x];
		idx = x;
		while(d){
			if(!C[idx]) T2.pb(idx);
			C[idx] += d;
			d = (C[idx] - 1) >> 1;
			C[idx] -= d << 1;
			idx <<= 1;
			res += idx * d;
		}
	}
	sort(all(T2));
	for(auto &x : T2){
		//cerr << x << ',' << C[x] << ' ';
		do { A[pA ++] = x; } while(-- C[x]);
	}
	//cerr << '\n';
	T2.clear();
	
	int fr, fr2, pa = 0, pb = 0, sz = pA + pB - 1;
	while(sz --){
		fr = (A[pa] <= B[pb] ? A[pa ++] : B[pb ++]);
		fr2 = (A[pa] <= B[pb] ? A[pa ++] : B[pb ++]);
		B[pB ++] = fr + fr2;
		res += fr + fr2;
	}
	while(pA) A[-- pA] = Inf;
	while(pB) B[-- pB] = Inf;
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	fill(A, A + N, Inf);
	fill(B, B + N, Inf);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	cin >> q;
	int l, r;
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		V.pb({{l, ++r}, i});
	}
	sort(all(V), [&](auto a, auto b){
		return pii(a.F.F / Sq, a.F.S) < pii(b.F.F / Sq, b.F.S);
	});

	l = 1; r = 1;
	for(auto &q : V){
		while(q.F.F < l) Add(a[-- l], 1);
		while(r < q.F.S) Add(a[r ++], 1);
		while(l < q.F.F) Add(a[l ++], -1);
		while(q.F.S < r) Add(a[-- r], -1);
		
		cnt2[0] = 0;
		Tp.clear();
		for(auto &x : T){
			if(cnt2[x]) Tp.pb(x);
			else mk[x] = 0;
		}
		T.swap(Tp);
		ans[q.S] = Huffman();
	}

	for(int i = 0; i < q; i++) cout << ans[i] << '\n';
	return 0;
}