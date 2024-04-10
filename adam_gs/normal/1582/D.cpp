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
	int n;
	cin >> n;
	int T[n], b[n];
	int sum=0;
	rep(i, n) {
		cin >> T[i];
		if(i==n-1) continue;
		if(abs(sum+T[i])<=abs(sum-T[i])) {
			b[i]=1;
			sum+=T[i];
		} else {
			b[i]=-1;
			sum-=T[i];
		}
	}
	if(sum==0) {
		if(b[n-2]==1) sum+=T[n-2];
		else sum-=T[n-2];
		b[n-2]*=2;
	}
	b[n-1]=-sum;
	rep(i, n-1) b[i]*=T[n-1];
	rep(i, n) cout << b[i] << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}