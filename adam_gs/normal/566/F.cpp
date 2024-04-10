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
int ile[LIM], dp[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while(n--) {
		int a;
		cin >> a;
		++ile[a];
	}
	for(int i=LIM-1; i; --i) {
		for(int j=i; j<LIM; j+=i) dp[i]=max(dp[i], dp[j]+ile[i]);
	}
	cout << dp[1] << '\n';
}