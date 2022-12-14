#include <bits/stdc++.h>

using namespace std;
using lint = long long;

const int N_ = int(1.1e5);
int N;
lint L[N_];


class SegmentTree{
	lint tree[530000], lazy[530000];
	void init(int s, int e, int p, int *x){
		if(s == e){
			tree[p] = x[s];
			return;
		}
		int m = (s+e)/2;
		init(s, m, 2*p, x);
		init(m+1, e, 2*p+1, x);
		tree[p] = min(tree[2*p], tree[2*p+1]);
	}
	void lazydown(int p){
		tree[2*p] += lazy[p];
		tree[2*p+1] += lazy[p];
		lazy[2*p] += lazy[p];
		lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	void add(int s, int e, int ps, int pe, int p, lint v){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			tree[p] += v;
			lazy[p] += v;
			return;
		}
		lazydown(p);
		int pm = (ps + pe) / 2;
		add(s, e, ps, pm, 2*p, v);
		add(s, e, pm+1, pe, 2*p+1, v);
		tree[p] = min(tree[2*p], tree[2*p+1]);
	}
	lint query(int s, int e, int ps, int pe, int p){
		if(e < ps || pe < s) return 1e18;
		if(s <= ps && pe <= e) return tree[p];
		lazydown(p);
		int pm = (ps + pe) / 2;
		return min(query(s, e, ps, pm, 2*p), query(s, e, pm+1, pe, 2*p+1));
	}
public:
  void add(int s, int e, lint v) {
    add(s, e, 1, N, 1, v);
  }
  lint query(int s, int e) {
    return query(s, e, 1, N, 1);
  }
}seg;

char S[int(1.1e5)];

const char GRASS = 'G',WATER = 'W', LAVA = 'L';
const int WALK = 5, SWIM = 3, FLY = 1;

lint ans;

int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    scanf("%lld", &L[i]);
    L[i] *= 2;
  }
  scanf("%s", S+1);

  lint stamina = 0;
  for(int i = 1, g = -1, w = -1; i <= N; i++) {
    if(S[i] == GRASS) {
      stamina += L[i];
      if(g < 0) g = i;
    }else if(S[i] == WATER) {
      stamina += L[i];
      if(w < 0) w = i;
    }else {
      stamina -= L[i];
      if(stamina < 0) {
        // G/W stamina  
        lint how_much = -stamina;
        stamina += how_much;
        if(w > 0) {
          L[w] += how_much;
        }else if(g > 0) {
          L[g] += how_much;
        }
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    if(S[i] == GRASS){
      seg.add(i, N, +L[i]);
      ans += L[i] * WALK;
    }else if(S[i] == WATER) {
      seg.add(i, N, +L[i]);
      ans += L[i] * SWIM;
    }else {
      seg.add(i, N, -L[i]);
      ans += L[i] * FLY;
    }
  }


  for(int i = N; i > 0; i--) {
    if(S[i] == GRASS) {
      // fly  fly 
      lint how_much = min(seg.query(i, N) / 2, L[i]);
      seg.add(i, N, -how_much * 2);
      ans += how_much * (FLY - WALK);
    }
  }

  for(int i = N; i > 0; i--) {
    if(S[i] == WATER) {
      // fly  fly 
      lint how_much = min(seg.query(i, N) / 2, L[i]);
      seg.add(i, N, -how_much * 2);
      ans += how_much * (FLY - SWIM);
    }
  }

  printf("%lld\n", ans / 2);
  return 0;
}