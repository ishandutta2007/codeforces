///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 100'010;
int n, m;

int cnt1[N], cnt2[N];
bitset<N> a, b, c;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	Loop(i,0,n) {int x; cin >> x; cnt1[x]++; a[x]=1;}
	Loop(i,0,n) {int x; cin >> x; cnt2[x]++; b[m-1-x]=1;}
	LoopR(x,0,m) {
		for(;;){
			c = a&b;
			int i = c._Find_first();
			if(i==N) break;
			cout << x << ' ';
			a[i] = a[i]&&--cnt1[i];
			b[i] = b[i]&&--cnt2[(x+m-i)%m];
		}
		bool tmp = b[0];
		b >>= 1;
		b[m-1] = tmp;
	}
	cout << '\n';
}