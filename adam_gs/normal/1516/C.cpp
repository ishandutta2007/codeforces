#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
#define all(a) a.begin(), a.end()
ll pow(ll a,ll b,ll c){ll w=1;while(b){if(b&1)w=(w*a)%c;b/=2;a=(a*a)%c;}return w;}
const int LIM=2e5+7;
int dp[LIM];
void solve() {
	int n;
	cin >> n;
	int T[n], sum=0;
	dp[0]=1;
	rep(i, n) {
		cin >> T[i];
		sum+=T[i];
		for(int j=LIM-T[i]-1; j>=0; --j) dp[j+T[i]]=max(dp[j+T[i]], dp[j]);
	}
	if(sum%2==1 || dp[sum/2]==0) {
		cout << 0;
		return;
	}
	int p=1;
	while(true) {
		int np=-1;
		rep(i, n) if(T[i]%2==1) np=i;
		if(np!=-1) {
			cout << "1\n" << np+1 << '\n';
			return;
		}
		rep(i, n) T[i]/=2;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	while(t--) solve();
}