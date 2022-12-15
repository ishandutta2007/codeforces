#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>

using namespace std;
typedef long long ll;
const int INF = 987654321;
const ll LINF = 1e15;

const int N_ = 100005;
const int BSZ = 350;

int N;
ll Bucket[BSZ+5][BSZ*2+5]; int Org[BSZ+5][BSZ*2+5], Where[N_];
ll Dist[BSZ+5], Sum[BSZ+5]; int Length[BSZ+5];

void calcSum (int b) {
	Dist[b] = Sum[b] = 0;
	for(int i = 1; i <= Length[b]; i++) {
		int mul = Length[b] - 1 - 2 * (Length[b] - i); 
		Dist[b] += Bucket[b][i] * mul;
		Sum[b] += Bucket[b][i];
	}
}

void reorder() { 
	int i, j, pos = 0; 
	vector<ll> A; A.reserve(N);
	vector<int> O; O.reserve(N);

	for(i = 1; i <= BSZ; i++) {
		for(j = 1; j <= Length[i]; j++) A.push_back(Bucket[i][j]), O.push_back(Org[i][j]);
		Length[i] = 0;
	}
	for(i = 1; i <= BSZ; i++) {
		Length[i] = max(min(BSZ, N - BSZ * (i - 1)), 0);
		for(j = 1; j <= Length[i]; j++) {
			Bucket[i][j] = A[pos];
			Org[i][j] = O[pos]; Where[O[pos]] = i;
			++pos;
		}
		calcSum(i);
	}
}

void searchPositionbyP (int p, int &b, int &w) {
	b = Where[p];
	for(w = 1; w <= Length[b]; w++) {
		if(Org[b][w] == p) return;
	}
}

void searchPositionbyX (ll p, int &b, int &w) {
	for(b = 1; b <= BSZ; b++) {
		if(Length[b] > 0 && Bucket[b][Length[b]] >= p) break;
	}
	b = min(b, BSZ);
	for(w = 1; w <= Length[b]; w++) {
		if(Bucket[b][w] >= p) break;
	}
}

int D[N_], Ord[N_], OrdI[N_];
bool cmpOrd (const int &a, const int &b) { return D[a] < D[b]; }

int main() {
	int i, j, k;

	scanf("%d", &N);
	for(i = 1; i <= N; i++) scanf("%d", &D[i]), Ord[i] = i;
	sort(Ord + 1, Ord + N + 1, cmpOrd);
	for(i = j = 1; i <= N; i++) {
		int &o = Ord[i]; 
		Bucket[j][++Length[j]] = D[o];
		Org[j][Length[j]] = o;
		if(Length[j] == BSZ) ++j;
	}

	reorder();

	int Q, S = 0; scanf("%d", &Q);
	while(Q--) {
		int t; scanf("%d", &t);
		if(t == 1) {
			int p; ll d;
			scanf("%d%I64d", &p, &d);

			int pb, pw, rb, rw; 

			searchPositionbyP (p, pb, pw); ll rd = Bucket[pb][pw] + d;
			for(i = pw; i < Length[pb]; i++) Bucket[pb][i] = Bucket[pb][i + 1], Org[pb][i] = Org[pb][i + 1];
			Bucket[pb][Length[pb]--] = 0; calcSum(pb);

			searchPositionbyX (rd, rb, rw);
			for(i = ++Length[rb]; i > rw; i--) Bucket[rb][i] = Bucket[rb][i - 1], Org[rb][i] = Org[rb][i - 1];
			Bucket[rb][rw] = rd; Org[rb][rw] = p; calcSum(rb);
			if(rw != Length[rb])assert(Bucket[rb][rw] < Bucket[rb][rw + 1]);

			Where[p] = rb;

			if(++S == BSZ){
				S = 0; reorder();
			}
		}else {
			ll l, r; scanf("%I64d%I64d", &l, &r);

			int lb, lw, rb, rw;
			searchPositionbyX (l, lb, lw); if(l > Bucket[lb][lw]) { puts("0"); continue; }
			searchPositionbyX (r, rb, rw); rw = min(rw, Length[rb]); 
			while(Bucket[rb][rw] > r && rw > 0) --rw;
			while((rw == 0 || Bucket[rb][rw] > r) && rb > 0) rw = Length[--rb];
			if(rb == 0 || Bucket[lb][lw] > Bucket[rb][rw]) { puts("0"); continue; }
			assert(Bucket[rb][rw] <= r);

			ll ret = 0; int v;

			if(lb == rb) {
				vector<ll> A;
				for(i = lw; i <= rw; i++) A.push_back(Bucket[lb][i]);
				for(i = 0; i < A.size(); i++) {
					int mul = (int)A.size() - 1 - 2 * ((int)A.size() - i - 1); 
					ret += A[i] * mul;
				}
			}else {
				vector<ll> A; ll PL = 0, PS = 0;
				for(i = lw; i <= Length[lb]; i++) A.push_back(Bucket[lb][i]), ++PS, PL -= Bucket[lb][i]; 
				for(i = 1; i <= rw; i++) A.push_back(Bucket[rb][i]), --PS, PL += Bucket[rb][i];

				for(i = lb + 1; i <= rb - 1; i++) {
					ret += Dist[i] + Sum[i] * PS + Length[i] * PL; 
					PS += Length[i]; PL -= Sum[i];
				}

				for(i = 0; i < A.size(); i++) {
					int mul = (int)A.size() - 1 - 2 * ((int)A.size() - i - 1); 
					ret += A[i] * mul;
				}
			}
			printf("%I64d\n", ret);
		}

	}
	return 0;
}