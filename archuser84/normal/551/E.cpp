///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
typedef unsigned int dw;
typedef dw ymm __attribute((vector_size(32),aligned(32)));
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))

const int N = 500000;
dw v[N];

pii q2(dw y){
	ymm mn, mx, kooft;
	Loop(i,0,8) mn[i] = ~N, mx[i] = -1, kooft[i] = i;
	for(int i = 0; i < N; i += 8){
		ymm x = *(ymm*)(v+i);
		x = (x == y);
		mx = x? kooft: mx;
		mn = max(mn, x&~kooft);
		kooft += 8;
	}
	int  a1 = N, a2 = -1;
	Loop(i,0,8) a1 = min(a1, (int)~mn[i]), a2 = max(a2, (int)mx[i]);
	return {a1, a2};
}

void q1(int l, int r, dw x){
	Loop(i,l,r) v[i] = min(v[i]+x, 1<<30);
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	Loop(i,0,n) cin >> v[i];
	while(q--){
		int t;
		cin >> t;
		if(t == 1){int l, r, x; cin >> l >> r >> x; q1(l-1,r,x);}
		if(t == 2){
			int y; cin >> y;
			auto [l, r] = q2(y);
			cout << (r==-1?-1:r-l) << '\n';
		}
	}
}