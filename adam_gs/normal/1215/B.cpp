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
const int LIM=2e5+7;
ll T[LIM], ile[2];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin >> n;
	rep(i, n) {
		int a;
		cin >> a;
		if(a<0) ++T[i];
	}
	ll sum=0;
	ile[0]=1;
	rep(i, n) {
		sum^=T[i];
		++ile[sum];
	}
	cout << ile[0]*ile[1] << " " << n*(n+1)/2-ile[0]*ile[1] << '\n';
}