///
///   You fell for it, fool!
///   Thunder Cross Split Attack!
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;

const int N = 200'010;
char s[N], t[N];
int n, m;
bool ans[N];

int lst[26];
ll hsh[26];
ll hsht[26];
int mp[26];

template<ll bs, int mod>
void solve()
{
	ll bsm = 1; Loop(_,1,m) bsm = bs*bsm % mod;
	Loop(_,0,26) lst[_] = N, hsh[_] = 0, hsht[_] = 0;
	LoopR(i,n-m+1,n) {
		lst[s[i]] = i;
		Loop(z,0,26) hsh[z] = (hsh[z]*bs + (z==s[i])) % mod;
	}
	LoopR(i,0,m) Loop(z,0,26) hsht[z] = (hsht[z]*bs + (z==t[i])) % mod;
	LoopR(i,0,n-m+1) {
		lst[s[i]] = i;
		Loop(z,0,26) hsh[z] = (hsh[z]*bs + (z==s[i])) % mod;

		bool flg = 0;
		Loop(z,0,26) mp[z] = 26;
		Loop(z,0,26) {
			if(lst[z]-i >= m) continue;
			if(mp[z] != t[lst[z]-i] && mp[z] != 26) flg = 1;
			if(mp[t[lst[z]-i]] != z && mp[t[lst[z]-i]] != 26) flg = 1;
			mp[z] = t[lst[z]-i];
			mp[t[lst[z]-i]] = z;
		}
		Loop(z,0,26){
			if(mp[z] != 26 && hsh[z] != hsht[mp[z]])
				flg = 1;
		}
		if(flg) ans[i] = 0;

		hsh[s[i+m-1]] = (hsh[s[i+m-1]]+mod-bsm) % mod;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	cin >> s >> t;
	Loop(i,0,n) s[i]-='a';
	Loop(i,0,m) t[i]-='a';
	memset(ans,1,n-m+1);
	solve<29,1000000009>();
	solve<31,7*17*(2<<23)+1>();
	cout << count(ans,ans+N,1) << '\n';
	Loop(i,0,N) if(ans[i]) cout << i+1 << ' ';
	cout << '\n';
}