///
///   Oh? You're approaching me?
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 5000;
const int K = 15;
int k, n[K];
ll sum[K];
ll ssum;
ll a[K*N];
int nxt[K*N], val[K*N];
map<ll, int> mp;
int dp[1<<K];
pii ans[K];

#define at(a, i, j) (a)[(i)*N + (j)]

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> k;
	Loop (i,0,k) {
		cin >> n[i];
		Loop (j,0,n[i]) {
			cin >> at(a,i,j);
			mp[at(a,i,j)] = i*N+j;
			sum[i] += at(a,i,j);
			ssum += at(a,i,j);
		}
	}
	if (ssum % k)
		Kill("No");
	ssum /= k;
	memset(nxt, -1, sizeof(nxt));
	Loop (i,0,k) {
		Loop (j,0,n[i]) {
			ll need = ssum-sum[i]+at(a,i,j);
			if (mp.count(need))
				at(nxt,i,j) = mp[need];
		}
	}
	Loop (i,0,k) {
		Loop (j,0,n[i]) {
			int p = i*N+j;
			int vis = (1<<(p/N));
			while(1) {
				p = nxt[p];
				if (p == -1 || (vis&(1<<(p/N))))
					break;
				vis |= (1<<(p/N));
			};
			at(val,i,j) = p == i*N+j? vis: 0;
		}
	}
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	Loop (msk,1,1<<k) {
		int i = __builtin_ctz(msk);
		Loop (j,0,n[i]) {
			int x = at(val,i,j);
			if (x && (x|msk) == msk && dp[x^msk] != -1) {
				dp[msk] = i*N+j;
				break;
			}
		}
	}
//	Loop (i,0,1<<k)
//		cout << i << ' ' << dp[i]/N << ' ' << dp[i]%N << '\n';
//	cout << nxt[N*3] << '\n';
//	cout << val[N*3] << '\n';
	int msk = (1<<k)-1;
	if (dp[msk] == -1)
		Kill("No");
	cout << "Yes\n";
	while (msk) {
		int i = dp[msk];
		msk ^= val[i];
		int j = i;
		do {
			ans[nxt[j]/N] = {a[nxt[j]], j/N+1};
			j = nxt[j];
		} while (j != i);
	}
	Loop (i,0,k)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
}