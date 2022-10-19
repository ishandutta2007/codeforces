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

const int N = 100'010;
const int S = 300;

ll sum[N], add[N/S], sm2[N/S];
ll a[N];
int bcnt = 0;
int insct[N][N/S];
int id[N];
int n, m, q;
vector<int> s[N];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> q;
	Loop(i,0,n) cin >> a[i];
	Loop(i,0,m)
	{
		int k;
		cin >> k;
		id[i] = k > S? bcnt++: -1;
		while(k--)
		{
			int x;
			cin >> x; --x;
			sum[i] += a[x];
			s[i].push_back(x);
		}
	}

	bitset<N> bs;
	Loop(i,0,m)
	{
		if(id[i] == -1) continue;
		for(int x : s[i]) bs[x] = 1;
		Loop(j,0,m)
			for(int x : s[j])
				if(bs[x])
					insct[j][id[i]]++;
		for(int x : s[i]) bs[x] = 0;
	}

	while(q--)
	{
		char c; int i;
		cin >> c >> i; --i;
		if(c == '+')
		{
			ll x; cin >> x;
			if(id[i] == -1){
				for(int j : s[i])
					a[j] += x;
				Loop(j,0,bcnt)
					sm2[j] += insct[i][j]*x;
			} else {
				add[id[i]] += x;
			}
		}
		if(c == '?')
		{
			if(id[i] == -1){
				ll ans = 0;
				for(int j : s[i]) ans += a[j];
				Loop(j,0,bcnt) ans += insct[i][j]*add[j];
				cout << ans << '\n';
			} else {
				ll ans = sum[i]+sm2[id[i]];
				Loop(j,0,bcnt) ans += insct[i][j]*add[j];
				cout << ans << '\n';
			}
		}
	}
}