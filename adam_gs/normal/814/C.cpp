#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1507;
int ans[LIM][26];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	rep(i, n) rep(j, 26) {
		int l=i, akt=0;
		rep(k, n+1) {
			while(l<n && (s[l]-'a'==j || akt<k)) {
				if(s[l]-'a'!=j) ++akt;
				++l;
			}
			ans[k][j]=max(ans[k][j], l-i);
		}
	}
	int q;
	cin >> q;
	while(q--) {
		int a;
		char b;
		cin >> a >> b;
		cout << ans[a][b-'a'] << '\n';
	}
}