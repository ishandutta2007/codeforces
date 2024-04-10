#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int MAXA=8192, INF=1e9+7;
pair<int,int>dp[MAXA], tmp[MAXA], T[MAXA];
vector<int>V[MAXA];
int bylo[MAXA];
void solve() {
	int n;
	cin >> n;
	rep(i, n) {
		int a;
		cin >> a;
		V[a].pb(i);
	}
	rep(i, MAXA-1) dp[i+1]={i+1, INF};
	rep(i, MAXA) {
		V[i].pb(INF);
		int l=0;
		rep(j, MAXA) {
			while(V[i][l]<dp[j].nd) ++l;
			T[j]={dp[j].st^i, V[i][l]};
		}
		int l1=0, l2=0; l=0;
		while(l1<MAXA || l2<MAXA) {
			if(l2==MAXA || l1<MAXA && dp[l1].nd<T[l2].nd) {
				++l1;
				if(bylo[dp[l1-1].st]>i) continue;
				bylo[dp[l1-1].st]=i+1;
				tmp[l]=dp[l1-1];
				++l;
			} else {
				++l2;
				if(bylo[T[l2-1].st]>i) continue;
				bylo[T[l2-1].st]=i+1;
				tmp[l]=T[l2-1];
				++l;
			}
		}
		rep(j, MAXA) dp[j]=tmp[j];
	}
	vector<int>ans;
	rep(i, MAXA) if(dp[i].nd<INF) ans.pb(dp[i].st);
	sort(all(ans));
	cout << ans.size() << '\n';
	for(auto i : ans) cout << i << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}