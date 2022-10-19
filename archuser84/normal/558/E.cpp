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

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

const int N = 100'010;
char a[N];
int cnt[26];
int Cnt[26];
int n, q;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> q;
	cin >> a; Loop(i,0,n) a[i] -= 'a', Cnt[a[i]]++;
	while(q--){
		int l, r, k;
		cin >> l >> r >> k; --l;
		if(r-l <= n/2) Loop(i,l,r) cnt[a[i]]++;
		else{
			Loop(i,0,l) cnt[a[i]]++;
			Loop(i,r,n) cnt[a[i]]++;
			Loop(z,0,26) cnt[z] = Cnt[z]-cnt[z];
		}
		if(k==0){
			int b = l, e = l;
			LoopR(i,0,26){
				e += cnt[i]; cnt[i] = 0;
				Loop(j,b,e) a[j] = i;
				b = e;
			}
		} else {
			int b = l, e = l;
			Loop(i,0,26){
				e += cnt[i]; cnt[i] = 0;
				Loop(j,b,e) a[j] = i;
				b = e;
			}
		}
	}
	Loop(i,0,n) a[i]+='a';
	cout << a << '\n';
}