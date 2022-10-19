#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=3e5+7;
vector<ll>V[3];
ll dp[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<ll,int>>T;
	rep(i, n) {
		ll w, c;
		cin >> w >> c;
		V[w-1].pb(c);
	}
	rep(i, 3) {
		sort(all(V[i]));
		reverse(all(V[i]));
	}
	ll akt=0, l=0, l2=0;
	vector<ll>P;
	rep(j, m) {
		while(l<=j && P.size()<V[0].size()) {
			akt+=V[0][P.size()];
			P.pb(V[0][P.size()]);
			++l;
		}
		while(P.size()>=2 && l2<V[1].size()) {
			if(l+2<=j+1) {
				akt+=V[1][l2];
				++l2; l+=2;
				continue;
			}
			if(l<=j) {
				if(P.back()>V[1][l2]) break;
				akt-=P.back();
				P.pop_back();
				akt+=V[1][l2];
				++l2; ++l;
				continue;
			}
			if(P.back()+P[P.size()-2]>V[1][l2]) break;
			akt-=P.back();
			P.pop_back();
			akt-=P.back();
			P.pop_back();
			akt+=V[1][l2];
			++l2;
			while(l<=j && P.size()<V[0].size()) {
				akt+=V[0][P.size()];
				P.pb(V[0][P.size()]);
				++l;
			}
		}
		if(P.size()==1 && l2<V[1].size() && P[0]<=V[1][l2] && l<=j) {
			akt-=P.back();
			P.pop_back();
			akt+=V[1][l2];
			++l2; ++l;
		}
		while(l+2<=j+1 && l2<V[1].size()) {
			akt+=V[1][l2];
			++l2; l+=2;
		}
		while(l<=j && P.size()<V[0].size()) {
			akt+=V[0][P.size()];
			P.pb(V[0][P.size()]);
			++l;
		}
		dp[j+1]=akt;
	}
	rep(j, m) dp[j+1]=max(dp[j+1], dp[j]);
	ll ans=dp[m], sum=0;
	rep(i, V[2].size()) {
		if(m-3*(i+1)<0) break;
		sum+=V[2][i];
		ans=max(ans, dp[m-3*(i+1)]+sum);
	}
	cout << ans << '\n';
}