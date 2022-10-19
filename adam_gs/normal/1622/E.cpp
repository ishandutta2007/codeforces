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
void solve() {
	int n, m;
	cin >> n >> m;
	int T[n], ans=-1, P[m];
	string S[n];
	rep(i, n) cin >> T[i];
	rep(i, n) cin >> S[i];
	rep(i, 1<<n) {
		pair<int,int>ile[m];
		rep(j, m) ile[j]={0, j};
		rep(j, m) rep(l, n) {
			int x=S[l][j]-'0';
			if(i&(1<<l)) x^=1;
			if(x) ++ile[j].st;
		}
		sort(ile, ile+m);
		int wynik[n], jaki[m];
		rep(j, n) wynik[j]=0;
		rep(j, m) jaki[ile[j].nd]=j+1;
		rep(j, m) rep(l, n) {
			int x=S[l][j]-'0';
			if(i&(1<<l)) x^=1;
			if(x) wynik[l]+=jaki[j];
		}
		int sum=0;
		rep(j, n) {
			if(i&(1<<j)) wynik[j]=m*(m+1)/2-wynik[j];
			sum+=abs(T[j]-wynik[j]);
		}
		if(sum>ans) {
			ans=sum;
			rep(j, m) P[j]=jaki[j];
		}
	}
	rep(j, m) cout << P[j] << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}