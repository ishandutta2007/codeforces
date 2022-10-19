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
typedef std::pair<ll,ll> pll;
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx")
typedef double ymm  __attribute((vector_size(32),aligned(32)));
#define smax(a,b) ((a)=(a)>(b)?(a):(b))

const int N = 100'000;
const int S = 512;
double a[N], b[N];
int n, q;
double ans[N]={};
int ansi[N];
tuple<int,int,int> Q[N]={};

double solve(int l, int r, double t){
	double ans = 0;
	Loop(i,l,r) smax(ans,a[i]*t+b[i]);
	return ans;
}

int find_index(int s, int l, int r, double x, double t){
	for(int i = s; i < s+S; ++i)
		if(l <= i && i < r && a[i]*t+b[i] == x)
			return i;
	return -1;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> q;
	Loop(i,0,n){
		int _a, _b;
		cin >> _b >> _a;
		a[i] = _a;
		b[i] = _b;
	}
	Loop(i,0,q) {
		int l, r, t;
		cin >> l >> r >> t; --l;
		Q[i]={l,r,t};
	}
	for(int z = 0; z < N; z += S){
		Loop(i,0,q) {
			auto [l, r, t] = Q[i];
			double x = solve(max(l,z),min(r,z+S),t);
			if(x>=ans[i]){
				ans[i]=x;
				ansi[i]=z;
			}
		}
	}
	Loop(i,0,q) {
		auto [l, r, t] = Q[i];
		cout << find_index(ansi[i],l,r,ans[i],t)+1 << '\n';
	}
}