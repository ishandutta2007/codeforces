#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
vector<int>V[26];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
	string s;
	cin >> n >> k >> s;
	rep(i, n) {
		V[s[i]-'a'].pb(i);
	}
	rep(i, 26) {
		rep(j, V[i].size()) {
			if(k) {
				s[V[i][j]]='.';
				--k;
			}
		}
	}
	for(auto i : s) if(i!='.') cout << i;
	cout << '\n';
}