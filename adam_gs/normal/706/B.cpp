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
const int LIM=1e5+7;
int T[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i, n) cin >> T[i+1];
	sort(T, T+n+1);
	int q;
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		int p=0, k=n;
		while(p<k) {
			int sr=(p+k+1)/2;
			if(T[sr]<=x) p=sr; else k=sr-1;
		}
		cout << p << '\n';
	}
}