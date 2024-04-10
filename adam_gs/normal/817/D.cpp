#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
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
const int LIM=1e6+7;
ll ile[LIM], F[LIM], odw[LIM], mi[LIM], ma[LIM];
pair<ll,ll>T[LIM];
int fnd(int x) {
	if(F[x]==x) return x;
	return F[x]=fnd(F[x]);
}
void uni(int a, int b) {
	ile[fnd(a)]+=ile[fnd(b)];
	mi[fnd(a)]=min(mi[fnd(a)], mi[fnd(b)]);
	ma[fnd(a)]=max(ma[fnd(a)], ma[fnd(b)]);
	F[fnd(b)]=fnd(a);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i, n) {
		cin >> T[i].st;
		ile[i]=1;
		F[i]=mi[i]=ma[i]=i;
		T[i].nd=i;
	}
	sort(T, T+n);
	ll ans=0;
	rep(i, n) {
		odw[T[i].nd]=1;
		if(T[i].nd && odw[T[i].nd-1]) uni(T[i].nd-1, T[i].nd);
		if(T[i].nd<n-1 && odw[T[i].nd+1]) uni(T[i].nd, T[i].nd+1);
		ans+=(T[i].nd-mi[fnd(T[i].nd)]+1)*(ma[fnd(T[i].nd)]-T[i].nd+1)*T[i].st;
	}
	reverse(T, T+n);
	rep(i, n) {
		ile[i]=1;
		F[i]=mi[i]=ma[i]=i;
		odw[i]=0;
	}
	rep(i, n) {
		odw[T[i].nd]=1;
		if(T[i].nd && odw[T[i].nd-1]) uni(T[i].nd-1, T[i].nd);
		if(T[i].nd<n-1 && odw[T[i].nd+1]) uni(T[i].nd, T[i].nd+1);
		ans-=(T[i].nd-mi[fnd(T[i].nd)]+1)*(ma[fnd(T[i].nd)]-T[i].nd+1)*T[i].st;
	}
	cout << ans << '\n';
}