#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int sum=0;
	rep(i, n) {
		int a;
		cin >> a;
		sum+=a^1;
	}
	if(n==1) cout << (sum==0?"YES":"NO") << '\n';
	else cout << (sum==1?"YES":"NO") << '\n';
}