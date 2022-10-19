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

const int N = 2010;
bool A[N][N];
int deg[N];
int n;
int fans=N, fansc;

void up(int x){
	if(x < fans) {fans = x; fansc=0;}
	if(x == fans) fansc++;
}

void rev(int v){
	Loop(u,0,n){
		deg[v] -= A[v][u];
		A[v][u] = !A[v][u];
		deg[v] += A[v][u];
		deg[u] -= A[u][v];
		A[u][v] = !A[u][v];
		deg[u] += A[u][v];
	}
}

void revmask(int msk)
{
	for(int i = 0; msk; msk >>= 1, ++i)
		if(msk&1) rev(i);
}

bool check(){
	static int cnt[N];
	Loop(i,0,n) cnt[i] = 0;
	Loop(i,0,n) cnt[deg[i]]++;
	int Cnt = 0, Sum = 0;
	LoopR(i,0,n){
		Cnt += cnt[i];
		Sum += cnt[i]*i;
		if(0 < Cnt && Cnt < n && Sum == Cnt*(Cnt-1)/2 + Cnt*(n-Cnt))
			return 0;
	}
	return 1;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n) Loop(j,0,n){
		char c;
		cin >> c;
		A[i][j] = c-'0';
		deg[i] += A[i][j];
	}
	if(n > 6){
		Loop(i,0,n) {
			rev(i);
			if(check()) up(1);
			rev(i);
		}
		if(check()) up(0);
	} else {
		Loop(mask,0,1<<n){
			revmask(mask);
			if(check()) up(__builtin_popcount(mask));
			revmask(mask);
		}
	}
	if(fans == N) Kill(-1);
	Loop(i,0,fans) fansc *= i+1;
	cout << fans << ' ' << fansc << '\n';
}