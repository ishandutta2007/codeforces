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
	string s;
	cin >> n >> s;
	for(int i=1; i<=n; ++i) if(n%i==0) {
		reverse(s.begin(), s.begin()+i);
	}
	cout << s << '\n';
}