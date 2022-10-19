#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
char T[62];
int ile[62];
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	rep(i, k) ile[i]=0;
	string S[n], ans[n];
	int sum=0;
	rep(i, n) {
		cin >> S[i];
		ans[i]=S[i];
		rep(j, m) if(S[i][j]=='R') ++sum;
	}
	int l=0;
	while(sum) {
		++ile[l]; --sum; ++l;
		l%=k;
	}
	l=0;
	rep(i, n) {
		if(i%2==0) {
			rep(j, m) {
				if(S[i][j]=='R') {
					if(ile[l]==0) ++l;
					--ile[l];
				}
				ans[i][j]=T[l];
			}
		} else {
			for(int j=m-1; j>=0; --j) {
				if(S[i][j]=='R') {
					if(ile[l]==0) ++l;
					--ile[l];
				}
				ans[i][j]=T[l];
			}
		}
	}
	rep(i, n) cout << ans[i] << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	rep(i, 26) {
		T[i]='a'+i;
		T[26+i]='A'+i;
	}
	rep(i, 10) T[52+i]='0'+i;
	int _;
	cin >> _;
	while(_--) solve();
}