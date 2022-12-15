#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=70;

ll n, m, k, u, v, x, y, t, sum, ans;
ll cnt[LOG];

int solve(){
	memset(cnt, 0, sizeof(cnt));
	sum=ans=0;
	cin>>n>>m;
	while (m--) cin>>x, cnt[__builtin_ctz(x)]++, sum+=x;
	if (sum<n) kill(-1)
	while (n){
		if (n&1){
			if (!cnt[0]){
				int shit=-1;
				for (int i=1; i<LOG; i++) if (cnt[i]){
					shit=i;
					break ;
				}
				if (shit==-1) kill(-1)
				cnt[shit]--;
				for (int i=1; i<shit; i++) cnt[i]++;
				cnt[0]+=2;
				ans+=shit;
			}
			cnt[0]--;
		}
		cnt[1]+=cnt[0]>>1;
		for (int i=0; i<LOG-1; i++) cnt[i]=cnt[i+1];
		n>>=1;
	}
	kill(ans)
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) solve();
	
	return 0;
}
/*
1
5 1 1

*/