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
ll T[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	ll sum=0;
	rep(i, n) {
		cin >> T[i];
		sum+=T[i];
	}
	sort(T, T+n);
	ll x=0;
	rep(i, n/2) x+=T[i];
	cout << x*x+(sum-x)*(sum-x) << '\n';
}