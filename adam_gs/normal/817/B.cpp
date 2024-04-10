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
const int INF=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	ll mi=INF, ile=0, mi2=INF, ile2=0, mi3=INF, ile3=0;
	rep(i, n) {
		int a;
		cin >> a;
		if(a<mi) {
			mi3=mi2;
			ile3=ile2;
			mi2=mi;
			ile2=ile;
			mi=a;
			ile=0;
		} else if(a<mi2 && a!=mi) {
			mi3=mi2;
			ile3=ile2;
			mi2=a;
			ile2=0;
		} else if(a<mi3 && a!=mi2 && a!=mi) {
			mi3=a;
			ile3=0;
		}
		if(a==mi) ++ile;
		if(a==mi2) ++ile2;
		if(a==mi3) ++ile3;
	}
	if(ile==1 && ile2==1) {
		cout << ile3 << '\n';
	} else if(ile==1) {
		cout << ile2*(ile2-1)/2 << '\n';
	} else if(ile==2) {
		cout << ile2 << '\n';
	} else {
		cout << ile*(ile-1)*(ile-2)/6 << '\n';
	}
}