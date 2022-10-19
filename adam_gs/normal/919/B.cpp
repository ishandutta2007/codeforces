#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int akt=0, ile=0;
	int k;
	cin >> k;
	while(ile<k) {
		++akt;
		int x=akt, sum=0;
		while(x) {
			sum+=x%10;
			x/=10;
		}
		if(sum==10) ++ile;
	}
	cout << akt << '\n';
}